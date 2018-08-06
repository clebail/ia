#include "CVerticale.h"

CVerticale::CVerticale(double x) {
    this->x = x;
}

QPoint CVerticale::croise(const CDroite& other) const {
    CDroite *o = (CDroite *)&other;
    CVerticale *v;
    if ((v = dynamic_cast<CVerticale *>(o)) != 0) {
        if(v->x == x) {
            return QPoint(x, 0);
        }

        return QPoint();
    }

    return QPoint(x, other.eval(x));
}

double CVerticale::eval(double) const {
    return x;
}

