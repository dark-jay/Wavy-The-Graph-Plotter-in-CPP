#include "graphengine.h"

graphEngine::graphEngine()
{
    widget a;
}

void graphEngine::plotGraph(std::string inputString, int times){
    msp myMsp(inputString);
    const int twoPi = 630; // one complete cycle

    // generate some data
    QVector<double> x1(twoPi*times), y1(twoPi*times); // initialize with entries 0..100
    QVector<double> x2(twoPi*times), y2(twoPi*times);
    for(double i=0; i<twoPi*times; ++i){
        // left graph
        x1[i] = -i/100.0;
        y1[i] = myMsp.returnYvalue(x1[i]);
        // right graph
        x2[i] = i/100.0;
        y2[i] = myMsp.returnYvalue(x2[i]);
    }
    // create graph and assign data to it
    ui->WidCustomPlot->addGraph();
    ui->WidCustomPlot->graph(0)->setData(x1,y1);
    ui->WidCustomPlot->addGraph();
    ui->WidCustomPlot->graph(1)->setData(x2,y2);
    // give the axes some labels
    ui->WidCustomPlot->xAxis->setLabel("X");
    ui->WidCustomPlot->yAxis->setLabel("Y");
    // set axes ranges, so we see all data
    ui->WidCustomPlot->xAxis->setRange(-5,5);
    ui->WidCustomPlot->yAxis->setRange(-5,5);
    //ui->WidCustomPlot->graph(0)->rescaleAxes(); // this will automatically resccale the view as the size of graph
    //ui->WidCustomPlot->graph(1)->rescaleAxes(true);
    ui->WidCustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->WidCustomPlot->replot();
}

void graphEngine::clearAllGraph(){
    ui->WidCustomPlot->clearGraphs();
    ui->WidCustomPlot->replot();
}
