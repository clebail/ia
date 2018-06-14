#include "CCircuit.h"

CCircuit::CCircuit(void) {
}

CCircuit::CCircuit(QPoint depart, QString imgResource) {
    this->depart = depart;
    
    image = QImage(imgResource);
}

const QPoint& CCircuit::getDepart(void) {
    return depart;
}

const QImage& CCircuit::getImage(void) {
    return image;
}

int CCircuit::normCoordonnees(int i) {
    if(i >= 500) {
        i = 500;
    }

    if(i < 0) {
        i = 0;
    }

    return i;
}

