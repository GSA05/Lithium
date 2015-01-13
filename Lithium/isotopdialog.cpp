#include "isotopdialog.h"

isotopDialog::isotopDialog(QDialog *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
}

void isotopDialog::allMaterials(bool state)
{
    ui.materialBox->setEnabled(!state);
}
