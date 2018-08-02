#include <QtDebug>
#include <QEventLoop>
#include <QTime>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "commun.h"
#include "CGenetic.h"
#include "CDistanceHelper.h"
#include "circuit1.cpp"
#include "circuit2.cpp"
#include "circuit3.cpp"
#include "circuit4.cpp"
#include "circuit5.cpp"
#include "circuit6.cpp"
#include "circuit7.cpp"
#include "circuit8.cpp"
#include "circuit9.cpp"
#include "circuit10.cpp"
#include "circuit11.cpp"
#include "circuit12.cpp"

CGenetic::CGenetic(CWCircuit *wCircuit, const CSetup &setup) {
    QList<CMarker> mks0, mks1, mks2, mks3, mks4, mks5, mks6, mks7, mks8, mks9, mks10, mks11;

    initCircuit1(mks0);
    initCircuit2(mks1);
    initCircuit3(mks2);
    initCircuit4(mks3);
    initCircuit5(mks4);
    initCircuit6(mks5);
    initCircuit7(mks6);
    initCircuit8(mks7);
    initCircuit9(mks8);
    initCircuit10(mks9);
    initCircuit11(mks10);
    initCircuit12(mks11);

    this->wCircuit = wCircuit;
    this->setup = setup;

    populationInited = false;

    circuits[0] = CCircuit(QPoint(592, 552), PI, ":/circuits/circuit1.png", QPoint(285, 285));
    circuits[1] = CCircuit(QPoint(615, 35), PI, ":/circuits/circuit2.png", QPoint(133, 436));
    circuits[2] = CCircuit(QPoint(652, 372), PI, ":/circuits/circuit3.png", QPoint(457, 217));
    circuits[3] = CCircuit(QPoint(118, 535), PI, ":/circuits/circuit4.png", QPoint(209, 203));
    circuits[4] = CCircuit(QPoint(631, 402), PI, ":/circuits/circuit5.png", QPoint(152, 138));
    circuits[5] = CCircuit(QPoint(539, 543), PI, ":/circuits/circuit6.png", QPoint(527, 279));
    circuits[6] = CCircuit(QPoint(592, 552), 0, ":/circuits/circuit1.png", QPoint(285, 285));
    circuits[7] = CCircuit(QPoint(615, 35), 0, ":/circuits/circuit2.png", QPoint(133, 436));
    circuits[8] = CCircuit(QPoint(652, 372), 0, ":/circuits/circuit3.png", QPoint(457, 217));
    circuits[9] = CCircuit(QPoint(118, 535), 0, ":/circuits/circuit4.png", QPoint(209, 203));
    circuits[10] = CCircuit(QPoint(631, 402), 0, ":/circuits/circuit5.png", QPoint(152, 138));
    circuits[11] = CCircuit(QPoint(539, 543), 0, ":/circuits/circuit6.png", QPoint(527, 279));

    circuits[0].setMarkers(mks0);
    circuits[1].setMarkers(mks1);
    circuits[2].setMarkers(mks2);
    circuits[3].setMarkers(mks3);
    circuits[4].setMarkers(mks4);
    circuits[5].setMarkers(mks5);
    circuits[6].setMarkers(mks6);
    circuits[7].setMarkers(mks7);
    circuits[8].setMarkers(mks8);
    circuits[9].setMarkers(mks9);
    circuits[10].setMarkers(mks10);
    circuits[11].setMarkers(mks11);
	
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
            croiseIndividus(i-1, i, ir);
            croiseIndividus(i, i-1, ir-1);

            i+=2;
            ir-=2;
        } else {
            initPopulation(i - (population[i-1]->getScore() <= 0 ? 1 : 0), max - 1);
            i = max;
        }
	}
}

void CGenetic::croiseIndividus(int i1, int i2, int ir) {
    population[ir]->from(population[i1], population[i2]);
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

bool CGenetic::calculVainqueurs(void) {
    int i;

    vainqueurs.clear();
    for(i=0;i<TAILLE_POPULATION;i++) {
        int j;
        bool allOk = true;

        for(j=0;j<NB_CIRCUIT;j++) {
            allOk &= population[i]->isVainqueur(j);
        }

        if(allOk) {
            vainqueurs.append(population[i]);
            population[i]->setChampion();
        }
    }

    return vainqueurs.size() >= setup.getNbVainqueur();
}

void CGenetic::run(void) {
    int i = 0;
	int nb = 0;
    bool fini;
	
	srand(time(NULL));
		
	initPopulation();

    setCircuit(0);

    do {
        calculScores();
        triPopulation();
		
        fini = calculVainqueurs();

        qDebug() << "Num circuit" << currentCircuit << "Meilleur score" << population[0]->getScore() << "Nombre de gagnant" << circuits[currentCircuit].getNbGagne() << "total vainqueurs" << vainqueurs.size();
		
        if(!fini) {
            croisePopuplation();

            if(++nb == setup.getNbCircuit()) {
                currentCircuit = (currentCircuit + 1) % NB_CIRCUIT;
                nb=0;
                if(currentCircuit == 0) {
                    qDebug() << "";
                }
            }
            setCircuit(currentCircuit);
            circuits[currentCircuit].setNbGagne(0);
        }

        fini |= (++i >= NOMBRE_GENERATION);
    }while(!fini);
	
    emit calculOk();
}

void CGenetic::drawPopulation(QPainter *painter) {
    if(populationInited) {
        int i;

        for(i=0;i<TAILLE_POPULATION;i++) {
            //if(population[i]->isAlive()) {
                population[i]->draw(painter);
            //}
        }
    }
}

const QList<CVoiture *>& CGenetic::getVainqueurs(void) {
	return vainqueurs;
}

void CGenetic::calculScores(void) {
    int i;
    int nbAlive = TAILLE_POPULATION;
    QTime time;
    int timeElapsed = 0;
    int nbGagne=0;
    
    time.start();
    while(nbAlive != 0 && timeElapsed < MAX_TIME) {
        for(i=0;i<TAILLE_POPULATION;i++) {
            bool gagne;
            if(population[i]->isAlive()) {
                double angle = population[i]->getCurrentAngle();
                double inputs[NB_CAPTEUR+1];
                QPointF *posRoue = population[i]->getPosRoue();
                QPointF result;
                int nbDehors = 0;

                inputs[0] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[0], posRoue[2], result, angle);
                inputs[1] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[0], posRoue[1], result, angle + PI2);
                inputs[2] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[0], posRoue[3], result, angle + PI / 4);
                inputs[3] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[1], posRoue[3], result, angle);
                inputs[4] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[1], posRoue[0], result, angle + 3 * PI2);
                inputs[5] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[1], posRoue[2], result, angle + 7 * PI / 4);
                inputs[6] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[2], posRoue[3], result, angle + PI2);
                inputs[7] = CDistanceHelper::calculDistance(&circuits[currentCircuit], posRoue[3], posRoue[2], result, angle + 3 * PI2);
                inputs[8] = population[i]->getCurrentVitesse() * setup.getCoefVitesse();

                population[i]->setInputs(inputs);

                if(population[i]->move(timeElapsed, gagne)) {
                    nbDehors += CDistanceHelper::isDehors(&circuits[currentCircuit], posRoue[0]) ? 1 : 0;
                    nbDehors += CDistanceHelper::isDehors(&circuits[currentCircuit], posRoue[1]) ? 1 : 0;
                    nbDehors += CDistanceHelper::isDehors(&circuits[currentCircuit], posRoue[2]) ? 1 : 0;
                    nbDehors += CDistanceHelper::isDehors(&circuits[currentCircuit], posRoue[3]) ? 1 : 0;

					population[i]->setAlive(nbDehors < 2);
					nbAlive -= nbDehors < 2 ? 0 : 1;
				} else {
					nbAlive--;
				}

                nbGagne += gagne ? 1 : 0;
                population[i]->setVictoire(currentCircuit, gagne);
            } else {
                population[i]->move(timeElapsed, gagne);
            }
        }

        circuits[currentCircuit].setNbGagne(nbGagne);

        emit repaintRequested();
        msleep(1000 / 24);

        timeElapsed = time.elapsed();
    }
}

void CGenetic::onWCircuitDrawVoitures(QPainter *painter) {
    drawPopulation(painter);
}
