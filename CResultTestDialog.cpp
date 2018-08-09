#include "CResultTestDialog.h"

CResultTestDialog::CResultTestDialog(QWidget *parent, QString result) : QDialog(parent) {
    setupUi(this);

    teResult->setText(result);
}
