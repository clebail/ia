#ifndef CCIRCUIT_H
#define CCIRCUIT_H

#include <QPoint>
#include <QString>
#include <QImage>

class CCircuit {
public:
    CCircuit(void);
    CCircuit(QPoint depart, QString imgResource);
    const QPoint& getDepart(void);
    const QImage& getImage(void);
private:
    QPoint depart;
    QImage image;
};

#endif // CCIRCUIT_H
