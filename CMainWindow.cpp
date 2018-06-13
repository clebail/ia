#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);
    
    connect(&genetic, SIGNAL(readyToCalculScore(bool)), this, SLOT(onGeneticReadyToCalculScore(bool)));

    circuits[0] = CCircuit(QPoint(85, 51), ":/circuits/circuit1.png");
    circuits[1] = CCircuit(QPoint(134, 54), ":/circuits/circuit2.png");
    circuits[2] = CCircuit(QPoint(134, 30), ":/circuits/circuit3.png");
    circuits[3] = CCircuit(QPoint(134, 28), ":/circuits/circuit4.png");

    currentCircuit = 0;
    wCircuit->setCircuit(&circuits[currentCircuit]);
    genetic.process();
}

void CMainWindow::onGeneticReadyToCalculScore(bool changeCircuit) {
    genetic.setCircuit(circuits[currentCircuit]);
    genetic.calculScores();
    
    if(changeCircuit) {
        currentCircuit = (currentCircuit + 1) % NB_CIRCUIT;
        wCircuit->setCircuit(&circuits[currentCircuit]);
    }
}

void CMainWindow::on_wCircuit_drawVoitures(QPainter *painter) {
    genetic.drawPopulation(painter);
}
