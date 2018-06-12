#ifndef CINDIVIDU_H
#define CINDIVIDU_H

#include <QPainter>
#include "CGene.h"

class CIndividu {
public:
    CIndividu(void);
    int getScore(void);
    void setScore(int score);
	virtual ~CIndividu(void) {}
	virtual void init(void) = 0;
	virtual void mute(int idxGene) = 0;
	virtual void from(CIndividu *i1, CIndividu *i2, int seuil) = 0;
    virtual void draw(QPainter *painter) = 0;
protected:
    virtual CGene * getGene(int idx) = 0;
private:
    int score;
};

#endif //CINDIVIDU_H
