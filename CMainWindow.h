#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include "ui_CMainWindow.h"
#include "CGenetic.h"
#include "CTestVoitureAngle.h"
#include "CTestVoiturePilote.h"

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
    CTestVoiturePilote * testVoiturePilote;
	CCircuit *circuitPilote;
    CSetup setup;
    int imgIdx;
	QTime mainTime;
    QTimer *testPiloteTimer;
private slots:
    void onGeneticCalculOk(void);
    void onGeneticCircuitChange(CCircuit *circuit);
    void onGeneticRepaintRequested(void);
    void onGeneticTerminated(void);
    void on_pbTest_clicked(bool checked = false);
	void on_pbTestVoiture_clicked(bool checked = false);
	void onTVdrawVoitures(QPainter *painter);
    void on_pbCalculMarkers_clicked(bool checked = false);
    void on_pbTestPilote_clicked(bool checked = false);
    void onTVPdrawVoitures(QPainter *painter);
    void onTestTimerPiloteTimeout(void);
};

#endif // CMAINWINDOW_H
