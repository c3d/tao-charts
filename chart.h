#ifndef CHART_H
#define CHART_H
// *****************************************************************************
// chart.h                                                         Tao3D project
// *****************************************************************************
//
// File description:
//
//      Define a chart technique.
//
//
//
//
//
//
// *****************************************************************************
// This software is licensed under the GNU General Public License v3
// (C) 2013, Baptiste Soulisse <baptiste.soulisse@taodyne.com>
// (C) 2013, Catherine Burvelle <catherine@taodyne.com>
// (C) 2013-2014,2019, Christophe de Dinechin <christophe@dinechin.org>
// (C) 2013-2014, Jérôme Forissier <jerome@taodyne.com>
// *****************************************************************************
// This file is part of Tao3D
//
// Tao3D is free software: you can r redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tao3D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Tao3D, in a file named COPYING.
// If not, see <https://www.gnu.org/licenses/>.
// *****************************************************************************

#include "tao/coords3d.h"
#include "tao/module_api.h"
#include "tao/tao_gl.h"
#include "tao/graphic_state.h"
#include <QObject>
#include <vector>

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
