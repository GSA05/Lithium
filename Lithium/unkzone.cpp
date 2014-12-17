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

quint16 UNKZone::getMaterial()
{
    return material;
}

bool UNKZone::getNothing()
{
    return nothing;
}
