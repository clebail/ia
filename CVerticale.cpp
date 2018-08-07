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

QLine CVerticale::getLine(const QSize& size) const {
    return QLine(QPoint(x, 0), QPoint(x, size.height()-1));
}

QString CVerticale::toString(void) const {
    return QString("x = %1").arg(x);
}

