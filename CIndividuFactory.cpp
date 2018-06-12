#include "CIndividuFactory.h"
#include "CVoiture.h"

CIndividu * CIndividuFactory::createIndividu(void) {
    return new CVoiture();
}

int CIndividuFactory::getTailleGenome(void) {
    return NB_GENE;
}

int CIndividuFactory::cmp(int score1, int score2) {
	return score2 < score1;
}

