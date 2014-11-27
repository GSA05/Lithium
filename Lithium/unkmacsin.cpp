#include "unkmacsin.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

UNKMacsin::UNKMacsin()
{
    zones = QVector<UNKZone>();
    materials = QVector<UNKMaterial>();
}

UNKMacsin::~UNKMacsin()
{

}

UNKMacsin::load(QFileInfo path)
{
    QFile file(path.absoluteFilePath());
    file.open(QIODevice::Text|QIODevice::ReadOnly);
    QTextStream in(&file);

    file.close();
}
