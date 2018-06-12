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

