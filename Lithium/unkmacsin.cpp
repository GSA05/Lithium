#include "unkmacsin.h"
#include "FlexLexer.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <fstream>

//extern FILE *yyin, *yyout;
//extern "C" int yylex();
//extern "C++" class FlexLexer;
//extern "C++" class parserFlexLexer;

UNKMacsin::UNKMacsin()
{
    zones = QVector<UNKZone>();
    materials = QVector<UNKMaterial>();
}

UNKMacsin::~UNKMacsin()
{

}

quint8 UNKMacsin::getGeometry()
{
    return geometry;
}

void UNKMacsin::setGeometry(quint8 in)
{
    geometry = in;
}

quint8 UNKMacsin::getGroups()
{
    return groups;
}

void UNKMacsin::setGroups(quint8 in)
{
    groups = in;
}

quint8 UNKMacsin::getGroupsT()
{
    return groupsT;
}

void UNKMacsin::setGroupsT(quint8 in)
{
    groupsT = in;
}

quint16 UNKMacsin::getPred()
{
    return pred;
}

void UNKMacsin::setPred(quint16 in)
{
    pred = in;
}

qreal UNKMacsin::getAlbedo()
{
    return albedo;
}

void UNKMacsin::setAlbedo(qreal in)
{
    albedo = in;
}

QVector<UNKZone>* UNKMacsin::getZones()
{
    return &zones;
}

void UNKMacsin::setZones(quint8 num)
{
    zones = QVector<UNKZone>(num,UNKZone(0,0,0));
}

QVector<UNKMaterial>* UNKMacsin::getMaterials()
{
    return &materials;
}

void UNKMacsin::setMaterials(quint8 num)
{
    materials = QVector<UNKMaterial>(num,UNKMaterial(QVector<UNKIsotop>(),0,""));
}

bool UNKMacsin::load(QFileInfo path)
{
    std::ifstream file;
    file.open(path.absoluteFilePath().toStdString().c_str());
    UNKMacsinScanner* lexer = new UNKMacsinScanner(&file);
    lexer->lex(this);
    file.close();
    this->save(path.absoluteFilePath()+".tmp");
    return true;
}

bool UNKMacsin::save(QFileInfo path)
{
    QFile file(path.absoluteFilePath());
    file.open(QIODevice::Text|QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<QString("  %1%2%3%4%5%6\n").arg(geometry,3).arg(zones.size(),3).arg(groups,3).arg(groupsT,3).arg(materials.size(),3).arg(pred,3);
    out<<QString(" %1\n").arg(albedo,12,'e',5);
    out<<" ";
    QVector<UNKZone>::iterator i;
    int j = 0;
    for(i = zones.begin(); i != zones.end(); ++i)
    {
        out<<QString("%1").arg(i->getRadius(),12,'e',5);
        if(++j == 10)
        {
            out<<endl;
            j = 0;
        }
    }
    if(j > 0) out<<endl;
    out<<"  ";
    j = 0;
    for(i = zones.begin(); i != zones.end(); ++i)
    {
        out<<QString("%1").arg(i->getMaterial(),3);
        if(++j == 10)
        {
            out<<endl;
            j = 0;
        }
    }
    if(j > 0) out<<endl;
    out<<"  ";
    j = 0;
    for(i = zones.begin(); i != zones.end(); ++i)
    {
        out<<QString("%1").arg(i->getNothing(),3);
        if(++j == 10)
        {
            out<<endl;
            j = 0;
        }
    }
    if(j > 0) out<<endl;
    QVector<UNKMaterial>::iterator k;
    for(k = materials.begin(); k != materials.end(); ++k)
        out<<k->save();
    file.close();
    return true;
}
