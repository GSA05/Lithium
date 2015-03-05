#include "material.h"

//Mics
Mics::Mics(QVector<quint8> grp)
{
    groups = grp;
}

QVector<quint8> *Mics::getGroups()
{
    return &groups;
}

void Mics::setGroups(QVector<quint8> grp)
{
    groups = grp;
}

QString Mics::save() const
{
    QString ans;
    ans += QString("  %1").arg(groups.size(),3);
    for(QVector<quint8>::const_iterator i = groups.constBegin(); i != groups.constEnd(); ++i )
        ans += QString("%1").arg(*i,3);
    ans += '\n';
    return ans;
}

//Isotop
Isotop::Isotop(quint16 num, qreal conc, bool mod, quint16 numT, Mics mic)
{
    number = num;
    concentration = conc;
    model = mod;
    numberT = numT;
    micGroups = mic;
}

Isotop::~Isotop()
{

}

int Isotop::type() const
{
    return IsotopType;
}

QVariant Isotop::data(int role) const
{
    if (role == Qt::DisplayRole) {
        return QVariant(QString("%1 (%2)").arg(number).arg(numberT));
    }
    else {
        return QStandardItem::data(role);
    }
}

quint16 Isotop::Number() const
{
    return number;
}

void Isotop::SetNumber(quint16 num)
{
    number = num;
}

qreal Isotop::Concentration() const
{
    return concentration;
}

void Isotop::SetConcentration(qreal conc)
{
    concentration = conc;
}

void Isotop::ChangeConcentration(qreal conc)
{
    SetConcentration(conc);
}

void Isotop::ChangeTemperature(qreal temp)
{

}

bool Isotop::Model() const
{
    return model;
}

void Isotop::SetModel(bool mod)
{
    model = mod;
}

quint16 Isotop::NumberT() const
{
    return numberT;
}

void Isotop::SetNumberT(quint16 numT)
{
    numberT = numT;
}

Mics Isotop::MicGroups() const
{
    return micGroups;
}

void Isotop::SetMicGroups(Mics mic)
{
    micGroups = mic;
}

//Material
Material::Material(): QStandardItem()
{
    name = "";
    color = Qt::green;
}

int Material::type() const
{
    return MaterialType;
}
