﻿// ****************************************************************************
//  charts.cpp                                                     Tao project
// ****************************************************************************
//
//   File Description:
//
//     Implementation of the XL primitives for the "charts" module.
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

#include "charts.h"
#include <iostream>
#include "coords3d.h"

XL_DEFINE_TRACES

// Current chart
Chart* current;

// Factory
ChartFactory * ChartFactory::factory = NULL;


ChartFactory::ChartFactory()
// ----------------------------------------------------------------------------
//   Constructor
// ----------------------------------------------------------------------------
{
}


ChartFactory * ChartFactory::instance()
// ----------------------------------------------------------------------------
//   Return factory instance (singleton)
// ----------------------------------------------------------------------------
{
    if (!factory)
        factory = new ChartFactory();
    return factory;
}


void ChartFactory::destroy()
// ----------------------------------------------------------------------------
//   Destroy factory instance
// ----------------------------------------------------------------------------
{
    if (!factory)
        return;
    delete factory;
    factory = NULL;
}


Chart * ChartFactory::chart(text name)
// ----------------------------------------------------------------------------
//   Find chart by name, optionally create new one
// ----------------------------------------------------------------------------
{
    Chart* chart = NULL;
    chart_map::iterator found = charts.find(name);
    if(found != charts.end())
    {
        chart = (*found).second;
    }
    else
    {
        chart = new Chart(name);
        charts[name] = chart;
    }

    return chart;
}


QList<Chart *> ChartFactory::chartsList(text expr)
// ----------------------------------------------------------------------------
//   Return charts that match expr ("<name>" or "re:<regexp>")
// ----------------------------------------------------------------------------
{
    QList<Chart *> ret;
    QString qexpr(expr.c_str());
    if (qexpr.startsWith("re:"))
    {
        QRegExp re(qexpr.mid(3));
        for (chart_map::iterator v = charts.begin(); v != charts.end(); ++v)
        {
            Chart *s = (*v).second;
            if (re.indexIn(s->name.c_str()) != -1)
                ret.append(s);
        }
    }
    else
    {
        if (Chart *s = chart(expr))
            ret.append(s);
    }
    return ret;
}


void ChartFactory::render_callback(void *arg)
// ----------------------------------------------------------------------------
//   Find chart by name and draw it
// ----------------------------------------------------------------------------
{
    text name = text((const char *)arg);
    Chart * chart = ChartFactory::instance()->chart(name);
    if (chart)
        chart->Draw();
}


void ChartFactory::identify_callback(void *arg)
// ----------------------------------------------------------------------------
//   We can't click on chart
// ----------------------------------------------------------------------------
{
    (void) arg;
}


void ChartFactory::delete_callback(void *arg)
// ----------------------------------------------------------------------------
//   Delete chart name
// ----------------------------------------------------------------------------
{
    free(arg);
}


// ============================================================================
//
//   Manage Data
//
// ============================================================================


Tree_p ChartFactory::chart_push_data(text name, uint set, float value)
// ----------------------------------------------------------------------------
//  Add a data in a chart
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->pushData(set, value);
    return xl_true;
}


Tree_p ChartFactory::chart_data(text name, uint set, uint index)
// ----------------------------------------------------------------------------
//  Return a data of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Real(chart->getData(set, index));
}


Tree_p ChartFactory::chart_data_ratio(text name, uint set, uint index)
// ----------------------------------------------------------------------------
//  Return ratio for a data of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    if(chart->maxAxis > 0)
        return new Real(chart->getData(set, index) / chart->maxAxis);
    else
        return new Real(0.0);
}


Tree_p ChartFactory::chart_sum(text name, uint set)
// ----------------------------------------------------------------------------
//  Sum data in a dataset
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Real(chart->computeSum(set));
}


Tree_p ChartFactory::chart_max(text name, uint set)
// ----------------------------------------------------------------------------
//  Max data of a dataset
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Real(chart->computeMax(set));
}


Tree_p ChartFactory::chart_max_count(text name)
// ----------------------------------------------------------------------------
//  Return max data count
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Integer(chart->data_count);
}


Tree_p ChartFactory::chart_count(text name, uint set)
// ----------------------------------------------------------------------------
//  Return size of a dataset
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Integer(chart->getDataCount(set));
}


Tree_p ChartFactory::chart_datasets_count(text name)
// ----------------------------------------------------------------------------
//  Return count of datasets to draw
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    double count = chart->last - chart->first + 1;
    return new Integer(count);
}


// ============================================================================
//
//   Chart mechanism
//
// ============================================================================

Tree_p ChartFactory::chart_reset(text name)
// ----------------------------------------------------------------------------
//  Reset data of a chart
// ----------------------------------------------------------------------------
{
    foreach(Chart* s, instance()->chartsList(name))
        s->reset();

    return xl_true;
}


Name_p ChartFactory::chart_only(text name)
// ----------------------------------------------------------------------------
//   Purge all other charts from memory
// ----------------------------------------------------------------------------
{
    ChartFactory * f = ChartFactory::instance();
    chart_map::iterator n = f->charts.begin();
    for (chart_map::iterator v = f->charts.begin();
         v != f->charts.end();
         v = n)
    {
        if (name != (*v).first)
        {
            Chart *s = (*v).second;
            f->charts.erase(v);
            delete s;
            n = f->charts.begin();
        }
        else
        {
            n = ++v;
        }
    }
    return XL::xl_false;
}


XL::Name_p ChartFactory::chart_drop(text name)
// ----------------------------------------------------------------------------
//   Purge the given chart from memory
// ----------------------------------------------------------------------------
{
    ChartFactory * f = ChartFactory::instance();
    foreach(Chart* chart, instance()->chartsList(name))
    {
        chart_map::iterator found = f->charts.find(chart->name);
        f->charts.erase(found);
        delete chart;
        return XL::xl_true;
    }
    return XL::xl_false;
}


Tree_p ChartFactory::chart_current(text name)
// ----------------------------------------------------------------------------
//  Set chart with given name as current
// ----------------------------------------------------------------------------
{
    current = instance()->chart(name);
    return xl_true;
}


Tree_p ChartFactory::chart_create(Context *context, text name, uint first, uint last, text master, Tree_p prog)
// ----------------------------------------------------------------------------
//  Create a chart
// ----------------------------------------------------------------------------
{
    current = instance()->chart(name);
    current->setFirst(first);
    current->setLast(last);
    current->setMaster(master);

    if(current->needInit)
    {
        context->Evaluate(prog);
        current->init();
    }

    return xl_true;
}


Tree_p ChartFactory::chart_name(text)
// ----------------------------------------------------------------------------
//  Return current chart name
// ----------------------------------------------------------------------------
{
    if(current)
        return new Text(current->name);
    else
        return new Text("");
}


Tree_p ChartFactory::chart_master(text name)
// ----------------------------------------------------------------------------
//  Return master of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->master);
}


Tree_p ChartFactory::chart_style(text name)
// ----------------------------------------------------------------------------
//  Return style of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->style);
}


Tree_p ChartFactory::chart_style(text name, text style)
// ----------------------------------------------------------------------------
//  Change style of chart
// ----------------------------------------------------------------------------
{
   foreach(Chart* chart, instance()->chartsList(name))
       chart->setStyle(style);
   return xl_true;
}


Tree_p ChartFactory::chart_format(text name)
// ----------------------------------------------------------------------------
//  Return format of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->format);
}


Tree_p ChartFactory::chart_format(text name, text format)
// ----------------------------------------------------------------------------
//  Change format of a chart
// ----------------------------------------------------------------------------
{
   foreach(Chart* chart, instance()->chartsList(name))
       chart->setFormat(format);
   return xl_true;
}


Tree_p ChartFactory::chart_first(text name)
// ----------------------------------------------------------------------------
//  Return first dataset of the chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Integer(chart->first);
}


Tree_p ChartFactory::chart_last(text name)
// ----------------------------------------------------------------------------
//  Return last dataset of the chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Integer(chart->last);
}


// ============================================================================
//
//   Title
//
// ============================================================================

Tree_p ChartFactory::chart_title(text name)
// ----------------------------------------------------------------------------
//  Return title of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->title);
}


Tree_p ChartFactory::chart_title(text name, text title)
// ----------------------------------------------------------------------------
//  Set title of a chart
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->title = title;
    return xl_true;
}


// ============================================================================
//
//   Legend
//
// ============================================================================

Tree_p ChartFactory::chart_legend(text name, uint N)
// ----------------------------------------------------------------------------
//  Return a legend of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->getLegend(N));
}


Tree_p ChartFactory::chart_legend(text name, uint N, text entry)
// ----------------------------------------------------------------------------
//  Set a legend of a chart
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->setLegend(N, entry);
    return xl_true;
}


// ============================================================================
//
//   Axis labels
//
// ============================================================================

Tree_p ChartFactory::chart_xlabel(text name)
// ----------------------------------------------------------------------------
//  Return x-label of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->xlabel);
}


Tree_p ChartFactory::chart_xlabel(text name, text label)
// ----------------------------------------------------------------------------
//  Set x-label of a chart
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->xlabel = label;
    return xl_true;
}


Tree_p ChartFactory::chart_ylabel(text name)
// ----------------------------------------------------------------------------
//  Return y-label of a chart
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->ylabel);
}


Tree_p ChartFactory::chart_ylabel(text name, text label)
// ----------------------------------------------------------------------------
//  Set y-label of a chart
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->ylabel = label;
    return xl_true;
}


// ============================================================================
//
//   Axis
//
// ============================================================================


Tree_p ChartFactory::chart_max_axis(text name)
// ----------------------------------------------------------------------------
//  Return maximum value on the axis
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Integer(chart->maxAxis);
}


Tree_p ChartFactory::chart_max_axis(text name, double max, bool adjust)
// ----------------------------------------------------------------------------
//  Set maximum value on the axis
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->setMaxAxis(max, adjust);
    return xl_true;
}


Tree_p ChartFactory::chart_xticks(text name)
// ----------------------------------------------------------------------------
//  Return ticks number for x-axis
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Integer(chart->xticks);
}


Tree_p ChartFactory::chart_xticks(text name, uint ticks)
// ----------------------------------------------------------------------------
//  Set ticks number for x-axis
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->setXTicks(ticks);
    return xl_true;
}


Tree_p ChartFactory::chart_yticks(text name)
// ----------------------------------------------------------------------------
//  Return ticks number for y-axis
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Integer(chart->yticks);
}


Tree_p ChartFactory::chart_yticks(text name, uint ticks)
// ----------------------------------------------------------------------------
//  Set ticks number for y-axis
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->setYTicks(ticks);
    return xl_true;
}


// ============================================================================
//
//   Ticks labels
//
// ============================================================================

Tree_p ChartFactory::chart_xticks_label(text name, uint N)
// ----------------------------------------------------------------------------
//  Return ticks label for x-axis
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->getXTicksLabel(N));
}


Tree_p ChartFactory::chart_yticks_label(text name, uint N)
// ----------------------------------------------------------------------------
//  Return ticks label for y-axis
// ----------------------------------------------------------------------------
{
    Chart* chart = instance()->chart(name);
    return new Text(chart->getYTicksLabel(N));
}


Tree_p ChartFactory::chart_xticks_label(text name, uint N, text label)
// ----------------------------------------------------------------------------
//  Set ticks label for x-axis
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->setXTicksLabel(N, label);
    return xl_true;
}


Tree_p ChartFactory::chart_yticks_label(text name, uint N, text label)
// ----------------------------------------------------------------------------
//  Set ticks label for y-axis
// ----------------------------------------------------------------------------
{
    foreach(Chart* chart, instance()->chartsList(name))
        chart->setYTicksLabel(N, label);
    return xl_true;
}


int module_init(const Tao::ModuleApi *api, const Tao::ModuleInfo *)
// ----------------------------------------------------------------------------
//   Initialize the Tao module
// ----------------------------------------------------------------------------
{
    glewInit();
    XL_INIT_TRACES();

    Chart::tao = api;

    return 0;
}


int module_exit()
// ----------------------------------------------------------------------------
//   Uninitialize the Tao module
// ----------------------------------------------------------------------------
{
    ChartFactory::chart_only("");
    return 0;
}
