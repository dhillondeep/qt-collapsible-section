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
#include "ui_mainwindow.h"
#include "Section.h"

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Section* section = new Section("Section", 300, ui->centralWidget);
    ui->centralWidget->layout()->addWidget(section);

    auto* anyLayout = new QVBoxLayout();
    anyLayout->addWidget(new QLabel("Some Text in Section", section));
    anyLayout->addWidget(new QPushButton("Button in Section", section));

    section->setContentLayout(anyLayout);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    section->setToggleButtonStyle("QToolButton {color: white;}");
    section->setContentAreaFrameShape(QFrame::NoFrame);
}

MainWindow::~MainWindow()
{
    delete ui;
}
