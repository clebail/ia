#include <QtDebug>
#include <iostream>
#include <string.h>
#include "commun.h"
#include "CVoiture.h"

#define TIME_DIV		100
#define MAX_SCORE       (100 + MAX_TIME / TIME_DIV)


QColor colors[NB_CIRCUIT+1] = {
    QColor(0, 0, 153),
    QColor(0, 0, 204),
    QColor(0, 17, 255),
    QColor(0, 85, 255),
    QColor(0, 153, 255),
    QColor(0, 221, 255),
    QColor(34, 255, 221),
    QColor(102, 255, 153),
    QColor(170, 255, 85),
    QColor(238, 255, 17),
    QColor(255, 204, 0),
    QColor(255, 119, 0),
    QColor(255, 34, 0),
};

CVoiture::CVoiture(void) : CBaseVoiture() {
    score = oldScore = 0;
    currentAngle = 0;
    currentVitesse = 0;
    champion = false;

    memset(victoires, 0, NB_CIRCUIT * sizeof(bool));
}

void CVoiture::setStartInfo(QPoint position, double angle, const QList<CDroite *>& markers, int idx) {
    CBaseVoiture::setStartInfo(position, angle);

    this->markers = markers;
    this->idx = idx;
    oldScore = score;
    score = 0;
    currentMarkerIdx = 0;
    vMax = 0;
    asColor = false;
}

void CVoiture::init(void) {
	int i;
	
    for(i=0;i<NB_NEURONE;i++) {
        ns[i]->initGenes();
        ns[i]->initSeuil();
        ns[i]->initPente();

        if(i == NV) {
            static_cast<CNeuroneVitesse *>(ns[i])->initCoefVitesse();
        }
    }
}

int CVoiture::getScore(void) {
    return score;
}

void CVoiture::from(CVoiture *v1, CVoiture *v2) {
	int i;
	for(i=0;i<NB_NEURONE;i++) {
		int seuil = rand() % ns[i]->getNbGene();
		
		ns[i]->from(*v1->ns[i], *v2->ns[i], seuil);	
		ns[i]->mute(rand() % ns[i]->getNbGene());
	}
    
    score = 0;
    champion = false;
    memset(victoires, 0, NB_CIRCUIT * sizeof(bool));
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

double CVoiture::getVMax(void) {
    return vMax;
}

double CVoiture::getVitesse(void) {
    double v = CBaseVoiture::getVitesse();

    vMax = qMax(vMax, v);

    return v;
}

QBrush CVoiture::getBrush(void) {
    if(!asColor) {
        int nbVictoire = 0;
        int i;
        for(i=0;i<NB_CIRCUIT;i++) {
            nbVictoire += (victoires[i] ? 1 : 0);
        }
        color = colors[nbVictoire];
        asColor = true;
    }

    color.setAlpha(alpha);
    return QBrush(color);
}

