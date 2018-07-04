#include <QtDebug>
#include <QKeyEvent>
#include "CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);

    testVoiture = 0;
}

CMainWindow::~CMainWindow(void) {
}

bool CMainWindow::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        switch(keyEvent->key()) {
        case Qt::Key_Plus:
            break;
        case Qt::Key_Right:
            break;
        case Qt::Key_Minus:
            break;
        case Qt::Key_Left:
            break;
        default:
            break;
        }
    }

    return QObject::eventFilter(obj, event);
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
    testVoiture = new CTestVoitureAngle(QPoint(400, 300), leAngle->text().toDouble());

    connect(wCircuit, SIGNAL(drawVoitures(QPainter *)), this, SLOT(onTVdrawVoitures(QPainter *)));
	
	for(int i=0;i<50;i++) {
        testVoiture->move(0);
        wCircuit->repaint();
	}
	
	disconnect(wCircuit, SIGNAL(drawVoitures(QPainter *)), this, SLOT(onTVdrawVoitures(QPainter *)));

    delete testVoiture;
    testVoiture = 0;
}

void CMainWindow::CMainWindow::onTVdrawVoitures(QPainter *painter) {
    if(testVoiture != 0) {
        testVoiture->draw(painter);
    }
}

void CMainWindow::on_pbCalculMarkers_clicked(bool) {
    QStringList l = leDepart->text().split(",");
    QPoint depart(QPoint(l.at(0).toInt(), l.at(1).toInt()));
    CCircuit circuit(depart, 0, ":circuits/circuit"+QString::number(sbNumCircuit->value())+".png", QPoint(96, 220));

    wCircuit->setCircuit(&circuit);
    wCircuit->calculMarkers(depart, leDistance->text().toDouble(), leAngleDepart->text().toDouble(), sbNumCircuit->value());
}
