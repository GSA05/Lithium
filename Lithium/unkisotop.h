#ifndef UNKISOTOP_H
#define UNKISOTOP_H

#include <QtGlobal>
#include <QVector>

class UNKMics
{
public:
    UNKMics();

private:
    QVector<quint8> groups;
};

class UNKIsotop
{
public:
    UNKIsotop();

private:
    quint16 number;
    qreal concer;
    bool model;
    quint16 number_t;
    UNKMics mics;
};

#endif // UNKISOTOP_H
