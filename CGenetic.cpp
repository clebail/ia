#include <QtDebug>
#include <QEventLoop>
#include <QTime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "commun.h"
#include "CGenetic.h"
#include "circuit1.cpp"
#include "circuit2.cpp"
#include "circuit3.cpp"
#include "circuit4.cpp"
#include "circuit5.cpp"

CGenetic::CGenetic(CWCircuit *wCircuit, const CSetup &setup) {
    QList<CMarker> mks1, mks2, mks3, mks4, mks5;

    initCicuit1(mks1);
    initCicuit2(mks2);
    initCicuit3(mks3);
    initCicuit4(mks4);
    initCicuit5(mks5);

    this->wCircuit = wCircuit;
    this->setup = setup;

    populationInited = false;

    circuits[0] = CCircuit(QPoint(592, 552), 0, ":/circuits/circuit1.png", QPoint(285, 285));
    circuits[1] = CCircuit(QPoint(615, 35), 0, ":/circuits/circuit2.png", QPoint(133, 436));
    circuits[2] = CCircuit(QPoint(652, 372), 0, ":/circuits/circuit3.png", QPoint(457, 217));
    circuits[3] = CCircuit(QPoint(118, 535), 0, ":/circuits/circuit4.png", QPoint(209, 203));
    circuits[4] = CCircuit(QPoint(631, 402), 0, ":/circuits/circuit5.png", QPoint(152, 138));

    circuits[0].setMarkers(mks1);
    circuits[1].setMarkers(mks2);
    circuits[2].setMarkers(mks3);
    circuits[3].setMarkers(mks4);
    circuits[4].setMarkers(mks5);
	
	currentCircuit = 0;

    connect(this->wCircuit, SIGNAL(drawVoitures(QPainter*)), this, SLOT(onWCircuitDrawVoitures(QPainter*)));
}

CGenetic::~CGenetic(void) {
}

void CGenetic::initPopulation(int from, int to) {
	int i;

    for(i=from;i<=to;i++) {
		population[i] = new CVoiture();
		population[i]->init();
	}

    populationInited = true;
}

void CGenetic::triPopulation(void) {
	int i, j;
	
	for(i=TAILLE_POPULATION-1;i>=1;i--) {
		for(j=0;j<=i-1;j++) {
			if(population[j+1]->getScore() > population[j]->getScore()) {
				CVoiture *tmp = population[j+1];
				
				population[j+1] = population[j];
				population[j] = tmp;
			}
		}
	}
}

void CGenetic::croisePopuplation(void) {
	int i, ir, max;
	
	i = 1;
	ir = TAILLE_POPULATION - 1;
	max = TAILLE_POPULATION / 2;
	
	while(i < max) {
        if(population[i-1]->getScore() > 0 && population[i]->getScore() > 0) {
            int seuilVitesse = (rand() % (NB_CAPTEUR - 1)) + 1;
            int seuilAngle = (rand() % (NB_CAPTEUR - 1)) + 1;

            croiseIndividus(i-1, i, ir, seuilVitesse, seuilAngle);
            croiseIndividus(i, i-1, ir-1, seuilVitesse, seuilAngle);

            i+=2;
            ir-=2;
        } else {
            initPopulation(i - (population[i-1]->getScore() <= 0 ? 1 : 0), max - 1);
            i = max;
        }
	}
}

void CGenetic::croiseIndividus(int i1, int i2, int ir, int seuilVitesse, int seuilAngle) {
    population[ir]->from(population[i1], population[i2], seuilVitesse, seuilAngle);
}

double CGenetic::calculDistance(QPoint p, QPoint oppose, double angle) {
    int x = p.x();
    int y = p.y();
    int dx, dy;
    
    if((angle > PI2 - 0.01 && angle < PI2 + 0.01) || (angle > 3 * PI2 - 0.01 && angle < 3 * PI2 + 0.01)) {
        int sens = oppose.y() > p.y() ? -1 : 1;
        bool fini = isDehors(QPoint(x, y));
        
        while(!fini) {
            y += sens;

            fini = isDehors(QPoint(x, y));
        }
    } else {
        double a = tan(angle);
        double b = y - a * x;
        int sens = oppose.x() > p.x() ? -1 : 1;
        bool fini = isDehors(QPoint(x, y));
        
        while(!fini) {
            x += sens;
            y = a * x + b;

            fini = isDehors(QPoint(x, y));
        }
    }
    
    circuits[currentCircuit].normCoordonnees(x, y);

    dx = abs(p.x() - x);
    dy = abs(p.y() - y);

    return sqrt(dx * dx + dy * dy);
}

void CGenetic::setCircuit(int numCircuit) {
    int i;

    currentCircuit = numCircuit;

    for(i=0;i<TAILLE_POPULATION;i++) {
        population[i]->setStartInfo(circuits[numCircuit].getDepart(), circuits[numCircuit].getAngle(), circuits[numCircuit].getMarkers());
        population[i]->setAlive(true);
    }

    emit circuitChange(&circuits[numCircuit]);
}

bool CGenetic::isDehors(const QPoint& p) {
	QImage img = circuits[currentCircuit].getImage();
	
	if(p.x() < 0 || p.y() < 0 || p.x() >= img.width() || p.y() >= img.height()) {
		return true;
	}
	
	return img.pixel(p) == 0xFF000000;
}

void CGenetic::run(void) {
    int i = 0;
	int nb = 0;
	
	srand(time(NULL));
		
	initPopulation();

    setCircuit(0);

    do {
        calculScores();
        triPopulation();
		
        qDebug() << "Num circuit" << currentCircuit << "Meilleur score" << population[0]->getScore();
		
        croisePopuplation();

        if(++nb == setup.getNbCircuit()) {
			currentCircuit = rand() % NB_CIRCUIT;//(currentCircuit + 1) % NB_CIRCUIT;
			nb=0;
		}
        setCircuit(currentCircuit);
    }while(++i < NOMBRE_GENERATION);
	
    emit calculOk(population[0]);
}

void CGenetic::drawPopulation(QPainter *painter) {
    if(populationInited) {
        int i;

        for(i=0;i<TAILLE_POPULATION;i++) {
            if(population[i]->isAlive()) {
                population[i]->draw(painter);
            }
        }
    }
}

void CGenetic::calculScores(void) {
    int i;
    int nbAlive = TAILLE_POPULATION;
    QTime time;
    int timeElapsed = 0;
    
    time.start();
    while(nbAlive != 0 && timeElapsed < MAX_TIME) {
        for(i=0;i<TAILLE_POPULATION;i++) {
            if(population[i]->isAlive()) {
                double angle = population[i]->getCurrentAngle();
                double inputs[NB_CAPTEUR];
                QPoint *posRoue = population[i]->getPosRoue();
                int nbDehors = 0;

                inputs[0] = calculDistance(posRoue[0], posRoue[2], angle);
                inputs[1] = calculDistance(posRoue[0], posRoue[1], angle + PI2);
                inputs[2] = calculDistance(posRoue[0], posRoue[3], angle + PI / 4);
                inputs[3] = calculDistance(posRoue[1], posRoue[3], angle);
                inputs[4] = calculDistance(posRoue[1], posRoue[0], angle + 3 * PI2);
                inputs[5] = calculDistance(posRoue[1], posRoue[2], angle + 7 * PI / 4);
                inputs[6] = calculDistance(posRoue[2], posRoue[3], angle + PI2);
                inputs[7] = calculDistance(posRoue[3], posRoue[2], angle + 3 * PI2);

                //inputs[8] = angle;
                //inputs[9] = population[i]->getCurrentVitesse();

                population[i]->setInputs(inputs);

                if(population[i]->move(timeElapsed)) {
					nbDehors += isDehors(posRoue[0]) ? 1 : 0;
					nbDehors += isDehors(posRoue[1]) ? 1 : 0;
					nbDehors += isDehors(posRoue[2]) ? 1 : 0;
					nbDehors += isDehors(posRoue[3]) ? 1 : 0;

					population[i]->setAlive(nbDehors < 2);
					nbAlive -= nbDehors < 2 ? 0 : 1;
				} else {
					nbAlive--;
				}
            }
        }

        emit repaintRequested();
        msleep(1000 / 24);

        timeElapsed = time.elapsed();
    }
}

void CGenetic::onWCircuitDrawVoitures(QPainter *painter) {
    drawPopulation(painter);
}
