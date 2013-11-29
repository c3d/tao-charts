#ifndef CHART_H
#define CHART_H
// ****************************************************************************
//  chart.h                                                     Tao project
// ****************************************************************************
//
//   File Description:
//
//      Define a chart technique.
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

#include "tao/coords3d.h"
#include "tao/module_api.h"
#include "tao/tao_gl.h"
#include "tao/graphic_state.h"
#include <QObject>

using namespace std;
using namespace Tao;


struct ChartData {
    ChartData(double d) : data(d) {}

    double data;
    std::map<text, double> properties;
};


struct Chart : public QObject
{
    Chart(text name);
    ~Chart();

    // Draw chart
    virtual void    Draw();

    void init();

    // Chart
    void setMaster(text m);
    void setStyle(text s);
    void setFormat(text f);
    void setFirst(uint f);
    void setLast(uint l);

    // Data
    void reset();
    void pushData(uint s, double d);
    double getDataCount(uint s);
    double getData(uint s, uint i);
    double getDataProperty(int s, uint i, text property);
    bool   setDataProperty(int s, uint i, text property, double value);

    double computeSum(uint s);
    double computeMax(uint s);

    // Legend
    void setLegend(uint N, text entry);
    text getLegend(uint N);

    // Axis
    void setMaxAxis(double max, bool adjust = true);

    // Ticks
    void setXTicks(uint ticks);
    void setYTicks(uint ticks);

    // Ticks labels
    void setXTicksLabel(uint N, text label);
    void setYTicksLabel(uint N, text label);
    text getXTicksLabel(uint N);
    text getYTicksLabel(uint N);

private:
    void autocomputeTicks();
    void autocomputeTicksLabels();

    float computeFraction(float range, bool round);

    std::ostream &  debug();

public:
    uint data_count;

    // Chart
    text name;
    text master, style, format;
    uint first, last;

    // Components
    text title;
    vector<text> legend;

    // Axis
    double step;
    uint maxAxis, minAxis;
    uint xticks, yticks;
    text xlabel, ylabel;
    vector<text> xticks_labels, yticks_labels;

    bool needInit;

    // Pointer to Tao functions
    static const Tao::ModuleApi *tao;

private:
    #define MAX_TICKS 10

    bool auto_maxAxis;
    bool auto_xticks, auto_yticks;
    bool auto_xticks_labels, auto_yticks_labels;

    typedef std::vector<ChartData*> data;
    typedef std::map<uint, data> data_map;
    data_map  datasets;
};


#endif
