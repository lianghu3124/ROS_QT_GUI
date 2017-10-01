#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"stdio.h"
#include "qgraphicsview.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    ui->customplot->xAxis->setRange(-1, 1);

    ui->customplot->addGraph();
    ui->customplot->graph(0)->setData(x, y);
    ui->customplot->xAxis->setLabel("x");
    ui->customplot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customplot->xAxis->setRange(-1, 1);
    ui->customplot->yAxis->setRange(0, 1);
    ui->customplot->replot();



    /*
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(0, 1);
    customPlot->replot();
    */

  this->setWindowTitle("plottest");

}

MainWindow::~MainWindow()
{
    delete ui;
}


