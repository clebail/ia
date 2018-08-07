#include <QPainter>
#include <QMouseEvent>
#include <QtDebug>
#include <math.h>
#include "commun.h"
#include "CWCircuit.h"

#define RAYON           22.0

CWCircuit::CWCircuit(QWidget *parent) : QWidget(parent) {
    circuit = 0;
	elapsedTime = "00:00:00";
}

void CWCircuit::setCircuit(CCircuit *circuit) {
    this->circuit = circuit;
    repaint();
}

void CWCircuit::calculMarkers(const QPoint& depart, double distance, double angleDepart, int numCircuit, bool showDroite) {
    QPoint curPoint;
    bool fini = false;
    double step = 0.01;

    markers.clear();
	lines.clear();
    
    curPoint = depart;
	
	qStdOut() << "#include <QList>\r\n";
    qStdOut() << "#include \"CDroite.h\"\r\n\r\n";
    qStdOut() << "void initCircuit" << numCircuit << "(QList<CDroite *>& mks) {\r\n";
	
    while(!fini) {
        double angle = angleDepart;

        while(fabs(angle - angleDepart) < 2 * PI) {
            QPoint p(cos(angle) * distance + curPoint.x(), sin(angle) * distance + curPoint.y());

           if(this->circuit->getImage().pixel(p) > 0xFFDDDDDD) {
                double dx = p.x() - curPoint.x();
                double dy = p.y() - curPoint.y();
                double ay = asin(dy / distance);

                markers.append(p);

                angleDepart = acos(dx / distance) * (ay < 0 ? -1 : 1) - PI2;
                QPoint pNext = calculNextPoint(p, angleDepart - PI2);
                CDroite *d = CDroite::create(p, pNext);

                if(showDroite) {
                    lines.append(d->getLine(this->circuit->getImage().size()));
                }

                qStdOut() << "\tmks << CDroite::create(QPointF(" << p.x() << ", " << p.y() << "), QPointF(" << pNext.x() << ", " << pNext.y() << ")); //" << d->toString() << "\r\n";
                
				curPoint = p;

                delete d;
                break;
            }

            angle += step;
        }

        fini = abs(curPoint.x() - depart.x()) < distance/2 && abs(curPoint.y() - depart.y()) < distance/2;
    }
    qStdOut() << "}\r\n";
    
    repaint();
}

void CWCircuit::createImage(QString fileName) {
    QPixmap pixmap(size());
    render(&pixmap);

    pixmap.save(fileName, "JPG", 75);
}

void CWCircuit::setElapsedTime(QString elapsedTime) {
	this->elapsedTime = elapsedTime;
}

void CWCircuit::paintEvent(QPaintEvent *) {
    QPainter painter(this);
	QFont font;
	
	font.setPixelSize(34);
	
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
        
        for(i=0;i<lines.size();i++) {
            painter.setPen(QPen(Qt::red));
            painter.setBrush(QBrush(Qt::red));

            painter.drawLine(lines.at(i));
        }
        
        if(!circuit->getPosTime().isNull()) {
            painter.setPen(QPen(Qt::white));
            painter.setFont(font);
            painter.drawText(circuit->getPosTime(), elapsedTime);
        }
    }

    emit drawVoitures(&painter);
}

QTextStream& CWCircuit::qStdOut(void) {
    static QTextStream ts(stdout);

    return ts;
}

QPoint CWCircuit::calculNextPoint(const QPoint& p, double angleDepart) {
    double a1 = angleDepart;
    double a2 = angleDepart + PI;
    double step = 0.01;
    QPoint pNext1(cos(a1) * RAYON + p.x(), sin(a1) * RAYON + p.y());
    QPoint pNext2(cos(a2) * RAYON + p.x(), sin(a2) * RAYON + p.y());

    while(this->circuit->getImage().pixel(pNext1) > 0xFF000000) {
        a1 += step;
        pNext1 = QPoint(cos(a1) * RAYON + p.x(), sin(a1) * RAYON + p.y());
    }

    while(this->circuit->getImage().pixel(pNext2) > 0xFF000000) {
        a2 -= step;
        pNext2 = QPoint(cos(a2) * RAYON + p.x(), sin(a2) * RAYON + p.y());
    }

    return QPoint((pNext1.x() + pNext2.x()) / 2, (pNext1.y() + pNext2.y()) / 2);
}

