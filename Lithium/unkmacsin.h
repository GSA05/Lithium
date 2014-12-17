#ifndef UNKMACSIN_H
#define UNKMACSIN_H

#include <QtGlobal>
#include <QVector>
#include <QFileInfo>
#include <unkzone.h>
#include <unkmaterial.h>

class UNKMacsin
{
public:
    UNKMacsin();
    ~UNKMacsin();
    quint8 getGeometry();
    quint8 getGroups();
    quint8 getGroupsT();
    quint16 getPred();
    qreal getAlbedo();
    QVector<UNKZone> getZones();
    QVector<UNKMaterial> getMaterials();
    bool load(QFileInfo path);
    bool save(QFileInfo path);
    bool addMaterial();
    bool removeMaterial();
    bool changeAllMaterials();
    bool changeTemp();

private:
    quint8 geometry;
    quint8 groups;
    quint8 groupsT;
    quint16 pred;
    qreal albedo;
    QVector<UNKZone> zones;
    QVector<UNKMaterial> materials;
};

#endif // UNKMACSIN_H
