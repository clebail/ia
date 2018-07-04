#include <math.h>
#include "CVehicule.h"

CVehicule::~CVehicule(void) {

}

void CVehicule::draw(QPainter *painter) {
    QRect rect(-(WIDTH / 2), -(HEIGHT / 2), WIDTH, HEIGHT);

    painter->save();
    painter->translate(position.x(), position.y());
    painter->rotate(currentAngle * 180 / PI);

    painter->setPen(QPen(Qt::blue));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(rect);

    painter->restore();

    painter->setPen(QPen(Qt::yellow));
    painter->setBrush(QBrush(Qt::yellow));
    painter->drawEllipse(posRoue[0].x(), posRoue[0].y(), 3, 3);

    painter->setPen(QPen(Qt::yellow));
    painter->setBrush(QBrush(Qt::yellow));
    painter->drawEllipse(posRoue[1].x(), posRoue[1].y(), 3, 3);

    painter->setPen(QPen(Qt::red));
    painter->setBrush(QBrush(Qt::red));
    painter->drawEllipse(posRoue[2].x(), posRoue[2].y(), 3, 3);

    painter->setPen(QPen(Qt::red));
    painter->setBrush(QBrush(Qt::red));
    painter->drawEllipse(posRoue[3].x(), posRoue[3].y(), 3, 3);
}

bool CVehicule::move(int) {
    double dx, dy;
    int sensX = posRoue[0].x() < posRoue[3].x() ? -1 : 1;
    int sensY = posRoue[0].y() < posRoue[3].y() ? -1 : 1;

    currentAngle += getAngle();
    currentVitesse = getVitesse();

    dx = fabs(cos(currentAngle) * currentVitesse) * sensX;
    dy = fabs(sin(currentAngle) * currentVitesse) * sensY;

    position.rx() += dx;
    position.ry() += dy;

    position.setX(position.x());
    position.setY(position.y());

    calculPosRoue();

    return true;
}

const QPoint& CVehicule::getPosition(void) {
    return position;
}

double CVehicule::getCurrentAngle(void) {
    return currentAngle;
}

double CVehicule::getCurrentVitesse(void) {
    return currentVitesse;
}

QPoint * CVehicule::getPosRoue(void) {
    return posRoue;
}

void CVehicule::calculPosRoue(void) {
    double aP = currentAngle + ANGLE;
    double aM = currentAngle - ANGLE;
    double xP = cos(aP) * HYPO;
    double xM = cos(aM) * HYPO;
    double yP = sin(aP) * HYPO;
    double yM = sin(aM) * HYPO;

    posRoue[0] = QPoint(position.x() - xP, position.y() - yP);
    posRoue[1] = QPoint(position.x() - xM, position.y() - yM);
    posRoue[2] = QPoint(position.x() + xM, position.y() + yM);
    posRoue[3] = QPoint(position.x() + xP, position.y() + yP);
}
