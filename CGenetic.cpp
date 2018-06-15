#include <QtDebug>
#include <QEventLoop>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "CGenetic.h"

CGenetic::CGenetic(CWCircuit *wCircuit) {
    this->wCircuit = wCircuit;

    populationInited = false;

    circuits[0] = CCircuit(QPoint(85, 51), ":/circuits/circuit1.png");
    circuits[1] = CCircuit(QPoint(134, 54), ":/circuits/circuit2.png");
    circuits[2] = CCircuit(QPoint(134, 30), ":/circuits/circuit3.png");
    circuits[3] = CCircuit(QPoint(134, 28), ":/circuits/circuit4.png");

    connect(this->wCircuit, SIGNAL(drawVoitures(QPainter*)), this, SLOT(onWCircuitDrawVoitures(QPainter*)));
}

CGenetic::~CGenetic(void) {
}

void CGenetic::initPopulation(void) {
	int i;

    for(i=0;i<TAILLE_POPULATION;i++) {
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
		int seuil = (rand() % (NB_GENE - 2)) + 1;
		
		croiseIndividus(i-1, i, ir, seuil);
		croiseIndividus(i, i-1, ir-1, seuil);
		
        i+=2;
		ir-=2;
	}
}

void CGenetic::croiseIndividus(int i1, int i2, int ir, int seuil) {
	population[ir]->from(population[i1], population[i2], seuil);
	
	if(rand() % 10 < 7) {
		population[ir]->mute(rand() % NB_GENE);
	}
}

double CGenetic::calculDistance(QPoint p, QPoint oppose, double angle) {
    int x = p.x();
    int y = p.y();
    int dx, dy;
    
    if((angle > PI2 - 0.01 && angle < PI2 + 0.01) || (angle > 3 * PI2 - 0.01 && angle < 3 * PI2 + 0.01)) {
        int sens = oppose.y() > p.y() ? -1 : 1;
        bool fini = y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        
        while(!fini) {
            y += sens;

            fini = y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        }
    } else {
        double a = tan(angle);
        double b = y - a * x;
        int sens = oppose.x() > p.x() ? -1 : 1;
        bool fini = x < 0 || x > 500 || y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        
        while(!fini) {
            x += sens;
            y = a * x + b;

            fini = x < 0 || x > 500 || y < 0 || y > 500 || circuits[currentCircuit].getImage().pixel(x, y) == 0xFF000000;
        }
    }

    x = CCircuit::normCoordonnees(x);
    y = CCircuit::normCoordonnees(y);

    dx = abs(p.x() - x);
    dy = abs(p.y() - y);

    return sqrt(dx * dx + dy * dy);
}

void CGenetic::setCircuit(int numCircuit) {
    int i;

    currentCircuit = numCircuit;

    for(i=0;i<TAILLE_POPULATION;i++) {
        population[i]->setPosition(circuits[numCircuit].getDepart());
        population[i]->setAlive(true);
    }

    emit circuitChange(&circuits[numCircuit]);
}

void CGenetic::run(void) {
    int i = 0;
	
	srand(time(NULL));
		
	initPopulation();

    setCircuit(0);

    do {
        calculScores();
        triPopulation();
        croisePopuplation();

        setCircuit((currentCircuit + 1) % NB_CIRCUIT);
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
    int nbIter = 0;
    
    while(nbAlive != 0 && nbIter < 200) {
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

                population[i]->setInputs(inputs);

                population[i]->move();

                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[0]) == 0xFF000000 ? 1 : 0;
                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[1]) == 0xFF000000 ? 1 : 0;
                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[2]) == 0xFF000000 ? 1 : 0;
                nbDehors += circuits[currentCircuit].getImage().pixel(posRoue[3]) == 0xFF000000 ? 1 : 0;

                population[i]->setAlive(nbDehors < 2);
                nbAlive -= nbDehors < 2 ? 0 : 1;
            }
        }

        emit repaintRequested();
        msleep(1000 / 24);

        nbIter++;
    }
}

void CGenetic::onWCircuitDrawVoitures(QPainter *painter) {
    drawPopulation(painter);
}
