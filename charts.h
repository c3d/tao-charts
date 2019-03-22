#ifndef CHARTS_H
#define CHARTS_H
// *****************************************************************************
// charts.h                                                        Tao3D project
// *****************************************************************************
//
// File description:
//
//    Prototype of the function used by charts.tbl to
//    implement the new XL primitive
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
#include "tree.h"
#include "main.h"
#include "runtime.h"
#include "base.h"
#include "tao/module_api.h"
#include "chart.h"

using namespace XL;


struct Chart;

class ChartFactory
{
    ChartFactory();
    virtual ~ChartFactory() {}

    Chart *       chart(text name);
    QList<Chart*> chartsList(text name);

public:
    static ChartFactory * instance();
    static void           destroy();

    static void   render_callback(void *arg);
    static void   identify_callback(void *arg);
    static void   delete_callback(void *arg);

    // Data
    static Tree_p chart_push_data(text name, uint unit, float value);
    static Tree_p chart_data(text name, uint set, uint index);
    static Tree_p chart_data_ratio(text name, uint set, uint index);
    static Tree_p chart_sum(text name, uint set, bool abs);
    static Tree_p chart_max(text name, uint set);
    static Tree_p chart_min(text name, uint set);
    static Tree_p chart_max_count(text);
    static Tree_p chart_count(text, uint set);
    static Tree_p chart_datasets_count(text);
    static Tree_p chart_reset_datasets(text name);
    static Tree_p chart_push_dataset(text name, uint s);
    static Tree_p chart_dataset(text name, uint index);
    static Tree_p chart_set_datasets_count(text name, uint count);
    static Tree_p chart_data_property(text name, int s, uint i, text);
    static Tree_p chart_data_set_property(text name, int s, uint i, text, double);

    // Chart
    static Tree_p chart_reset(text name);
    static Name_p chart_only(text name);
    static Name_p chart_drop(text name);
    static Tree_p chart_current(text name);
    static Tree_p chart_create(Context *context, text name, Tree_p prog);
    static Tree_p chart_name(text name);
    static Tree_p chart_type(text name);
    static Tree_p chart_type(text name, text master);
    static Tree_p chart_style(text name);
    static Tree_p chart_style(text name, text style);
    static Tree_p chart_format(text name);
    static Tree_p chart_format(text name, text format);
    static Tree_p chart_first(text name);
    static Tree_p chart_last(text name);

    // Title
    static Tree_p chart_title(text name);
    static Tree_p chart_title(text name, text title);

    // Legend
    static Tree_p chart_legend(text name, uint N);
    static Tree_p chart_legend(text name, uint N, text entry);

    // Axis labels
    static Tree_p  chart_xlabel(text name);
    static Tree_p  chart_xlabel(text name, text label);
    static Tree_p  chart_ylabel(text name);
    static Tree_p  chart_ylabel(text name, text label);

    // Axis
    static Tree_p chart_max_axis(text name);
    static Tree_p chart_max_axis(text name, double max, bool adjust);
    static Tree_p chart_min_axis(text name);
    static Tree_p chart_min_axis(text name, double max, bool adjust);
    static Tree_p chart_xticks(text name);
    static Tree_p chart_xticks(text name, uint ticks);
    static Tree_p chart_yticks(text name);
    static Tree_p chart_yticks(text name, uint ticks);

    // Ticks labels
    static Tree_p chart_xticks_label(text name, uint N);
    static Tree_p chart_yticks_label(text name, uint N);
    static Tree_p chart_xticks_label(text name, uint N, text label);
    static Tree_p chart_yticks_label(text name, uint N, text label);

public:
    const Tao::ModuleApi *  tao;

protected:
    typedef std::map<text, Chart *>  chart_map;
    chart_map charts;

protected:
    static ChartFactory * factory;
};

#endif
