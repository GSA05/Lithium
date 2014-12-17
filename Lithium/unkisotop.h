#ifndef UNKISOTOP_H
#define UNKISOTOP_H

#include <QtGlobal>
#include <QVector>
#include <QString>

class UNKMics
{
public:
    UNKMics();
    UNKMics(QVector<quint8> grp);
    QVector<quint8> getGroups();
    QString save();

private:
    QVector<quint8> groups;
};

class UNKIsotop
{
public:
    UNKIsotop();
    UNKIsotop(quint16 num, qreal con, bool mod, QVector<quint8> grp);
    int addT(quint16 num_t);
    quint16 getNumber();
    qreal getConcer();
    bool getModel();
    quint16 getNumber_t();
    UNKMics getMics();

private:
    quint16 number;
    qreal concer;
    bool model;
    quint16 number_t;
    UNKMics mics;
};

#endif // UNKISOTOP_H
