#ifndef UNKZONE_H
#define UNKZONE_H

#include <QtGlobal>
#include <unkmaterial.h>

class UNKZone
{
public:
    UNKZone();
    UNKZone(qreal rad, quint16 mat, bool noth);
    qreal getRadius();
    void setRadius(qreal in);
    quint16 getMaterial();
    void setMaterial(quint16 in);
    bool getNothing();
    void setNothing(bool in);

private:
    qreal radius;
    quint16 material;
    bool nothing;
};

#endif // UNKZONE_H
