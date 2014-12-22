#ifndef UNKMATERIAL_H
#define UNKMATERIAL_H

#include <QtGlobal>
#include <QVector>
#include <QString>
#include <unkisotop.h>

class UNKMaterial
{
public:
    UNKMaterial();
    UNKMaterial(QVector<UNKIsotop> iso, qreal tem, QString com);
    QVector<UNKIsotop>* getIsotopes();
    void setIsotopes(int num);
    qreal getTemp();
    void setTemp(qreal in);
    QString getComment();
    void setComment(QString in);
    QString save();

private:
    QVector<UNKIsotop> isotopes;
    qreal temp;
    QString comment;
};

#endif // UNKMATERIAL_H
