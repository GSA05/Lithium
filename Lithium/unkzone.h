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
    quint16 getMaterial();
    bool getNothing();

private:
    qreal radius;
    quint16 material;
    bool nothing;
};

#endif // UNKZONE_H
