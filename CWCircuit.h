#ifndef CWCIRCUIT_H
#define CWCIRCUIT_H

#include <QWidget>
#include "CCircuit.h"

class CWCircuit : public QWidget {
    Q_OBJECT
public:
    explicit CWCircuit(QWidget *parent = 0);
    void setCircuit(CCircuit *circuit);
protected:
    virtual void paintEvent(QPaintEvent *);
private:
    CCircuit *circuit;
signals:
    void drawVoitures(QPainter *painter);
};

#endif // CWCIRCUIT_H
