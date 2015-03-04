#include "material.h"

//Isotop
Isotop::Isotop(quint16 num, qreal temp, qreal conc): QStandardItem()
{
    number = num;
    temperature = temp;
    concentration = conc;
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
        return QVariant(number);
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

qreal Isotop::Temperature() const
{
    return temperature;
}

void Isotop::SetTemperature(qreal temp)
{
    temperature = temp;
}

void Isotop::ChangeTemperature(qreal temp)
{
    SetTemperature(temp);
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
