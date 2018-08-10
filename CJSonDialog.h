#ifndef CJSONDIALOG_H
#define CJSONDIALOG_H

#include <QDialog>
#include "ui_CJSonDialog.h"

class CJSonDialog : public QDialog, private Ui::CJSonDialog {
    Q_OBJECT
public:
    explicit CJSonDialog(QWidget *parent = 0);
    QString getJSon(void);
};

#endif // CJSONDIALOG_H
