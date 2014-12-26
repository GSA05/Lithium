#ifndef TEMPDIALOG_H
#define TEMPDIALOG_H

#include <QDialog>
#include "ui_temp.h"

class tempDialog : public QDialog
{
    Q_OBJECT
public:
    explicit tempDialog(QDialog *parent = 0);
    qreal getTemp();

signals:

public slots:
    void allMaterials(bool state);

private:
    Ui::tempDialog ui;
};

#endif // TEMPDIALOG_H
