#include "isotopdialog.h"

isotopDialog::isotopDialog(QDialog *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
}

quint16 isotopDialog::getNum()
{
    return ui.numEdit->text().toInt();
}

qreal isotopDialog::getConc()
{
    return ui.concEdit->text().toFloat();
}

void isotopDialog::allMaterials(bool state)
{
    ui.materialBox->setEnabled(!state);
}
