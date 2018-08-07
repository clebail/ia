#include <QtDebug>
#include <iostream>
#include <math.h>
#include <string.h>
#include "commun.h"
#include "CVoiture.h"

#define TIME_DIV		100
#define MAX_SCORE       (100 + MAX_TIME / TIME_DIV)
#define V_MAX			60.0
#define A_MAX			(PI / 10.0)
#define NV				0
#define NAP				1
#define NAM				2

CVoiture::CVoiture(void) : CVehicule() {
	int i;
    score = oldScore = 0;
    currentAngle = 0;
    currentVitesse = 0;

	for(i=0;i<NB_NEURONE;i++) {
        ns[i] = new CNeurone(NB_CAPTEUR+(i == 0 ? 2 : 1));
	}
    champion = false;

    memset(&victoires, 0, NB_CIRCUIT * sizeof(bool));
}

CVoiture::~CVoiture(void) {
	int i;
	
    for(i=0;i<NB_NEURONE;i++) {
		delete ns[i];
	}
}

void CVoiture::init(void) {
	int i;
	
    for(i=0;i<NB_NEURONE;i++) {
		ns[i]->init();
	}
}

int CVoiture::getScore(void) {
    return score;
}

void CVoiture::setInputs(double *inputs) {
	int i;
	
    for(i=0;i<NB_NEURONE;i++) {
		ns[i]->setInputs(inputs);
	}
}

void CVoiture::setStartInfo(QPoint position, double angle, const QList<CDroite *>& markers, int idx) {
    this->position = position;
    this->markers = markers;
    this->idx = idx;
    currentAngle = angle;
    oldScore = score;
    score = 0;
    currentMarkerIdx = 0;
    alpha = 255;

    calculPosRoue();
}

void CVoiture::setAlive(bool alive) {
    this->alive = alive;
    alpha = alive ? 255 : ALPHA;
}

bool CVoiture::isAlive(void) {
    return alive;
}

void CVoiture::from(CVoiture *v1, CVoiture *v2) {
	int i;
	for(i=0;i<NB_NEURONE;i++) {
		int seuil = rand() % ns[i]->getNbGene();
		
		ns[i]->from(*v1->ns[i], *v2->ns[i], seuil);	
		ns[i]->mute(rand() % ns[i]->getNbGene());
	}
    
    score = 0;
    alpha = 255;
    champion = false;
    memset(&victoires, 0, NB_CIRCUIT * sizeof(bool));
}

bool CVoiture::move(int timeElapsed, bool &gagne) {
    gagne = false;
    int offset = champion ? 2000 : oldScore / 5;
	QPointF orig = position;
	
	if(alive && CVehicule::move(timeElapsed, gagne)) {
		CDroite *d = CDroite::create(orig, position);
		QPointF croise = markers.at(currentMarkerIdx)->croise(*d);
		QRectF r(orig, position);
        r = r.normalized();
        r.adjust(-0.1, -0.1, 0.1, 0.1);
		
        //qDebug() << idx << orig << position << markers.at(currentMarkerIdx)->toString() << croise << r.contains(croise) << r;
		
        while(r.contains(croise)) {
            score = (++currentMarkerIdx) * 100 / markers.size();

            if(score == 100) {
                score += (MAX_TIME - timeElapsed) / TIME_DIV;
                alive = false;
                gagne = true;
                alpha = ALPHA;
                score += offset;

                delete d;

                return false;
            }

            croise = markers.at(currentMarkerIdx)->croise(*d);
        }

        delete d;

        return true;
    }

    alive = false;
	alpha = ALPHA;
    
    return false;
}

void CVoiture::setVictoire(int numCircuit, bool victoire) {
    victoires[numCircuit] = victoire;
}

void CVoiture::setChampion(bool champion) {
    this->champion = champion;
}

bool CVoiture::isVainqueur(int numCircuit) {
    return victoires[numCircuit];
}

QString CVoiture::serialize(void) {
	int i;
	QString ret = "[";
	QString s = "";
	
	for(i=0;i<NB_NEURONE;i++) {
		ret += s + ns[i]->serialize();
		s = ",\r\n";
	}
	
	ret += "]";
	
	return ret;
}

double CVoiture::getVitesse(void) {
    double a = ns[NV]->eval(0.01);
	double v = currentVitesse;
	
    if(a >= 0.5) {
        if(v < V_MAX) {
            v++;
        }
    }else if(v > 0) {
        v--;
    }
	
    return v;
}

double CVoiture::getAngle(void) {
	double vitesse = currentVitesse - 1;
    double a1 = ns[NAP]->eval(0.01);
    double a2 = ns[NAM]->eval(0.01);
	double eXp = exp((vitesse - V_MAX/2.0) * (1.0 / V_MAX * 10.0));
    double coef = (-eXp / (eXp + 1) + 1) * 0.5 + 0.5;
    double angle = currentAngle + coef * A_MAX * (a1 >= 0.5 && a2 < 0.5 ? 1 : a2 >= 0.5 && a1 < 0.5 ? -1 : 0);

    return angle;
}

QBrush CVoiture::getBrush(void) {
    if(champion) {
        return QBrush(QColor(255, 255, 255, alpha));
    }

    int r = qMax(0, qMin(255, oldScore * 50 / MAX_SCORE));
    int v = qMax(0, qMin(255, oldScore * 100 / MAX_SCORE));
    int b = qMin(255, qMax(0, 255 - MAX_SCORE + oldScore));

    return QBrush(QColor(r, v, b, alpha));
}

