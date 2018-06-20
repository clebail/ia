#include "CMarker.h"

CMarker::CMarker(const QPoint& p, pDepasse depasse) {
    this->p = p;
    this->depasse = depasse;
}

bool CMarker::isDepasse(const QPoint& p) {
   return (this->*depasse)(p);
}

bool CMarker::depasseHaut(const QPoint& p) {
    return false;
}

bool CMarker::depasseDroite(const QPoint& p) {
    return false;
}

bool CMarker::depasseBas(const QPoint& p) {
    return false;
}

bool CMarker::depasseGauche(const QPoint& p) {
    return false;
}
