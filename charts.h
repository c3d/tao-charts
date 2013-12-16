#ifndef CHARTS_H
#define CHARTS_H
// ****************************************************************************
//  charts.h                                                       Tao project
// ****************************************************************************
//
//   File Description:
//
//    Prototype of the function used by charts.tbl to
//    implement the new XL primitive
//
//
//
//
//
//
// ****************************************************************************
// This software is property of Taodyne SAS - Confidential
// Ce logiciel est la propriété de Taodyne SAS - Confidentiel
//  (C) 1992-2010 Christophe de Dinechin <christophe@taodyne.com>
//  (C) 2010 Jerome Forissier <jerome@taodyne.com>
//  (C) 2011 Baptiste Soulisse <baptiste.soulisse@taodyne.com>
//  (C) 2011 Taodyne SAS
// ****************************************************************************
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
    static Tree_p chart_sum(text name, uint set);
    static Tree_p chart_max(text name, uint set);
    static Tree_p chart_max_count(text);
    static Tree_p chart_count(text, uint set);
    static Tree_p chart_datasets_count(text);
    static Tree_p chart_set_datasets_count(text name, uint count);
    static Tree_p chart_data_property(text name, int s, uint i, text);
    static Tree_p chart_data_set_property(text name, int s, uint i, text, double);

    // Chart
    static Tree_p chart_reset(text name);
    static Name_p chart_only(text name);
    static Name_p chart_drop(text name);
    static Tree_p chart_current(text name);
    static Tree_p chart_create(Context *context, text name, uint start,
                               uint end, text master, Tree_p prog);
    static Tree_p chart_name(text name);
    static Tree_p chart_master(text name);
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
