#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);
    
    connect(&genetic, SIGNAL(readyToCalculScore()), this, SLOT(onGeneticReadyToCalculScore()));

    circuits[0] = CCircuit(QPoint(134, 28), ":/circuits/circuit1.png");
    circuits[1] = CCircuit(QPoint(134, 54), ":/circuits/circuit2.png");
    circuits[2] = CCircuit(QPoint(134, 30), ":/circuits/circuit3.png");
    circuits[3] = CCircuit(QPoint(134, 28), ":/circuits/circuit4.png");

    currentCircuit = 0;
    wCircuit->setCircuit(&circuits[currentCircuit]);
}

void CMainWindow::onGeneticReadyToCalculScore(void) {
    genetic.setCircuit(circuits[currentCircuit]);
    
    currentCircuit = (currentCircuit + 1) % NB_CIRCUIT;
}

void CMainWindow::on_wCircuit_drawVoitures(QPainter *painter) {
}
