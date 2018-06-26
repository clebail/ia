#include <QtDebug>
#include <iostream>
#include <math.h>
#include "commun.h"
#include "CVoiture.h"

CVoiture::CVoiture(void) : nVitesse(NB_CAPTEUR+1), nAngle(NB_CAPTEUR+1) {
    score = 0;
    currentAngle = 0;
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

    /*calculDistance(posRoue[0], posRoue[2], currentAngle, painter, Qt::yellow);
    calculDistance(posRoue[0], posRoue[1], PI / 2 + currentAngle, painter, Qt::yellow);
    calculDistance(posRoue[0], posRoue[3], PI / 4 + currentAngle, painter, Qt::yellow);*/

    painter->setPen(QPen(Qt::red));
    painter->setBrush(QBrush(Qt::red));
    painter->drawEllipse(posRoue[1].x(), posRoue[1].y(), 3, 3);

    /*calculDistance(posRoue[1], posRoue[3], currentAngle, painter, Qt::red);
    calculDistance(posRoue[1], posRoue[0], 3 * PI / 2 + currentAngle, painter, Qt::red);
    calculDistance(posRoue[1], posRoue[2], 7 * PI / 4 + currentAngle, painter, Qt::red);*/
    

    painter->setPen(QPen(Qt::green));
    painter->setBrush(QBrush(Qt::green));
    painter->drawEllipse(posRoue[2].x(), posRoue[2].y(), 3, 3);

    //calculDistance(posRoue[2], posRoue[3], PI / 2 + currentAngle, painter, Qt::green);

    painter->setPen(QPen(Qt::cyan));
    painter->setBrush(QBrush(Qt::cyan));
    painter->drawEllipse(posRoue[3].x(), posRoue[3].y(), 3, 3);

    //calculDistance(posRoue[3], posRoue[2], 3 * PI / 2 + currentAngle, painter, Qt::cyan);
}

void CVoiture::setInputs(double *inputs) {
    nVitesse.setInputs(inputs);
    nAngle.setInputs(inputs);
}

void CVoiture::move(void) {
    double vitesse;

	currentAngle += getAngle();
	currentAngle = normAngle(currentAngle);

    vitesse = getVitesse();
	if(vitesse < 1) {
		score = 0;
		alive = false;
		return;
	}
	
    realMove(vitesse, currentAngle);

	//qDebug() << currentAngle << currentMarkerIdx << markers.at(currentMarkerIdx).getPosition() << position << markers.at(currentMarkerIdx).isDepasse(position);
	
    if(markers.at(currentMarkerIdx).isDepasse(position)) {
        score = (++currentMarkerIdx) * 100 / markers.size();

        if(score == 100) {
            score = 1000;
            alive = false;
        }
    }
    
    //std::cout << "Score : " << QString::number(score).toStdString() << std::endl;
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

    position.setX(CCircuit::normCoordonnees(position.x()));
    position.setY(CCircuit::normCoordonnees(position.y()));
	
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
    return nVitesse.eval(100) * 20;
}

double CVoiture::getAngle(void) {
    double angle = nAngle.eval(100) * PI / 2 - (PI / 4);

    return angle;
}

void CVoiture::calculPosRoue(void) {
    double aP = currentAngle + ANGLE;
    double aM = currentAngle - ANGLE;
    double xP = cos(aP) * HYPO;
    double xM = cos(aM) * HYPO;
    double yP = sin(aP) * HYPO;
    double yM = sin(aM) * HYPO;

    posRoue[0] = QPoint(CCircuit::normCoordonnees(position.x() - xP), CCircuit::normCoordonnees(position.y() - yP));
    posRoue[1] = QPoint(CCircuit::normCoordonnees(position.x() - xM), CCircuit::normCoordonnees(position.y() - yM));
    posRoue[2] = QPoint(CCircuit::normCoordonnees(position.x() + xM), CCircuit::normCoordonnees(position.y() + yM));
    posRoue[3] = QPoint(CCircuit::normCoordonnees(position.x() + xP), CCircuit::normCoordonnees(position.y() + yP));
}

double CVoiture::calculDistance(QPoint p, QPoint oppose, double angle, QPainter *painter, QColor color) {
    bool fini = false;
    int x = p.x();
    int y = p.y();
    
    painter->setPen(QPen(color));

    angle = normAngle(angle);
    
    if((angle > PI2 - 0.01 && angle < PI2 + 0.01) || (angle > 3 * PI2 - 0.01 && angle < 3 * PI2 + 0.01)) {
        int sens = oppose.y() > p.y() ? -1 : 1;
        
        while(!fini) {
            painter->drawPoint(QPoint(x, y));

            y += sens;
            fini = y <= 0 || y >= 500;
        }
    } else {
        double a = tan(angle);
        double b = y - a * x;
        int sens = oppose.x() > p.x() ? -1 : 1;
        
        while(!fini) {
            painter->drawPoint(QPoint(x, y));

            x += sens;
            y = a * x + b;
            fini = y <= 0 || y >= 500 || x <= 0 || x >= 500;
        }
    }

    return 0;
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
