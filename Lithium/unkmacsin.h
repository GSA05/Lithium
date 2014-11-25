#ifndef UNKMACSIN_H
#define UNKMACSIN_H

#include <QtGlobal>
#include <QVector>
#include <unkzone.h>
#include <unkmaterial.h>

class UNKMacsin
{
public:
    UNKMacsin();

private:
    quint8 geometry;
    quint8 groups;
    quint8 groups_t;
    quint16 pred;
    qreal albedo;
    QVector<UNKZone> zones;
    QVector<UNKMaterial> materials;
};

#endif // UNKMACSIN_H
