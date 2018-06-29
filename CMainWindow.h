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
	CVoiture testVoiture;
    CSetup setup;
    int imgIdx;
private slots:
    void onGeneticCalculOk(CVoiture *best);
    void onGeneticCircuitChange(CCircuit *circuit);
    void onGeneticRepaintRequested(void);
    void onGeneticTerminated(void);
    void on_pbTest_clicked(bool checked = false);
	void on_pbTestVoiture_clicked(bool checked = false);
	void onTVdrawVoitures(QPainter *painter);
    void on_pbCalculMarkers_clicked(bool checked = false);
};

#endif // CMAINWINDOW_H
