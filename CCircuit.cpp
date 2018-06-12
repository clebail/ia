#include "CCircuit.h"

CCircuit::CCircuit(void) {
}

CCircuit::CCircuit(QPoint depart, QString imgResource) {
    this->depart = depart;
    this->imgResource = imgResource;
}

const QPoint& CCircuit::getDepart(void) {
    return depart;
}

const QString& CCircuit::getImgResource(void) {
    return imgResource;
}
