#ifndef UNKMATERIAL_H
#define UNKMATERIAL_H

#include <QtGlobal>
#include <QVector>
#include <QString>
#include <unkisotop.h>

class UNKMaterial
{
public:
    UNKMaterial();
    UNKMaterial(QVector<UNKIsotop> iso, qreal tem, QString com);
    QVector<UNKIsotop> getIsotopes();
    qreal getTemp();
    QString getComment();
    QString save();

private:
    QVector<UNKIsotop> isotopes;
    qreal temp;
    QString comment;
};

#endif // UNKMATERIAL_H
