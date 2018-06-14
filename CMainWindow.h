#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "ui_CMainWindow.h"
#include "CGenetic.h"

class CMainWindow : public QMainWindow, private Ui::CMainWindow {
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow(void);
private:
    CGenetic *genetic;
private slots:
    void onGeneticCalculOk(CVoiture *best);
    void onGeneticCircuitChange(CCircuit *circuit);
    void onGeneticRepaintRequested(void);
    void on_pbTest_clicked(bool checked = false);
};

#endif // CMAINWINDOW_H
