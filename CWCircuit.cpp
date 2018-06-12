#include <QPainter>
#include "CWCircuit.h"

CWCircuit::CWCircuit(QWidget *parent) : QWidget(parent) {
    circuit = 0;
}

void CWCircuit::setCircuit(CCircuit *circuit) {
    this->circuit = circuit;
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
    
    emit drawVoitures(&painter);
}
