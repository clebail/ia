#ifndef CGENETIC_H
#define CGENETIC_H

#include <QObject>
#include <QPainter>
#include "CIndividu.h"

#define TAILLE_POPULATION					100
#define NOMBRE_GENERATION					1000

class CGenetic : public QObject {
    Q_OBJECT
private:
	CIndividu *population[TAILLE_POPULATION];
	
	void initPopulation(void);
	void triPopulation(void);
    void croisePopuplation(void);
	void croiseIndividus(int i1, int i2, int ir, int seuil);
public:
	CIndividu * process(void);
    void drawIndividu(int idx, QPainter *painter);
signals:
    void ready(void);
};

#endif //CGENETIC_H
