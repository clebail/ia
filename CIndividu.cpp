#include "CIndividu.h"

CIndividu::CIndividu(void) {
    score = 0;
}

int CIndividu::getScore(void) {
    return score;
}

void  CIndividu::setScore(int score) {
    this->score = score;
}
