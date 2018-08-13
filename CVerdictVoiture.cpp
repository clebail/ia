#include <QtDebug>
#include "CVerdictVoiture.h"

CVerdictVoiture::CVerdictVoiture() : CBaseVoiture() {

}

CVerdictVoiture * CVerdictVoiture::fronJSon(json_object *jObj) {
    CVerdictVoiture *result = new CVerdictVoiture();

    if(json_object_get_type(jObj) == json_type_array) {
        int len = json_object_array_length(jObj);
        int i;

        if(len == NB_NEURONE) {
            for(i=0;i<len;i++) {
                json_object *val = json_object_array_get_idx(jObj, i);

                if(json_object_get_type(val) == json_type_object) {
                    struct json_object_iterator it;
                    struct json_object_iterator itEnd;
                    bool asSeuil = false;
                    bool asGenes = false;
                    bool asPente = false;

                    it = json_object_iter_begin(val);
                    itEnd = json_object_iter_end(val);
                    while(!json_object_iter_equal(&it, &itEnd)) {
                        QString key = QString(json_object_iter_peek_name(&it));
                        json_object *object = json_object_iter_peek_value(&it);

                        if(key == "seuil" && json_object_get_type(object) == json_type_double) {
                            result->ns[i]->setSeuil(json_object_get_double(object));
                            asSeuil = true;
                        }

                        if(key == "pente" && json_object_get_type(object) == json_type_double) {
                            result->ns[i]->setPente(json_object_get_double(object));
                            asPente = true;
                        }

                        if(key == "genes") {
                            result->ns[i]->setJSonGenes(object);
                            asGenes = true;
                        }

                        if(key == "coefVitesse") {
                            static_cast<CNeuroneVitesse *>(result->ns[i])->setJSonGenes(object);
                            asGenes = true;
                        }

                        json_object_iter_next(&it);
                    }

                    if(!asSeuil || !asGenes || !asPente) {
                        qCritical() << "JSon incorect, l'obejt doit contenir un attribut seuil, un attribut pente et un attribut genes";
                    }
                } else {
                    qCritical() << "Impossible de créer les neurones, l'objet n'est pas un objet";
                }
            }
        } else {
            qCritical() << "Impossible de créer les genes, le tableau n'a pas le bon nombre d'élément";
        }
    } else {
        qCritical() << "Impossible de créer les neurones, l'objet n'est pas un tableau";
    }

    return result;
}
