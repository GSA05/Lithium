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

QVector<quint8> *UNKMics::getGroups()
{
    return &groups;
}

QString UNKMics::save()
{
    QString ans;
    ans += QString("  %1").arg(groups.size(),3);
    for(QVector<quint8>::const_iterator i = groups.constBegin(); i != groups.constEnd(); ++i )
        ans += QString("%1").arg(*i,3);
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

void UNKIsotop::addT(quint16 num_t)
{
    number_t = num_t;
    model = true;
}

quint16 UNKIsotop::getNumber()
{
    return number;
}

void UNKIsotop::setNumber(quint16 in)
{
    number = in;
}

qreal UNKIsotop::getConcer()
{
    return concer;
}

void UNKIsotop::setConcer(qreal in)
{
    concer = in;
}

bool UNKIsotop::getModel()
{
    return model;
}

void UNKIsotop::setModel(bool in)
{
    model = in;
}

quint16 UNKIsotop::getNumber_t()
{
    return number_t;
}

void UNKIsotop::setNumber_t(quint16 in)
{
    number_t = in;
}

UNKMics *UNKIsotop::getMics()
{
    return &mics;
}

void UNKIsotop::setMics(quint8 num)
{
    mics = UNKMics(QVector<quint8>(num,0));
}
