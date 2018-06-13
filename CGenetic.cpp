#include <QtDebug>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "CGenetic.h"

void CGenetic::initPopulation(void) {
	int i;

    for(i=0;i<TAILLE_POPULATION;i++) {
		population[i] = new CVoiture();
		population[i]->init();
	}
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

double CGenetic::calculDistance(QPoint p, double angle, int sens) {
    bool fini = false;
    int x = p.x();
    int y = p.y();

    angle = abs(angle);
    if((angle > PI / 2 - 0.01 && angle < PI / 2 + 0.01) || (angle > 3 * PI / 2 - 0.01 && angle < 3 * PI / 2 + 0.01)) {
    } else {
    }

    return 0;
}

CVoiture * CGenetic::process(void) {
    int i = 0;
	
	srand(time(NULL));
		
	initPopulation();
    emit readyToCalculScore(false);
    
    do {
        triPopulation();
        croisePopuplation();

        emit readyToCalculScore(false);
    }while(++i != NOMBRE_GENERATION);
	
	return population[0];
}

void CGenetic::drawPopulation(QPainter *painter) {
    int i;

    for(i=0;i<TAILLE_POPULATION;i++) {
        population[i]->draw(painter);
    }
}

void CGenetic::setCircuit(CCircuit circuit) {
    int i;
    
    this->circuit = circuit;

    for(i=0;i<TAILLE_POPULATION;i++) {
        population[i]->setPosition(circuit.getDepart());
    }
}

void CGenetic::calculScores(void) {
    int i;
    
    for(i=0;i<TAILLE_POPULATION;i++) {
        double angle = population[i]->getCurrentAngle();
        double inputs[NB_CAPTEUR];
        QPoint *posRoue = population[i]->getPosRoue();

        inputs[0] = calculDistance(posRoue[0], angle, 1);
        inputs[1] = calculDistance(posRoue[0], angle - PI / 2, 1);
        inputs[2] = calculDistance(posRoue[1], angle, 1);
        inputs[3] = calculDistance(posRoue[1], angle + PI / 2, 1);
        inputs[4] = calculDistance(posRoue[2], angle, -1);
        inputs[5] = calculDistance(posRoue[2], angle - PI / 2, -1);
        inputs[6] = calculDistance(posRoue[3], angle, -1);
        inputs[7] = calculDistance(posRoue[3], angle + PI / 2, -1);

        population[i]->setInputs(inputs);

        //population[i]->move();
    }
}
