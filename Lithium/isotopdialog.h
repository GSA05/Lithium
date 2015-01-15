#ifndef ISOTOPDIALOG_H
#define ISOTOPDIALOG_H

#include <QDialog>
#include "ui_isotop.h"

class isotopDialog : public QDialog
{
    Q_OBJECT
public:
    explicit isotopDialog(QDialog *parent = 0);
    quint16 getNum();
    qreal getConc();

signals:

public slots:
    void allMaterials(bool state);

private:
    Ui::isotopDialog ui;
};

#endif // ISOTOPDIALOG_H
