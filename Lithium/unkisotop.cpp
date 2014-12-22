#include "unkisotop.h"

//UNKMics
UNKMics::UNKMics()
{
    groups = QVector<quint8>();
}

UNKMics::UNKMics(QVector<quint8> grp)
{
    groups = QVector<quint8>(grp);
}

QVector<quint8> UNKMics::getGroups()
{
    return groups;
}

QString UNKMics::save()
{
    QString ans;
    ans += groups.size();
    for(QVector<quint8>::const_iterator i = groups.constBegin(); i != groups.constEnd(); ++i )
        ans += ' ' + *i;
    ans += '\n';
    return ans;
}

//UNKIsotop
UNKIsotop::UNKIsotop()
{
}

UNKIsotop::UNKIsotop(quint16 num, qreal con, bool mod, UNKMics mic)
{
    number = num;
    concer = con;
    model = mod;
    mics = mic;
}

int UNKIsotop::addT(quint16 num_t)
{
    number_t = num_t;
    model = true;
    return 0;
}

quint16 UNKIsotop::getNumber()
{
    return number;
}

qreal UNKIsotop::getConcer()
{
    return concer;
}

bool UNKIsotop::getModel()
{
    return model;
}

quint16 UNKIsotop::getNumber_t()
{
    return number_t;
}

UNKMics UNKIsotop::getMics()
{
    return mics;
}
