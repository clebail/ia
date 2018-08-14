#ifndef CVERDICT_H
#define CVERDICT_H

#include <QString>
#include <QThread>
#include <json.h>
#include "CVerdictVoiture.h"
#include "CCircuit.h"
#include "CWCircuit.h"

class CVerdict : public QThread {
    Q_OBJECT
public:
    CVerdict(CWCircuit *wCircuit, QString circutResource, QString jSon);
    ~CVerdict(void);
    void run(void);
private:
    void parseVoitures(QString jSon);
    QList<CVerdictVoiture *> voitures;
    CCircuit circuit;
    CWCircuit *wCircuit;
private slots:
    void onWCircuitDrawVoitures(QPainter *painter, double dx, double dy);
signals:
   void repaintRequested(const QPointF& positionMeilleur);
};

#endif // CVERDICT_H
