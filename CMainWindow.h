#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "ui_CMainWindow.h"
#include "CCircuit.h"

#define NB_CIRCUIT              4

class CMainWindow : public QMainWindow, private Ui::CMainWindow {
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);
private:
    CCircuit circuits[NB_CIRCUIT];
};

#endif // CMAINWINDOW_H
