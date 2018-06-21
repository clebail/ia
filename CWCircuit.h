#ifndef CWCIRCUIT_H
#define CWCIRCUIT_H

#include <QWidget>
#include <QTextStream>
#include "CCircuit.h"

class CWCircuit : public QWidget {
    Q_OBJECT
public:
    explicit CWCircuit(QWidget *parent = 0);
    void setCircuit(CCircuit *circuit);
    void calculMarkers(const QPoint &depart, double distance, double angleDepart);
protected:
    virtual void paintEvent(QPaintEvent *);
private:
    CCircuit *circuit;
    QList<QPoint> markers;

    QTextStream& qStdOut(void);
signals:
    void drawVoitures(QPainter *painter);
};

#endif // CWCIRCUIT_H
