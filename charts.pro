# ******************************************************************************
#  charts.pro                                                  Tao project
# ******************************************************************************
# File Description:
# Qt build file for the Filters module
# ******************************************************************************
# This software is property of Taodyne SAS - Confidential
# Ce logiciel est la propriété de Taodyne SAS - Confidentiel
# (C) 2010 Jerome Forissier <jerome@taodyne.com>
# (C) 2010 Taodyne SAS
# ******************************************************************************

MODINSTDIR = charts

include(../modules.pri)



INCLUDEPATH += $${TAOTOPSRC}/tao/include/tao/
HEADERS = \
          charts.h \
          chart.h

SOURCES = charts.cpp \
          chart.cpp

win32 {
    DEFINES     += GLEW_STATIC
    SOURCES     += $${TAOTOPSRC}/tao/include/tao/GL/glew.c
}

TBL_SOURCES  = charts.tbl


OTHER_FILES = charts.xl \
              charts2.xl \
              default-theme.xl \
              pie_chart.xl \
              line_chart.xl \
              bar_chart.xl \
              area_chart.xl \
              charts.tbl \
              traces.tbl

QT          += core \
               gui \
               opengl

default.path = $$MODINSTPATH
default.files = charts2.xl default-theme.xl pie_chart.xl bar_chart.xl line_chart.xl area_chart.xl

INSTALLS    += thismod_icon default

SIGN_XL_SOURCES = charts2.xl default-theme.xl pie_chart.xl bar_chart.xl line_chart.xl area_chart.xl
include(../sign_xl.pri)

QMAKE_SUBSTITUTES = doc/Doxyfile.in
DOXYFILE = doc/Doxyfile
DOXYLANG = en,fr
include(../modules_doc.pri)

