#include <QtDebug>
#include <string.h>
#include <math.h>
#include "CNeurone.h"

CNeurone::CNeurone(int nbGene) {
    this->nbGene = nbGene;
    genes = new CCapteur[nbGene];
    inputs = new double[nbGene-1];
}

CNeurone::~CNeurone(void) {
    delete[] genes;
    delete[] inputs;
}

void CNeurone::setInputs(double *inputs) {
    memcpy(this->inputs, inputs, (nbGene-1)*sizeof(double));
}

double CNeurone::eval(double a) {
    double sigma = genes[0].getValue();
	double s = 0;
    int i;

    for(i=1;i<nbGene;i++) {
        sigma += inputs[i-1] * genes[i].getValue();
		s += inputs[i-1];
    }

    double eXp = exp(a * sigma);
	
	return eXp / (eXp + 1);
}

int CNeurone::getNbGene(void) {
    return nbGene;
}

void CNeurone::from(const CNeurone& n1, const CNeurone& n2, int seuil) {
    int i;
    CNeurone *src = (CNeurone *)&n1;

    for(i=0;i<nbGene;i++) {
        if(i == seuil) {
            src = (CNeurone *)&n2;
        }

        genes[i].from(&src->genes[i]);
    }

    if(rand() % 2 > 0.5) {
        this->seuil = n1.seuil;
    }else {
        this->seuil = n2.seuil;
    }

    if(rand() % 2 > 0.5) {
        this->pente = n1.pente;
    }else {
        this->pente = n2.pente;
    }
}

void CNeurone::mute(int idx) {
    if(idx >= 0 && idx < nbGene) {
        genes[idx].init();
    }

    if(rand() % 2 > 0.5) {
        initSeuil();
    }

    if(rand() % 2 > 0.5) {
        initPente();
    }
}

void CNeurone::initGenes(void) {
    int i;

    for(i=0;i<nbGene;i++) {
        genes[i].init();
    }
}

void CNeurone::initSeuil(void) {
    seuil = ((double)(rand() % 801 + 100)) / 1000.0;
}

void CNeurone::initPente(void) {
    pente = ((double)(rand() % 10000 + 1)) / 10000.0;
}

QString CNeurone::serialize(void) {
    QString ret = "{ "+serializeSimples()+", "+serializeGenes()+ " }";

    return ret;
}

void CNeurone::setJSonGenes(json_object *jObj) {
    if(json_object_get_type(jObj) == json_type_array) {
        int len = json_object_array_length(jObj);
        int i;

        if(len == nbGene) {
            for(i=0;i<len;i++) {
                json_object *val = json_object_array_get_idx(jObj, i);
                genes[i] = CCapteur(json_object_get_double(val));
            }
        } else {
            qCritical() << "Impossible de créer les genes, le tableau n'a pas le bon nombre d'élément";
        }
    } else {
        qCritical() << "Impossible de créer les neurones, l'objet n'est pas un tableau";
    }
}

double CNeurone::getSeuil(void) {
    return seuil;
}

void CNeurone::setSeuil(double seuil) {
    this->seuil = seuil;
}

double CNeurone::getPente(void) {
    return pente;
}

void CNeurone::setPente(double pente) {
    this->pente = pente;
}

QString CNeurone::serializeSimples(void) {
    QString ret = "\"seuil\": "+QString::number(seuil)+", \"pente\": "+QString::number(pente);

    return ret;
}

QString CNeurone::serializeGenes(void) {
    int i;
    QString ret = "\"genes\": [";
    QString s = "";

    for(i=0;i<nbGene;i++) {
        ret += s + QString::number(genes[i].getValue());
        s = ",";
    }

    ret += "]";

    return ret;
}
