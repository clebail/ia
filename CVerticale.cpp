#include "CVerticale.h"

CVerticale::CVerticale(double x) {
    this->x = x;
}

QPointF CVerticale::croise(const CDroite& other) const {
    CDroite *o = (CDroite *)&other;
    CVerticale *v;
    if ((v = dynamic_cast<CVerticale *>(o)) != 0) {
        if(v->x == x) {
            return QPointF(x, 0);
        }

        return QPointF();
    }

    return QPointF(x, other.eval(x));
}

double CVerticale::eval(double) const {
    return x;
}

