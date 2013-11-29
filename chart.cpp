// ****************************************************************************
//  filtering.cpp                                                   Tao project
// ****************************************************************************
//
//   File Description:
//
//   Filtering implementation.
//
//
//
//
//
//
//
// ****************************************************************************
// This software is property of Taodyne SAS - Confidential
// Ce logiciel est la propriété de Taodyne SAS - Confidentiel
//  (C) 2011 Baptiste Soulisse <baptiste.soulisse@taodyne.com>
//  (C) 2011 Taodyne SAS
// ****************************************************************************
#include "chart.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

const Tao::ModuleApi *Chart::tao = NULL;

// ============================================================================
//
//    Filter
//
// ============================================================================

Chart::Chart(text n) : name(n)
// ----------------------------------------------------------------------------
//   Construction
// ----------------------------------------------------------------------------
{
    reset();
}


Chart::~Chart()
// ----------------------------------------------------------------------------
//   Destruction
// ----------------------------------------------------------------------------
{
}

void Chart::reset()
// ----------------------------------------------------------------------------
//   Reset chart
// ----------------------------------------------------------------------------
{
    // Chart settings
    master = style = format = "";
    first  = last = 0;

    // Title
    title = "";

    // Legend
    legend.clear();

    // Axis labels
    xlabel = ylabel = "";

    // Axis setttings
    maxAxis = minAxis = 0;
    auto_maxAxis = true;

    // Ticks
    xticks = yticks = 1;
    auto_xticks  = auto_yticks = true;

    // Ticks labels
    xticks_labels.clear();
    yticks_labels.clear();
    auto_xticks_labels = auto_yticks_labels = true;

    // Data
    datasets.clear();
    data_count = 0;

    needInit = true;
}


void Chart::init()
// ----------------------------------------------------------------------------
//   Init chart
// ----------------------------------------------------------------------------
{
    // We need to init chart and there is
    // at least one data, so do it.
    if(needInit && data_count > 0)
    {
        autocomputeTicks();
        autocomputeTicksLabels();
        needInit = false;
    }
}


void Chart::Draw()
// ----------------------------------------------------------------------------
//   Draw chart
// ----------------------------------------------------------------------------
{
}


#define SETTER(Name, Variable, Type)  \
void Chart::Name(Type v)              \
{                                     \
    if(Variable != v)                 \
    {                                 \
        Variable = v;                 \
        needInit = true;              \
    }                                 \
}                                     \

SETTER(setMaster, master, text);
SETTER(setStyle, style, text);
SETTER(setFormat, format, text);
SETTER(setFirst, first, uint);
SETTER(setLast, last, uint);


// ============================================================================
//
//   Data
//
// ============================================================================

void Chart::pushData(uint set, double data)
// ----------------------------------------------------------------------------
//   Add data to chart
// ----------------------------------------------------------------------------
{
    ChartData* d = new ChartData(data);

    uint count = datasets[set].size();

    // Update maximum data count if needed
    if(count >= data_count)
        data_count = count + 1;

    // Push data
    datasets[set].push_back(d);

    // As we have change data, need init
    needInit = true;
}


double Chart::getDataCount(uint s)
// ----------------------------------------------------------------------------
//   Return size of a dataset
// ----------------------------------------------------------------------------
{
    if(datasets.size() > 0)
        return datasets[s].size();
    else
        return 0;
}


double Chart::getData(uint s, uint i)
// ----------------------------------------------------------------------------
//   Return data of chart
// ----------------------------------------------------------------------------
{
    if(datasets.size() > 0 && datasets[s].size() > 0)
        return datasets[s][i]->data;
    else
        return 0;
}


double Chart::getDataProperty(int s, uint i, text property)
// ----------------------------------------------------------------------------
//   Return value of a data property
// ----------------------------------------------------------------------------
{
    if(datasets.size() > 0 && datasets[s].size() > 0)
        if(datasets[s][i]->properties.find(property) != datasets[s][i]->properties.end())
            return datasets[s][i]->properties[property];

    return 0;
}


bool Chart::setDataProperty(int s, uint i, text property, double value)
// ----------------------------------------------------------------------------
//   Set value of a data property
// ----------------------------------------------------------------------------
{
    if(datasets.size() > 0 && datasets[s].size() > 0)
    {
        datasets[s][i]->properties[property] = value;
        return true;
    }

    return false;
}


double Chart::computeSum(uint s)
// ----------------------------------------------------------------------------
//   Compute sum of all data in a set
// ----------------------------------------------------------------------------
{
    double sum = 0;
    if(datasets.size() > 0)
    {
        uint size = datasets[s].size();
        for(uint i = 0; i < size; i++)
            sum += datasets[s][i]->data;
    }

    return sum;
}


double Chart::computeMax(uint s)
// ----------------------------------------------------------------------------
//   Get maximum value in a set
// ----------------------------------------------------------------------------
{
    double max = 0;
    if(datasets.size() > 0)
    {
        uint size = datasets[s].size();
        for(uint i = 0; i < size; i++)
        {
            double value = datasets[s][i]->data;
            if(max < value)
                max = value;
        }
    }

    return max;
}


// ============================================================================
//
//   Legend
//
// ============================================================================

void Chart::setLegend(uint N, text entry)
// ----------------------------------------------------------------------------
//   Add an entry to legend
// ----------------------------------------------------------------------------
{
    // Resize array if needed
    if(legend.size() <= N)
        legend.resize(N + 1);

    // Add legend
    legend[N] = entry;
}


text Chart::getLegend(uint N)
// ----------------------------------------------------------------------------
//   Return an entry of legend
// ----------------------------------------------------------------------------
{
    if(N < legend.size())
        return legend[N];
    else
        return "";
}


// ============================================================================
//
//   Axis
//
// ============================================================================

void Chart::setMaxAxis(double max, bool adjust)
// ----------------------------------------------------------------------------
//   Change maximum value of y-axis
// ----------------------------------------------------------------------------
{
    maxAxis = max;         // Change maximum of axis
    auto_maxAxis = adjust; // Auto-adjust maximum if needed
}


// ============================================================================
//
//   Ticks
//
// ============================================================================

void Chart::setXTicks(uint ticks)
// ----------------------------------------------------------------------------
//   Set ticks number of x-axis
// ----------------------------------------------------------------------------
{
    auto_xticks = false; // Disable autocomputation of ticks
    if(xticks != ticks)
    {
        xticks = ticks;  // Change ticks number
        needInit = true; // Force init to recompute axis
    }
}


void Chart::setYTicks(uint ticks)
// ----------------------------------------------------------------------------
//   Set ticks number of y-axis
// ----------------------------------------------------------------------------
{
    auto_yticks = false; // Disable autocomputation of ticks
    if(yticks != ticks)
    {
        yticks = ticks;  // Change ticks number
        needInit = true; // Force init to recompute axis
    }
}


void Chart::autocomputeTicks()
// ----------------------------------------------------------------------------
//   Autocompute ticks for axis
// ----------------------------------------------------------------------------
{
    // Compute step of y-axis
    double range = computeFraction(maxAxis - minAxis, false);
    step = computeFraction(range/MAX_TICKS, true);

    // Auto adjust maximum of y-axis if needed
    if(auto_maxAxis)
        maxAxis = ceil(maxAxis / step) * step;

    // Autocompute ticks number of y-axis if needed
    if(auto_yticks)
        yticks = maxAxis / step;

    // Autocompute ticks number of x-axis if needed
    if(auto_xticks)
        xticks = data_count - 1;
}


// ============================================================================
//
//   Ticks Labels
//
// ============================================================================

void Chart::setXTicksLabel(uint N, text label)
// ----------------------------------------------------------------------------
//   Set ticks label of x-axis
// ----------------------------------------------------------------------------
{
    xticks_labels.resize(N + 1);
    if(xticks_labels[N] != label)
    {
        xticks_labels[N] = label;   // Set ticks label
        auto_xticks_labels = false; // Disable autocomputation of ticks labels
    }
}


void Chart::setYTicksLabel(uint N, text label)
// ----------------------------------------------------------------------------
//   Set ticks label of y-axis
// ----------------------------------------------------------------------------
{
    yticks_labels.resize(N + 1);
    if(yticks_labels[N] != label)
    {
        yticks_labels[N] = label;   // Set ticks label
        auto_yticks_labels = false; // Disable autocomputation of ticks labels
    }
}


text Chart::getXTicksLabel(uint N)
// ----------------------------------------------------------------------------
//   Return ticks label of x-axis
// ----------------------------------------------------------------------------
{
    if(N < xticks_labels.size())
        return xticks_labels[N];
    else
        return "";
}


text Chart::getYTicksLabel(uint N)
// ----------------------------------------------------------------------------
//   Return ticks label of y-axis
// ----------------------------------------------------------------------------
{
    if(N < yticks_labels.size())
        return yticks_labels[N];
    else
        return "";
}


void Chart::autocomputeTicksLabels()
// ----------------------------------------------------------------------------
//   Autocompute ticks labels for axis
// ----------------------------------------------------------------------------
{
    if(auto_xticks_labels && xticks)
    {
        xticks_labels.clear();
        // Compute ticks labels of x-axis
        for(uint i = 0; i <= xticks; i++)
        {
            // Push tick label
            stringstream out;
            out << (i + 1);
            xticks_labels.push_back(out.str());
        }
    }

    if(auto_yticks_labels && yticks)
    {
        yticks_labels.clear();
        // Compute ticks labels of y-axis
        for(uint i = 0; i <= yticks; i++)
        {
            // Compute label for current tick
            double label = ((double) maxAxis / yticks) * i;

            // Push it
            stringstream out;
            out << label;
            yticks_labels.push_back(out.str());
        }
    }
}


float Chart::computeFraction(float range, bool round)
// ----------------------------------------------------------------------------
//   A short function to compute nice fractions for a chart
//   see http://stackoverflow.com/questions/8506881/nice-label-algorithm-for-charts-with-minimum-ticks/16363437#16363437
// ----------------------------------------------------------------------------
{
    int exponent = 0;
    float fraction = 0.0;

    if(range > 0.0)
        exponent = floor (log10 (range));
    else
        exponent = 1;
    fraction = range / pow(10.0, exponent);

    // Compute nice, rounded fraction
    if (round)
    {
        if (fraction < 1.5)
            fraction = 1;
        else if (fraction < 3)
            fraction = 2;
        else if (fraction < 7)
            fraction = 5;
        else
            fraction = 10;
    }
    else
    {
        if (fraction <= 1)
            fraction = 1;
        else if (fraction <= 2)
            fraction = 2;
        else if (fraction <= 5)
            fraction = 5;
        else
            fraction = 10;
    }

    return fraction * (10 ^ exponent);
}


std::ostream & Chart::debug()
// ----------------------------------------------------------------------------
//   Convenience method to log with a common prefix
// ----------------------------------------------------------------------------
{
    std::cerr << "[Charts] " << (void*)this << " ";
    return std::cerr;
}
