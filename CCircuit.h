#ifndef CCIRCUIT_H
#define CCIRCUIT_H

#include <QPoint>
#include <QString>

class CCircuit {
public:
    CCircuit(void);
    CCircuit(QPoint depart, QString imgResource);
    const QPoint& getDepart(void);
    const QString& getImgResource(void);
private:
    QPoint depart;
    QString imgResource;
};

#endif // CCIRCUIT_H
