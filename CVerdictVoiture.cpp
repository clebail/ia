#include <QtDebug>
#include "CVerdictVoiture.h"

CVerdictVoiture::CVerdictVoiture() : CBaseVoiture() {

}

CVerdictVoiture * CVerdictVoiture::fronJSon(json_object *jObj) {
    CVerdictVoiture *result = new CVerdictVoiture();

    if(json_object_get_type(jObj) == json_type_array) {
        int len = json_object_array_length(jObj);
        int i;

        for(i=0;i<len;i++) {
            json_object *val = json_object_array_get_idx(jObj, i);
            result->ns[i]->setJSonGenes(val);
        }
    } else {
        qCritical() << "Impossible de créer les neurones, l'objet n'est pas un tableau";
    }

    return result;
}
