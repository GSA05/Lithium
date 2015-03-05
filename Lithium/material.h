#ifndef MATERIAL_H
#define MATERIAL_H

#include <QStandardItem>

#define MaterialType QStandardItem::UserType + 1
#define IsotopType QStandardItem::UserType + 2

class Mics
{
public:
    Mics(QVector<quint8> grp = QVector<quint8>());

    QVector<quint8> *getGroups();
    void setGroups(QVector<quint8> grp);
    QString save() const;

private:
    QVector<quint8> groups;
};

class Isotop: public QStandardItem
{
public:
    Isotop(quint16 num = 9010, qreal conc = 1e-7, bool mod = false,
           quint16 numT = 7010, Mics mic = Mics());
    ~Isotop();

    int type() const;

    QVariant data(int role = Qt::UserRole + 1) const;

    quint16 Number() const;
    void SetNumber(quint16 num);
    qreal Concentration() const;
    void SetConcentration(qreal conc);
    void ChangeConcentration(qreal conc);
    void ChangeTemperature(qreal temp);
    bool Model() const;
    void SetModel(bool mod);
    quint16 NumberT() const;
    void SetNumberT(quint16 numT);
    Mics MicGroups() const;
    void SetMicGroups(Mics mic);

private:
    quint16 number;
    qreal concentration;
    bool model;
    quint16 numberT;
    Mics micGroups;
};

class Material: public QStandardItem
{
public:
    Material();

    int type() const;

private:
    QString name;
    QColor color;
};

#endif // MATERIAL_H
