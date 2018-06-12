#include <iostream>
#include <stdlib.h>
#include <time.h> 
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

CVoiture * CGenetic::process(void) {
    int i = 0;
	
	srand(time(NULL));
		
	initPopulation();
    emit readyToCalculScore();
    
    do {
        triPopulation();
        croisePopuplation();

        emit readyToCalculScore();
    }while(++i == NOMBRE_GENERATION);
	
	return population[0];
}

void CGenetic::drawIndividu(int idx, QPainter *painter) {
    population[idx]->draw(painter);
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
        population[i]->move();
    }
}
