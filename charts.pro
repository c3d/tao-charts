# ******************************************************************************
#  charts.pro                                                       Tao project
# ******************************************************************************
# File Description:
# Qt build file for the Charts module
#
# The Charts module defines some charts for Tao Presentations
#
# ******************************************************************************
# This software is property of Taodyne SAS - Confidential
# Ce logiciel est la propriété de Taodyne SAS - Confidentiel
# (C) 2013 Baptiste Soulisse <baptiste.soulisse@taodyne.com>
# (C) 2013 Taodyne SAS
# ******************************************************************************

MODINSTDIR = charts

include(../modules.pri)

OTHER_FILES = charts.xl \
              charts2.xl \
              default-theme.xl \
              pie_chart.xl \
              line_chart.xl \
              bar_chart.xl \
              area_chart.xl

CRYPT_XL_SOURCES = charts2.xl
include(../crypt_xl.pri)

default.path = $$MODINSTPATH
default.files = default-theme.xl pie_chart.xl bar_chart.xl line_chart.xl area_chart.xl


INSTALLS    += thismod_icon default
INSTALLS    -= thismod_bin

SIGN_XL_SOURCES = default-theme.xl pie_chart.xl bar_chart.xl line_chart.xl area_chart.xl
include(../sign_xl.pri)


HEADERS += \
    doc/charts.doxy.h

QMAKE_SUBSTITUTES = doc/Doxyfile.in
DOXYFILE = doc/Doxyfile
DOXYLANG = en,fr
include(../modules_doc.pri)
