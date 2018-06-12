#ifndef CINDIVIDUFACTORY_H
#define CINDIVIDUFACTORY_H

#include "CIndividu.h"

class CIndividuFactory {
public:
	static CIndividu * createIndividu(void);
	static int getTailleGenome(void);
	static int cmp(int score1, int score2);
};

#endif //CINDIVIDUFACTORY_H
