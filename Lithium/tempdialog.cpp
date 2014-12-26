#include "tempdialog.h"

tempDialog::tempDialog(QDialog *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
}

qreal tempDialog::getTemp()
{
    return ui.tempEdit->text().toFloat();
}

void tempDialog::allMaterials(bool state)
{
    ui.izotEdit->setEnabled(!state);
}
