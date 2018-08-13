#include <QtDebug>
#include "CVerdict.h"
#include "commun.h"
#include "CDistanceHelper.h"

CVerdict::CVerdict(CWCircuit *wCircuit, QString circutResource, double coefVitesse, QString jSon) {
    parseVoitures(jSon);

    circuit = CCircuit(QPoint(387, 787), 0, circutResource, QPoint(25, 50));
    this->wCircuit = wCircuit;
    this->coefVitesse = coefVitesse;

    this->wCircuit->setCircuit(&circuit);

    connect(this->wCircuit, SIGNAL(drawVoitures(QPainter*, double, double)), this, SLOT(onWCircuitDrawVoitures(QPainter*, double, double)));
}

CVerdict::~CVerdict(void) {
    int i;

    for(i=0;i<voitures.size();i++) {
        delete voitures.at(i);
    }
}

void CVerdict::run(void) {
    int i;

    for(i=0;i<voitures.size();i++) {
        voitures.at(i)->setStartInfo(QPoint(387, 787), 0);
        voitures.at(i)->setAlive(true);
    }

    do {
		i = 0;
        while(i<voitures.size()) {
            if(voitures.at(i)->isAlive()) {
                double angle = voitures.at(i)->getCurrentAngle();
                double inputs[NB_CAPTEUR+1];
                QPointF *posRoue = voitures.at(i)->getPosRoue();
                QPointF result;
                int nbDehors = 0;
                bool gagne;
                QPointF devant = QPointF((posRoue[0].x() + posRoue[1].x()) / 2, (posRoue[0].y() + posRoue[1].y()) / 2);
                QPointF derriere = QPointF((posRoue[2].x() + posRoue[3].x()) / 2, (posRoue[2].y() + posRoue[3].y()) / 2);

                inputs[0] = CDistanceHelper::calculDistance(&circuit, posRoue[0], posRoue[2], result, angle);
                inputs[1] = CDistanceHelper::calculDistance(&circuit, posRoue[0], posRoue[1], result, angle + PI2);
                inputs[2] = CDistanceHelper::calculDistance(&circuit, posRoue[0], posRoue[3], result, angle + PI / 4);
                inputs[3] = CDistanceHelper::calculDistance(&circuit, posRoue[1], posRoue[3], result, angle);
                inputs[4] = CDistanceHelper::calculDistance(&circuit, posRoue[1], posRoue[0], result, angle + 3 * PI2);
                inputs[5] = CDistanceHelper::calculDistance(&circuit, posRoue[1], posRoue[2], result, angle + 7 * PI / 4);
                inputs[6] = CDistanceHelper::calculDistance(&circuit, posRoue[2], posRoue[3], result, angle + PI2);
                inputs[7] = CDistanceHelper::calculDistance(&circuit, posRoue[3], posRoue[2], result, angle + 3 * PI2);
                inputs[8] = CDistanceHelper::calculDistance(&circuit, devant, derriere, result, angle);
                inputs[9] = voitures.at(i)->getCurrentVitesse() * voitures.at(i)->getCoefVitesse();

                voitures.at(i)->setInputs(inputs);

                if(voitures.at(i)->move(0, gagne)) {
                    nbDehors += CDistanceHelper::isDehors(&circuit, posRoue[0]) ? 1 : 0;
                    nbDehors += CDistanceHelper::isDehors(&circuit, posRoue[1]) ? 1 : 0;
                    nbDehors += CDistanceHelper::isDehors(&circuit, posRoue[2]) ? 1 : 0;
                    nbDehors += CDistanceHelper::isDehors(&circuit, posRoue[3]) ? 1 : 0;

                    if(nbDehors >= 2) {
						voitures.removeAt(i);	
					} else {
						i++;
					}
                } else {
                    voitures.removeAt(i);
                }
            } else {
				voitures.removeAt(i);
			}
        }

        this->wCircuit->setNbVoiture(voitures.size());

        emit repaintRequested(voitures.at(0)->getPosition());
        msleep(1000 / STEP_BY_SECOND);
    }while(voitures.size());
}

void CVerdict::parseVoitures(QString jSon) {
    struct json_object *jObj = 0;
    struct json_tokener *tok = json_tokener_new();
    enum json_tokener_error jerr;

    do {
        jObj = json_tokener_parse_ex(tok, jSon.toAscii().data(), jSon.size());
    }while((jerr = json_tokener_get_error(tok)) == json_tokener_continue);

    if(jerr == json_tokener_success) {
        if(json_object_get_type(jObj) == json_type_array) {
            int len = json_object_array_length(jObj);
            int i;

            for(i=0;i<len;i++) {
                json_object *val = json_object_array_get_idx(jObj, i);

                voitures.append(CVerdictVoiture::fronJSon(val));
            }
        } else {
            qCritical() << "Impossible de créer les voitures, l'objet n'est pas un tableau";
        }
    } else {
        qCritical() << QString(json_tokener_error_desc(jerr));
    }
}

void CVerdict::onWCircuitDrawVoitures(QPainter *painter, double dx, double dy) {
    int i;

    for(i=0;i<voitures.size();i++) {
        voitures.at(i)->draw(painter, dx, dy);
    }
}
