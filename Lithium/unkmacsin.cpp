#include "unkmacsin.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>

extern FILE *yyin, *yyout;
extern "C" int yylex();

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

quint8 UNKMacsin::getGroups()
{
    return groups;
}

quint8 UNKMacsin::getGroupsT()
{
    return groupsT;
}

quint16 UNKMacsin::getPred()
{
    return pred;
}

qreal UNKMacsin::getAlbedo()
{
    return albedo;
}

QVector<UNKZone> UNKMacsin::getZones()
{
    return zones;
}

QVector<UNKMaterial> UNKMacsin::getMaterials()
{
    return materials;
}

bool UNKMacsin::load(QFileInfo path)
{
    yyin = fopen(path.absoluteFilePath().toUtf8().constData(),"r");
    FILE *out;
    yyout = out;//fopen((QString(path.absoluteDir().path()) + "raw.dat").toUtf8().constData(),"w");
    yylex();
    //QFile file(path.absoluteDir().path() + "raw.dat");
    //file.open(QIODevice::Text|QIODevice::ReadOnly);
    QTextStream in(out);
    quint16 geom,num_z,groups,groupsT,num_m,pred;
    qreal alb;
    in>>geom>>num_z>>groups>>groupsT>>num_m>>pred;
    in>>alb;
    //file.close();
    return true;
}

bool UNKMacsin::save(QFileInfo path)
{
    QFile file(path.absoluteFilePath());
    file.open(QIODevice::Text|QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<QString("%1%2%3%4%5%6\n").arg(geometry,3).arg(zones.size(),3).arg(groups,3).arg(groupsT,3).arg(materials.size(),3).arg(pred,3);
    out<<QString("%1\n").arg(albedo,12,'e',5);
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
