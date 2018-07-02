#include <QtDebug>
#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);
}

CMainWindow::~CMainWindow(void) {
}

void CMainWindow::onGeneticCalculOk(CVoiture *best) {
}

void CMainWindow::onGeneticCircuitChange(CCircuit *circuit) {
    wCircuit->setCircuit(circuit);
}

void CMainWindow::onGeneticRepaintRequested(void) {
	int elapsed = mainTime.elapsed() / 1000;
	QString time = "%1:%2:%3";
	
	time = time.arg(elapsed / 3600, 2, 10, QChar('0')).arg(elapsed / 60, 2, 10, QChar('0')).arg(elapsed % 60, 2, 10, QChar('0'));
	
	wCircuit->setElapsedTime(time);
    wCircuit->repaint();
    wCircuit->createImage("images/img_"+QString("%1").arg(imgIdx, 6, 10, QChar('0'))+".jpg");

    imgIdx++;
}

void CMainWindow::onGeneticTerminated(void) {
    delete genetic;

    pbTest->setEnabled(true);
}

void CMainWindow::on_pbTest_clicked(bool) {
    pbTest->setEnabled(false);

    imgIdx = 1;

    setup.setNbCircuit(sbCircuit->value());
    setup.setCreateImages(cbCreateImage->isChecked());

    genetic = new CGenetic(wCircuit, setup);

    connect(genetic, SIGNAL(calculOk(CVoiture*)), this, SLOT(onGeneticCalculOk(CVoiture*)));
    connect(genetic, SIGNAL(circuitChange(CCircuit*)), this, SLOT(onGeneticCircuitChange(CCircuit*)));
    connect(genetic, SIGNAL(repaintRequested()), this, SLOT(onGeneticRepaintRequested()));
    connect(genetic, SIGNAL(terminated()), this, SLOT(onGeneticTerminated()));

	mainTime.start();
    genetic->start();
}

void CMainWindow::on_pbTestVoiture_clicked(bool) {
    testVoiture.setStartInfo(QPoint(250, 250), 0, QList<CMarker>());
	
	connect(wCircuit, SIGNAL(drawVoitures(QPainter *)), this, SLOT(onTVdrawVoitures(QPainter *)));
	
	for(int i=0;i<50;i++) {
		testVoiture.realMove(2, leAngle->text().toDouble());
		wCircuit->repaint();
	}
	
	disconnect(wCircuit, SIGNAL(drawVoitures(QPainter *)), this, SLOT(onTVdrawVoitures(QPainter *)));
}

void CMainWindow::CMainWindow::onTVdrawVoitures(QPainter *painter) {
	testVoiture.draw(painter);
}

void CMainWindow::on_pbCalculMarkers_clicked(bool) {
    QStringList l = leDepart->text().split(",");
    QPoint depart(QPoint(l.at(0).toInt(), l.at(1).toInt()));
    CCircuit circuit(depart, 0, ":circuits/circuit"+QString::number(sbNumCircuit->value())+".png", QPoint(96, 220));

    wCircuit->setCircuit(&circuit);
    wCircuit->calculMarkers(depart, leDistance->text().toDouble(), leAngleDepart->text().toDouble(), sbNumCircuit->value());
}
