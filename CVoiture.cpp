#include <QtDebug>
#include <math.h>
#include "CVoiture.h"

CVoiture::CVoiture(void) {
    score = 0;
    currentAngle = 0;
}

void CVoiture::init(void) {
    int i;

    for(i=0;i<NB_GENE;i++) {
        poids[i].init();
    }
}

int CVoiture::getScore(void) {
    return score;
}

void CVoiture::mute(int idxGene) {
     poids[idxGene].init();
}

void CVoiture::from(CVoiture *i1, CVoiture *i2, int seuil) {
    int i;
    CVoiture *src = i1;

    for(i=0;i<NB_GENE;i++) {
        if(i == seuil) {
            src = i2;
        }

        poids[i].from(src->getGene(i));
    }
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

    //calculDistance(posRoue[0], posRoue[2], currentAngle, painter, Qt::yellow);
    //calculDistance(posRoue[0], posRoue[1], PI / 2 + currentAngle, painter, Qt::yellow);
    //calculDistance(posRoue[0], posRoue[3], PI / 4 + currentAngle, painter, Qt::yellow);

    painter->setPen(QPen(Qt::red));
    painter->setBrush(QBrush(Qt::red));
    painter->drawEllipse(posRoue[1].x(), posRoue[1].y(), 3, 3);

    //calculDistance(posRoue[1], posRoue[3], currentAngle, painter, Qt::red);
    //calculDistance(posRoue[1], posRoue[0], 3 * PI / 2 + currentAngle, painter, Qt::red);
    //calculDistance(posRoue[1], posRoue[2], 7 * PI / 4 + currentAngle, painter, Qt::red);
    

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
    memcpy(this->inputs, inputs, NB_CAPTEUR * sizeof(double));
}

void CVoiture::move(void) {
    double vitesse;
    int sensX = posRoue[0].x() < posRoue[3].x() ? -1 : 1;
    int sensY = posRoue[0].y() < posRoue[3].y() ? -1 : 1;

    currentAngle = getAngle();
    vitesse = getVitesse();

    position.rx() += cos(currentAngle) * vitesse * sensX;
    position.ry() += sin(currentAngle) * vitesse * sensY;

    position.setX(CCircuit::normCoordonnees(position.x()));
    position.setY(CCircuit::normCoordonnees(position.y()));

    score += vitesse;

    calculPosRoue();
}

void CVoiture::setPosition(QPoint position) {
    this->position = position;
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

CCapteur * CVoiture::getGene(int idx) {
    return &poids[idx];
}

double CVoiture::getVitesse(void) {
    return transfert(0) * 10;
}

double CVoiture::getAngle(void) {
    double angle = normAngle(transfert(NB_CAPTEUR + 1) * 2 * PI);

    qDebug() << angle;

    return angle;
}

double CVoiture::transfert(int idxFirstGene) {
    double sigma = poids[idxFirstGene++].getValue();
    int i;
    
    for(i=0;i<NB_CAPTEUR;i++,idxFirstGene++) {
        sigma += inputs[i] * poids[idxFirstGene].getValue();
    }
    
    return 1 / (1 + exp(-sigma));
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
