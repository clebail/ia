#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>
#include "CWCircuit.h"

CWCircuit::CWCircuit(QWidget *parent) : QWidget(parent) {
    circuit = 0;
    path = 0;
}

void CWCircuit::setCircuit(CCircuit *circuit) {
    this->circuit = circuit;
    repaint();
}

void CWCircuit::drawTestCircuit(void) {
    path = new QPainterPath(QPointF(50, 50));

    path->cubicTo(QPointF(350, 0), QPointF(150, 500), QPointF(250, 50));
    path->cubicTo(QPointF(500, 150), QPointF(0, 350), QPointF(450, 50));
    repaint();
}

void CWCircuit::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::black));
    painter.drawRect(rect());

    if(circuit != 0) {
       painter.drawImage(QPoint(0, 0), circuit->getImage());
    }

    if(path != 0) {
        QPen pen = QPen(QColor(170, 170, 170));
        QBrush brush = QBrush(QColor(120, 120, 120));
        //pen.setWidth(40);
        painter.setPen(pen);
        painter.setBrush(brush);

        painter.drawPath(*path);
    }
    
    emit drawVoitures(&painter);
}

void CWCircuit::mousePressEvent(QMouseEvent * event) {
    if(path != 0) {
        qDebug() << event->pos() << path->contains(event->pos());
    }
    emit mousePress(event->x(), event->y());
}
