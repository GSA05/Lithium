#ifndef MATERIAL_H
#define MATERIAL_H

#include <QStandardItem>

#define MaterialType QStandardItem::UserType + 1
#define IsotopType QStandardItem::UserType + 2

class Isotop: public QStandardItem
{
public:
    Isotop(quint16 num = 1111, qreal temp = 300, qreal conc = 1e-7);
    ~Isotop();

    int type() const;

    QVariant data(int role = Qt::UserRole + 1) const;

    quint16 Number() const;
    void SetNumber(quint16 num);
    qreal Temperature() const;
    void SetTemperature(qreal temp);
    void ChangeTemperature(qreal temp);
    qreal Concentration() const;
    void SetConcentration(qreal conc);
    void ChangeConcentration(qreal conc);

private:
    quint16 number;
    qreal temperature;
    qreal concentration;
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
