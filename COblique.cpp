#include "COblique.h"
#include "CVerticale.h"

COblique::COblique(double a, double b) {
    this->a = a;
    this->b = b;
}

QPoint COblique::croise(const CDroite& other) const {
    CDroite *o = (CDroite *)&other;
    double x, y;

    if (dynamic_cast<CVerticale *>(o) != 0) {
        x = other.eval(0);
        return QPoint(x, eval(x));
    }else {
        COblique *oblique = dynamic_cast<COblique *>(o);
        x = (oblique->b - b) / (a - oblique->a);
        y = eval(x);

        return QPoint(x, y);
    }
}

double COblique::eval(double x) const {
    return a * x + b;
}
