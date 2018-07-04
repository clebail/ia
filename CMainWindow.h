#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "ui_CMainWindow.h"
#include "CGenetic.h"
#include "CTestVoitureAngle.h"

class CMainWindow : public QMainWindow, private Ui::CMainWindow {
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow(void);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
private:
    CGenetic *genetic;
    CTestVoitureAngle *testVoiture;
    CSetup setup;
    int imgIdx;
	QTime mainTime;
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
