#include <QtDebug>
#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);

    genetic = new CGenetic(wCircuit);

    connect(genetic, SIGNAL(calculOk(CVoiture*)), this, SLOT(onGeneticCalculOk(CVoiture*)));
    connect(genetic, SIGNAL(circuitChange(CCircuit*)), this, SLOT(onGeneticCircuitChange(CCircuit*)));
    connect(genetic, SIGNAL(repaintRequested()), this, SLOT(onGeneticRepaintRequested()));
}

CMainWindow::~CMainWindow(void) {
    delete genetic;
}

void CMainWindow::onGeneticCalculOk(CVoiture *best) {

}

void CMainWindow::onGeneticCircuitChange(CCircuit *circuit) {
    wCircuit->setCircuit(circuit);
}

void CMainWindow::onGeneticRepaintRequested(void) {
    wCircuit->repaint();
}

void CMainWindow::on_pbTest_clicked(bool) {
    genetic->start();
}
