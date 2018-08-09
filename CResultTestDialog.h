#ifndef CRESULTTESTDIALOG_H
#define CRESULTTESTDIALOG_H

#include <QDialog>
#include "ui_CResultTestDialog.h"

class CResultTestDialog : public QDialog, private Ui::CResultTestDialog {
    Q_OBJECT
public:
    explicit CResultTestDialog(QWidget *parent = 0, QString result = QString());
};

#endif // CRESULTTESTDIALOG_H
