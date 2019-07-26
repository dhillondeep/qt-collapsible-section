/*
    dhillondeep/qt-collapsible-section
    (c) 2016 Michael A. Voelkel - michael.alexander.voelkel@gmail.com
    (c) 2019 Deep Dhillon - deep@dhillon.io

    This file is part of dhillondeep/qt-collapsible-section.

    dhillondeep/qt-collapsible-section is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    dhillondeep/qt-collapsible-section is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with dhillondeep/qt-collapsible-section. If not, see <http://www.gnu.org/licenses/>.
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
