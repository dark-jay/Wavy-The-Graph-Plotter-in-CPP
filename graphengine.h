#ifndef GRAPHENGINE_H
#define GRAPHENGINE_H
#include "mainwindow.h"

class graphEngine
{
public:
    graphEngine();
    void plotGraph(std::string inputString, int times);
    void clearAllGraph();

private:
    Ui::MainWindow *ui;
};

#endif // GRAPHENGINE_H
