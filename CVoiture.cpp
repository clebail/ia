#include <QtDebug>
#include <iostream>
#include <math.h>
#include "commun.h"
#include "CVoiture.h"

CVoiture::CVoiture(void) : nVitesse(NB_CAPTEUR+3), nAngle(NB_CAPTEUR+3) {
    score = 0;
    currentAngle = 0;
    currentVitesse = 0;
}

void CVoiture::init(void) {
    nVitesse.init();
    nAngle.init();
}

int CVoiture::getScore(void) {
    return score;
}

void CVoiture::draw(QPainter *painter) {
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

void CVoiture::setInputs(double *inputs) {
    nVitesse.setInputs(inputs);
    nAngle.setInputs(inputs);
}

bool CVoiture::move(int timeElapsed) {
    currentAngle += getAngle();

    currentVitesse = getVitesse();
    if(currentVitesse < 1) {
		score = 0;
		alive = false;

        return false;
	}
	
    realMove(currentVitesse, currentAngle);

    if(markers.at(currentMarkerIdx).isDepasse(position)) {
        score = (++currentMarkerIdx) * 100 / markers.size();

        if(score == 100) {
            score += (MAX_TIME - timeElapsed) / 1000;
            alive = false;

            return false;
        }
    }else if(currentMarkerIdx > 0) {
        if(markers.at(currentMarkerIdx - 1).isDepasseInv(position)) {
            score = 0;
            alive = false;

            return false;
        }
    }else if(currentMarkerIdx == 0) {
        if(markers.at(markers.size() - 1).isDepasseInv(position)) {
            score = 0;
            alive = false;

            return false;
        }
    }
    
    return true;
}

double CVoiture::realMove(double vitesse, double angle) {
	double dx, dy;
	int sensX = posRoue[0].x() < posRoue[3].x() ? -1 : 1;
    int sensY = posRoue[0].y() < posRoue[3].y() ? -1 : 1;
	
	currentAngle = angle;
	dx = fabs(cos(angle) * vitesse) * sensX;
	dy = fabs(sin(angle) * vitesse) * sensY;
	
	position.rx() += dx;
    position.ry() += dy;

    position.setX(position.x());
    position.setY(position.y());
	
	calculPosRoue();
	
	return sqrt(dx*dx + dy*dy);
}

void CVoiture::setStartInfo(QPoint position, double angle, const QList<CMarker>& markers) {
    this->position = position;
    this->markers = markers;
    currentAngle = angle;
    score = 0;
    currentMarkerIdx = 0;

    calculPosRoue();
}

const QPoint& CVoiture::getPosition(void) {
    return position;
}

double CVoiture::getCurrentAngle(void) {
    return currentAngle;
}

double CVoiture::getCurrentVitesse(void) {
    return currentVitesse;
}

QPoint * CVoiture::getPosRoue(void) {
    return posRoue;
}

void CVoiture::setAlive(bool alive) {
    this->alive = alive;
}

bool CVoiture::isAlive(void) {
    return alive;
}

void CVoiture::from(CVoiture *v1, CVoiture *v2, int seuilVitesse, int seuilAngle) {
    nVitesse.from(v1->nVitesse, v2->nVitesse, seuilVitesse);
    nAngle.from(v1->nAngle, v2->nVitesse, seuilAngle);

    if(rand() % 10 < 5) {
        nVitesse.mute(rand() % nVitesse.getNbGene());
    }

    if(rand() % 10 < 5) {
        nAngle.mute(rand() % nAngle.getNbGene());
    }
    
    score = 0;
}

double CVoiture::getVitesse(void) {
    return nVitesse.eval(100) * 10;
}

double CVoiture::getAngle(void) {
    double angle = nAngle.eval(100) * PI - PI2;

    return angle;
}

void CVoiture::calculPosRoue(void) {
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

double CVoiture::normAngle(double angle) {
    while(angle < 0) {
        angle += PI;
    }
    while(angle > 2 * PI) {
        angle -= PI;
    }

    return angle;
}
