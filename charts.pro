# ******************************************************************************
# charts.pro                                                       Tao3D project
# ******************************************************************************
#
# File description:
# Qt build file for the Filters module
#
#
#
#
#
#
#
# ******************************************************************************
# This software is licensed under the GNU General Public License v3
# (C) 2013, Baptiste Soulisse <baptiste.soulisse@taodyne.com>
# (C) 2014-2015,2019, Christophe de Dinechin <christophe@dinechin.org>
# (C) 2013, Jérôme Forissier <jerome@taodyne.com>
# ******************************************************************************
# This file is part of Tao3D
#
# Tao3D is free software: you can r redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Tao3D is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Tao3D, in a file named COPYING.
# If not, see <https://www.gnu.org/licenses/>.
# ******************************************************************************

MODINSTDIR = charts

include(../modules.pri)



INCLUDEPATH += $${TAOTOPSRC}/tao/include/tao/
HEADERS = \
          charts.h \
          chart.h

SOURCES = charts.cpp \
          chart.cpp

TBL_SOURCES  = charts.tbl


OTHER_FILES = charts.xl \
              default-theme.xl \
              pie_chart.xl \
              line_chart.xl \
              bar_chart.xl \
              area_chart.xl \
              charts.tbl \
              traces.tbl \
              doc/Doxyfile.in \
              doc/charts.doxy.h

QT          += core \
               gui \
               opengl

default.path = $$MODINSTPATH
default.files = charts.xl default-theme.xl pie_chart.xl bar_chart.xl line_chart.xl area_chart.xl

INSTALLS    += thismod_icon default

SIGN_XL_SOURCES = charts.xl default-theme.xl pie_chart.xl bar_chart.xl line_chart.xl area_chart.xl
include(../sign_xl.pri)

QMAKE_SUBSTITUTES = doc/Doxyfile.in
DOXYFILE = doc/Doxyfile
DOXYLANG = en,fr
DOXYADDFILES = doc/charts.ddd
include(../modules_doc.pri)

