#ifndef CWCIRCUIT_H
#define CWCIRCUIT_H

#include <QWidget>
#include "CCircuit.h"

class CWCircuit : public QWidget {
    Q_OBJECT
public:
    explicit CWCircuit(QWidget *parent = 0);
    void setCircuit(CCircuit *circuit);
    void drawTestCircuit(void);
protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent * event);
private:
    CCircuit *circuit;
    QPainterPath *path;
signals:
    void drawVoitures(QPainter *painter);
    void mousePress(int x, int y);
};

#endif // CWCIRCUIT_H
