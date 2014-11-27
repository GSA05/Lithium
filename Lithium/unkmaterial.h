#ifndef UNKMATERIAL_H
#define UNKMATERIAL_H

#include <QtGlobal>
#include <QVector>
#include <unkisotop.h>

class UNKMaterial
{
public:
    UNKMaterial();

private:
    QVector<UNKIsotop> isotopes;
    qreal temp;
    QString comment;
};

#endif // UNKMATERIAL_H
