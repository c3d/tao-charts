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
    ChartData(double d) : value(d) {}

    double value;
    std::map<text, double> properties;
};

struct ChartDataSet {
    ChartDataSet(uint i = 0) : index(i) {}

    int dataCount() { return data.size(); }
    double dataValue(uint i) { return data[i]->value; }
    bool   dataHasProperty(uint i, text p) { return (data[i]->properties.find(p) != data[i]->properties.end()); }
    double dataProperty(uint i, text p) { return data[i]->properties[p]; }

    uint index;
    vector<ChartData*> data;
};

struct Chart : public QObject
{
    Chart(text name);
    ~Chart();

    // Draw chart
    virtual void    Draw();

    void init();

    // Chart
    void setType(text m);
    void setStyle(text s);
    void setFormat(text f);
    void setFirst(uint f);
    void setLast(uint l);
    void setDatasetsCount(uint count);

    // Data
    void reset();
    void pushData(uint s, double d);
    double getDataCount(uint s);
    double getData(uint s, uint i);
    double getDataProperty(int s, uint i, text property);
    bool   setDataProperty(int s, uint i, text property, double value);

    // Datasets
    uint   getDataSet(uint index);
    void   pushDataSet(uint s);
    void   resetDataSets();

    double computeSum(uint s, bool abs = false);
    double computeMax(uint s);
    double computeMin(uint s);

    // Legend
    void setLegend(uint N, text entry);
    text getLegend(uint N);

    // Axis
    void setMaxAxis(double max, bool adjust = true);
    void setMinAxis(double min, bool adjust = true);

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
    text type, style, format;
    uint first, last;

    uint64 previousDatasetsMask; // Previous mask of datasets
    uint64 datasetsMask;         // Mask of datasets to draw
    vector<uint> datasetsToDraw; // List of datasets to draw

    // Components
    text title;
    vector<text> legend;

    // Axis
    double step;
    double maxAxis, minAxis;
    uint xticks, yticks;
    text xlabel, ylabel;
    vector<text> xticks_labels, yticks_labels;

    bool needInit;

    // Pointer to Tao functions
    static const Tao::ModuleApi *tao;

private:
    #define MAX_TICKS 10

    bool auto_maxAxis, auto_minAxis;
    bool auto_xticks, auto_yticks;
    bool auto_xticks_labels, auto_yticks_labels;

    typedef std::map<uint, ChartDataSet> data_map;
    data_map  datasets;
};


#endif
