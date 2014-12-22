#include "unkmaterial.h"

UNKMaterial::UNKMaterial()
{
    isotopes = QVector<UNKIsotop>();
}

UNKMaterial::UNKMaterial(QVector<UNKIsotop> iso, qreal tem, QString com)
{
    isotopes = QVector<UNKIsotop>(iso);
    temp = tem;
    comment = com;
}

QVector<UNKIsotop>* UNKMaterial::getIsotopes()
{
    return &isotopes;
}

void UNKMaterial::setIsotopes(int num)
{
    isotopes = QVector<UNKIsotop>(num,UNKIsotop(0,0,false,UNKMics()));
}

qreal UNKMaterial::getTemp()
{
    return temp;
}

void UNKMaterial::setTemp(qreal in)
{
    temp = in;
}

QString UNKMaterial::getComment()
{
    return comment;
}

void UNKMaterial::setComment(QString in)
{
    comment = in;
}

QString UNKMaterial::save()
{
    QString ans;
    quint16 num_t = isotopes.size();
    QVector<UNKIsotop>::iterator i;
    quint16 j = 0;
    ans += QString("  %1").arg(isotopes.size(),3);
    for(i = isotopes.begin(); i != isotopes.end(); ++i)
        num_t -= i->getModel();
    ans += QString("%1 %2\n").arg(num_t,3).arg(comment);
    ans += " ";
    for(i = isotopes.begin(); i != isotopes.end(); ++i)
    {
        ans += QString("%1").arg(i->getNumber(),5);
        if(++j == 10)
        {
            ans += "\n ";
            j = 0;
        }
    }
    if(j > 0) ans += '\n';
    ans += " ";
    j = 0;
    for(i = isotopes.begin(); i != isotopes.end(); ++i)
    {
        ans += QString("%1").arg(i->getConcer(),12,'e',5);
        if(++j == 10)
        {
            ans += "\n ";
            j = 0;
        }
    }
    if(j > 0) ans += '\n';
    ans += "  ";
    j = 0;
    for(i = isotopes.begin(); i != isotopes.end(); ++i)
    {
        ans += QString("%1").arg(i->getModel(),5);
        if(++j == 10)
        {
            ans += "\n ";
            j = 0;
        }
    }
    if(j > 0) ans += '\n';
    j = 0;
    for(i = isotopes.begin(); i != isotopes.end(); ++i)
    {
        if(!i->getModel())
        {
            ans += QString("%1").arg(i->getNumber_t(),5);
            if(++j == 10)
            {
                ans += '\n';
                j = 0;
            }
        }
    }
    if(j > 0) ans += '\n';
    j = 0;
    for(i = isotopes.begin(); i != isotopes.end(); ++i)
    {
        if(!i->getModel())
        {
            ans += QString("%1").arg(i->getConcer(),12,'e',5);
            if(++j == 10)
            {
                ans += '\n';
                j = 0;
            }
        }
    }
    if(j > 0) ans += '\n';
    ans += QString("%1").arg(temp,12,'e',5) + '\n';
    for(i = isotopes.begin(); i != isotopes.end(); ++i)
        ans += i->getMics()->save();
    return ans;
}
