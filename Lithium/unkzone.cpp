#include "unkzone.h"

UNKZone::UNKZone()
{

}

UNKZone::UNKZone(qreal rad, quint16 mat, bool noth)
{
    radius = rad;
    material = mat;
    nothing = noth;
}

qreal UNKZone::getRadius()
{
    return radius;
}

void UNKZone::setRadius(qreal in)
{
    radius = in;
}

quint16 UNKZone::getMaterial()
{
    return material;
}

void UNKZone::setMaterial(quint16 in)
{
    material = in;
}

bool UNKZone::getNothing()
{
    return nothing;
}

void UNKZone::setNothing(bool in)
{
    nothing = in;
}
