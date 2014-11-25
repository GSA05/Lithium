#ifndef UNKZONE_H
#define UNKZONE_H

#include <QtGlobal>
#include <unkmaterial.h>

class UNKZone
{
public:
    UNKZone(UNKMaterial *mat);

private:
    qreal radius;
    UNKMaterial* material;
    bool nothing;
};

#endif // UNKZONE_H
