#include "CJSonDialog.h"

CJSonDialog::CJSonDialog(QWidget *parent) : QDialog(parent) {
    setupUi(this);
}

QString CJSonDialog::getJSon(void) {
    return teJSon->toPlainText();
}

