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
    void calculMarkers(const QPoint &depart, double distance, double angleDepart, int numCircuit, bool showDroite);
    void createImage(QString fileName);
	void setElapsedTime(QString elapsedTime);
	void setPositionRef(const QPoint& positionRef);
protected:
    virtual void paintEvent(QPaintEvent *);
private:
    CCircuit *circuit;
    QList<QPoint> markers;
	QList<QLine> lines;
	QString elapsedTime;
	QPoint positionRef;

    QTextStream& qStdOut(void);
    QPoint calculNextPoint(const QPoint& p, double angleDepart);
signals:
    void drawVoitures(QPainter *painter);
};

#endif // CWCIRCUIT_H
