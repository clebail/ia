#include "CVoiture.h"

void CVoiture::init(void) {
    int i;

    for(i=0;i<NB_GENE;i++) {
        capteurs[i].init();
    }
}

void CVoiture::mute(int idxGene) {
     capteurs[idxGene].init();
}

void CVoiture::from(CIndividu *i1, CIndividu *i2, int seuil) {
    int i;
    CVoiture *src = static_cast<CVoiture *>(i1);

    for(i=0;i<NB_GENE;i++) {
        if(i == seuil) {
            src = static_cast<CVoiture *>(i2);
        }

        capteurs[i].from(src->getGene(i));
    }
}

void CVoiture::draw(QPainter *painter) {

}

CGene * CVoiture::getGene(int idx) {
    return &capteurs[idx];
}
