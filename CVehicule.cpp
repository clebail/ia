#include <math.h>
#include "CVehicule.h"

CVehicule::~CVehicule(void) {
    alpha = 255;
}

void CVehicule::draw(QPainter *painter) {
    QRect rect(-(WIDTH / 2), -(HEIGHT / 2), WIDTH, HEIGHT);
    QColor yellow = QColor(255, 255, 0, alpha);
    QColor red = QColor(255, 0, 0, alpha);
    QColor blue = QColor(0, 0, 255, alpha);


    painter->save();
    painter->translate(position.x(), position.y());
    painter->rotate(currentAngle * 180 / PI);

    painter->setPen(QPen(blue));
    painter->setBrush(getBrush());
    painter->drawRect(rect);

    painter->restore();

    painter->setPen(QPen(yellow));
    painter->setBrush(QBrush(yellow));
    painter->drawEllipse(posRoue[0].x(), posRoue[0].y(), 3, 3);

    painter->setPen(QPen(yellow));
    painter->setBrush(QBrush(yellow));
    painter->drawEllipse(posRoue[1].x(), posRoue[1].y(), 3, 3);

    painter->setPen(QPen(red));
    painter->setBrush(QBrush(red));
    painter->drawEllipse(posRoue[2].x(), posRoue[2].y(), 3, 3);

    painter->setPen(QPen(red));
    painter->setBrush(QBrush(red));
    painter->drawEllipse(posRoue[3].x(), posRoue[3].y(), 3, 3);
}

bool CVehicule::move(int, bool &) {
    double dx, dy;

    currentAngle += getAngle();
    currentVitesse = getVitesse();
	
	if(currentVitesse != 0) {
		dx = cos(currentAngle) * currentVitesse;
		dy = sin(currentAngle) * currentVitesse;

		position.rx() += dx;
		position.ry() += dy;

		calculPosRoue();
		
		return true;
	}
	
	return false;
}

const QPointF& CVehicule::getPosition(void) {
    return position;
}

double CVehicule::getCurrentAngle(void) {
    return currentAngle;
}

double CVehicule::getCurrentVitesse(void) {
    return currentVitesse;
}

QPointF * CVehicule::getPosRoue(void) {
    return posRoue;
}

void CVehicule::calculPosRoue(void) {
    double aP = currentAngle + ANGLE;
    double aM = currentAngle - ANGLE;
    double xP = cos(aP) * HYPO;
    double xM = cos(aM) * HYPO;
    double yP = sin(aP) * HYPO;
    double yM = sin(aM) * HYPO;

    posRoue[3] = QPointF(position.x() - xP, position.y() - yP);
    posRoue[2] = QPointF(position.x() - xM, position.y() - yM);
    posRoue[1] = QPointF(position.x() + xM, position.y() + yM);
    posRoue[0] = QPointF(position.x() + xP, position.y() + yP);
}

QBrush CVehicule::getBrush(void) {
    return QBrush(Qt::blue);
}
