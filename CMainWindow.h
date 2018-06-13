#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "ui_CMainWindow.h"
#include "CCircuit.h"
#include "CGenetic.h"

#define NB_CIRCUIT              4

class CMainWindow : public QMainWindow, private Ui::CMainWindow {
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);
private:
    CCircuit circuits[NB_CIRCUIT];
    CGenetic genetic;
    
    int currentCircuit;
private slots:
    void onGeneticReadyToCalculScore(bool changeCircuit);
    void on_wCircuit_drawVoitures(QPainter *painter);
};

#endif // CMAINWINDOW_H
