//    PAL Tester GUI
//    Copyright (C) 2025-...  Oleksandr Kolodkin <oleksandr.kolodkin@ukr.net>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // View Log
    connect(ui->actionShowLog, &QAction::triggered, ui->dockLog, &QDockWidget::setVisible);
    connect(ui->dockLog, &QDockWidget::visibilityChanged, ui->actionShowLog, &QAction::setChecked);

    // About
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);


    updateState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveSession()
{
    QSettings settings;

    settings.setValue("geometry"     , saveGeometry());
    settings.setValue("state"        , saveState());
}

void MainWindow::restoreSession()
{
    QSettings settings;

    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("state").toByteArray());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveSession();
    event->accept();
}

void MainWindow::updateState()
{

}
