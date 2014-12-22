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
    QVector<quint8>* getGroups();
    QString save();

private:
    QVector<quint8> groups;
};

class UNKIsotop
{
public:
    UNKIsotop();
    UNKIsotop(quint16 num, qreal con, bool mod, UNKMics mic);
    void addT(quint16 num_t);
    quint16 getNumber();
    void setNumber(quint16 in);
    qreal getConcer();
    void setConcer(qreal in);
    bool getModel();
    void setModel(bool in);
    quint16 getNumber_t();
    void setNumber_t(quint16 in);
    UNKMics* getMics();
    void setMics(quint8 num);

private:
    quint16 number;
    qreal concer;
    bool model;
    quint16 number_t;
    UNKMics mics;
};

#endif // UNKISOTOP_H
