#include <math.h>
#include "COblique.h"
#include "CVerticale.h"

COblique::COblique(double a, double b) {
    this->a = a;
    this->b = b;
}

QPointF COblique::croise(const CDroite& other) const {
    CDroite *o = (CDroite *)&other;
    double x, y;

    if (dynamic_cast<CVerticale *>(o) != 0) {
        x = other.eval(0);
        return QPointF(x, eval(x));
    }else {
        COblique *oblique = dynamic_cast<COblique *>(o);
        x = (oblique->b - b) / (a - oblique->a);
        y = eval(x);

        return QPointF(x, y);
    }
}

double COblique::eval(double x) const {
    return a * x + b;
}

QLine COblique::getLine(const QSize& size) const {
    double x1=0;
    double x2=size.width() - 1;
    double y1 = eval(x1);
    double y2 = eval(x2);

    if(y1 < 0) {
        y1 = 0;
        x1 = (y1 - b) / a;
    }

    if(y1 >= size.height()) {
        y1 =size. height() - 1;
        x1 = (y1 - b) / a;
    }

    if(y2 < 0) {
        y2 = 0;
        x2 = (y2 - b) / a;
    }

    if(y2 >= size.height()) {
        y2 = size.height() - 1;
        x2 = (y2 - b) / a;
    }

    return QLine(QPoint(x1, y1), QPoint(x2, y2));
}


QString COblique::toString(void) const {
    return QString("y = %1x %2 %3").arg(a).arg(b<0 ? "-" : "+").arg(abs(b));
}
