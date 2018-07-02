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
    void calculMarkers(const QPoint &depart, double distance, double angleDepart, int numCircuit);
    void createImage(QString fileName);
	void setElapsedTime(QString elapsedTime);
protected:
    virtual void paintEvent(QPaintEvent *);
private:
    CCircuit *circuit;
    QList<QPoint> markers;
	QString elapsedTime;

    QTextStream& qStdOut(void);
signals:
    void drawVoitures(QPainter *painter);
};

#endif // CWCIRCUIT_H
