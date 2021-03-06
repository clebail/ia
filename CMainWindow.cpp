#include <QtDebug>
#include <QKeyEvent>
#include <iostream>
#include <json.h>
#include "CMainWindow.h"
#include "CResultTestDialog.h"
#include "CJSonDialog.h"
#include "CVerdict.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi(this);

    testVoiture = 0;
    testVoiturePilote = 0;
    testPiloteTimer = 0;

    spVainqueur->setMaximum(TAILLE_POPULATION);
    spVainqueur->setValue(TAILLE_POPULATION / 4);

    cbCircuit->addItem("Circuit normal", QVariant(":/circuits/circuitFinal.png"));
    cbCircuit->addItem("Circuit fun", QVariant(":/circuits/circuitFinalFun.png"));
}

CMainWindow::~CMainWindow(void) {
}

bool CMainWindow::eventFilter(QObject *obj, QEvent *event) {
    if(testVoiturePilote != 0) {
        if(event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

            switch(keyEvent->key()) {
            case Qt::Key_Plus:
                testVoiturePilote->incVitesse(1.0);
                break;
            case Qt::Key_D:
                testVoiturePilote->incAngle(-PI/8);
                break;
            case Qt::Key_Minus:
                testVoiturePilote->incVitesse(-1.0);
                break;
            case Qt::Key_G:
                testVoiturePilote->incAngle(PI/8);
                break;
            default:
                break;
            }
        }
    }

    return QObject::eventFilter(obj, event);
}

void CMainWindow::onGeneticCalculOk(void) {
   	int i;
    QString result = "[\r\n";
	
	for(i=0;i<genetic->getVainqueurs().size();i++) {
		if(i != 0) {
            result += ",\r\n";
		}
		
        result += genetic->getVainqueurs().at(i)->serialize();
	}
	
    result += "\r\n]\r\n";

    CResultTestDialog resultDialog(this, result);
    resultDialog.exec();
}

void CMainWindow::onGeneticCircuitChange(CCircuit *circuit) {
    wCircuit->setCircuit(circuit);
}

void CMainWindow::onGeneticRepaintRequested(const QPointF& posMeilleur) {
	int elapsed = mainTime.elapsed() / 1000;
	QString time = "%1:%2:%3";
	
	time = time.arg((elapsed / 3600) % 60, 2, 10, QChar('0')).arg((elapsed / 60) % 60, 2, 10, QChar('0')).arg(elapsed % 60, 2, 10, QChar('0'));
	
	wCircuit->setElapsedTime(time);
    wCircuit->setPositionRef(posMeilleur.toPoint());
	if(setup.getCreateImages()) {
		wCircuit->createImage("images/img_"+QString("%1").arg(imgIdx, 6, 10, QChar('0'))+".jpg");
	}

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
    setup.setNbVainqueur(spVainqueur->value());

    genetic = new CGenetic(wCircuit, setup);

    connect(genetic, SIGNAL(calculOk()), this, SLOT(onGeneticCalculOk()));
    connect(genetic, SIGNAL(circuitChange(CCircuit*)), this, SLOT(onGeneticCircuitChange(CCircuit*)));
    connect(genetic, SIGNAL(repaintRequested(const QPointF&)), this, SLOT(onGeneticRepaintRequested(const QPointF&)));
    connect(genetic, SIGNAL(terminated()), this, SLOT(onGeneticTerminated()));

	mainTime.start();
    genetic->start();
}

void CMainWindow::on_pbTestVoiture_clicked(bool) {
    testVoiture = new CTestVoitureAngle(QPoint(400, 300), leAngle->text().toDouble());

    connect(wCircuit, SIGNAL(drawVoitures(QPainter *, double , double)), this, SLOT(onTVdrawVoitures(QPainter *, double , double)));
	
	for(int i=0;i<50;i++) {
        bool b;

        testVoiture->move(0, b);
        wCircuit->repaint();
	}
	
    disconnect(wCircuit, SIGNAL(drawVoitures(QPainter *, double , double)), this, SLOT(onTVdrawVoitures(QPainter *, double , double)));

    delete testVoiture;
    testVoiture = 0;
}

void CMainWindow::CMainWindow::onTVdrawVoitures(QPainter *painter, double dx, double dy) {
    if(testVoiture != 0) {
        testVoiture->draw(painter, dx, dy);
    }
}

void CMainWindow::on_pbCalculMarkers_clicked(bool) {
    QStringList l = leDepart->text().split(",");
    QPoint depart(QPoint(l.at(0).toInt(), l.at(1).toInt()));
    CCircuit circuit(depart, 0, ":circuits/circuit"+QString::number(sbNumCircuit->value())+".png");

    wCircuit->setCircuit(&circuit);
    wCircuit->calculMarkers(depart, leDistance->text().toDouble(), leAngleDepart->text().toDouble(), sbNumCircuit->value(), cbShowDroite->isChecked());
}

void CMainWindow::on_pbTestPilote_clicked(bool) {
    if(testVoiturePilote == 0) {
		QStringList l = leDepartPilote->text().split(",");
		QPoint depart(QPoint(l.at(0).toInt(), l.at(1).toInt()));
		circuitPilote = new CCircuit(depart, 0, ":circuits/circuit"+QString::number(sbNumCircuitPilote->value())+".png");

        wCircuit->setCircuit(circuitPilote);

        testVoiturePilote = new CTestVoiturePilote(circuitPilote, depart, leAngleDepartPilote->text().toDouble(), cbCapteurs->isChecked());

        connect(wCircuit, SIGNAL(drawVoitures(QPainter *, double , double)), this, SLOT(onTVPdrawVoitures(QPainter *, double , double)));

        installEventFilter(this);

        testPiloteTimer = new QTimer(this);

        connect(testPiloteTimer, SIGNAL(timeout()), this, SLOT(onTestTimerPiloteTimeout()));

        testPiloteTimer->setInterval(1000 / 24);

        testPiloteTimer->start();
    } else {
        disconnect(wCircuit, SIGNAL(drawVoitures(QPainter *, double , double)), this, SLOT(onTVPdrawVoitures(QPainter *, double , double)));

        removeEventFilter(this);

        delete testVoiturePilote;
        delete testPiloteTimer;
		delete circuitPilote;

        testVoiturePilote = 0;
    }
}

void CMainWindow::onTVPdrawVoitures(QPainter *painter, double dx, double dy) {
	if(testVoiturePilote != 0) {
        testVoiturePilote->draw(painter, dx, dy);
	}
}

void CMainWindow::onTestTimerPiloteTimeout(void) {
	if(testVoiturePilote != 0) {
        bool b;

        testVoiturePilote->move(0, b);
		wCircuit->update();
	}
}

void CMainWindow::on_pbVerdict_clicked(bool) {
    CJSonDialog dialog(this);

    if(dialog.exec() == QDialog::Accepted) {
        QString jSon = dialog.getJSon();

        if(!jSon.isEmpty()) {
            CVerdict *verdict = new CVerdict(wCircuit, cbCircuit->itemData(cbCircuit->currentIndex()).toString(), jSon);

            connect(verdict, SIGNAL(repaintRequested(const QPointF&)), this, SLOT(onVerdictRepaintRequested(const QPointF&)));

            mainTime.start();
            verdict->start();
        }
    }
}

void CMainWindow::onVerdictRepaintRequested(const QPointF& posMeilleur) {
    int elapsed = mainTime.elapsed() / 1000;
    QString time = "%1:%2:%3";

    time = time.arg((elapsed / 3600) % 60, 2, 10, QChar('0')).arg((elapsed / 60) % 60, 2, 10, QChar('0')).arg(elapsed % 60, 2, 10, QChar('0'));

    wCircuit->setElapsedTime(time);
    wCircuit->setPositionRef(posMeilleur.toPoint());
}
