#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>
#include <math.h>
#include "commun.h"
#include "CWCircuit.h"

CWCircuit::CWCircuit(QWidget *parent) : QWidget(parent) {
    circuit = 0;
}

void CWCircuit::setCircuit(CCircuit *circuit) {
    this->circuit = circuit;
    repaint();
}

void CWCircuit::calculMarkers(const QPoint& depart, double distance, double angleDepart) {
    QPoint curPoint;
    bool fini = false;
    double step = 0.01;

    markers.clear();

    curPoint = depart;
    while(!fini) {
        double angle = angleDepart;

        while(fabs(angle - angleDepart) < PI) {
            QPoint p(cos(angle) * distance + curPoint.x(), sin(angle) * distance + curPoint.y());

            //qDebug() << p << this->circuit->getImage().pixel(p);

            if(this->circuit->getImage().pixel(p) > 0xFFDDDDDD) {
                double dx = abs(p.x() - curPoint.x());
                double dy = abs(p.y() - curPoint.y());

                markers.append(p);

                angleDepart = PI2 - qMin(acos(dx / distance), asin(dy / distance));

                qDebug() << p << angleDepart;

                curPoint = p;

                break;
            }

            angle += step;
        }

        fini = markers.size() == 100;
    }

    markers.append(depart);

    repaint();
}

void CWCircuit::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(rect());

    if(circuit != 0) {
        int i;

        painter.drawImage(QPoint(0, 0), circuit->getImage());

        for(i=0;i<markers.size();i++) {
            painter.setPen(QPen(Qt::red));
            painter.setBrush(QBrush(Qt::red));

            painter.drawEllipse(markers.at(i), 3, 3);
        }
    }

    emit drawVoitures(&painter);
}

double CWCircuit::normAngle(double angle) {
    while(angle < 0) {
        angle += PI;
    }
    while(angle > 2 * PI) {
        angle -= PI;
    }

    return angle;
}

