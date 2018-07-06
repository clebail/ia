#include <math.h>
#include "CDistanceHelper.h"
#include "commun.h"

double CDistanceHelper::calculDistance(CCircuit *circuit, QPointF p, QPointF oppose, QPointF &result, double angle) {
    int x = p.x();
    int y = p.y();
    int dx, dy;

    angle = CDistanceHelper::normAngle(angle);

    if((angle > PI2 - 0.01 && angle < PI2 + 0.01) || (angle > 3 * PI2 - 0.01 && angle < 3 * PI2 + 0.01)) {
        int sens = oppose.y() > p.y() ? -1 : 1;
        bool fini = CDistanceHelper::isDehors(circuit, QPointF(x, y));

        while(!fini) {
            y += sens;

            fini = CDistanceHelper::isDehors(circuit, QPointF(x, y));
        }
    } else {
        double a = tan(angle);
        double b = y - a * x;
        int sens = oppose.x() > p.x() ? -1 : 1;
        bool fini = CDistanceHelper::isDehors(circuit, QPointF(x, y));

        while(!fini) {
            x += sens;
            y = a * x + b;

            fini = CDistanceHelper::isDehors(circuit, QPointF(x, y));
        }
    }

    circuit->normCoordonnees(x, y);

    result = QPointF(x, y);

    dx = abs(p.x() - x);
    dy = abs(p.y() - y);

    return sqrt(dx * dx + dy * dy);
}

bool CDistanceHelper::isDehors(CCircuit *circuit, const QPointF& p) {
    QImage img = circuit->getImage();
    QPoint pe;

    if(p.x() < 0 || p.y() < 0 || p.x() >= img.width() || p.y() >= img.height()) {
        return true;
    }

    pe = p.toPoint();
    circuit->normCoordonnees(pe);

    return img.pixel(pe) == 0xFF000000;
}

double CDistanceHelper::normAngle(double angle) {
    while(angle < 0) {
        angle += PI;
    }
    while(angle > 2 * PI) {
        angle -= PI;
    }

    return angle;
}
