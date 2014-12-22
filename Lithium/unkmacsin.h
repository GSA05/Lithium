#ifndef UNKMACSIN_H
#define UNKMACSIN_H

#include <QtGlobal>
#include <QVector>
#include <QFileInfo>
#include <unkzone.h>
#include <unkmaterial.h>

class UNKMacsin
{
public:
    UNKMacsin();
    ~UNKMacsin();
    quint8 getGeometry();
    void setGeometry(quint8);
    quint8 getGroups();
    void setGroups(quint8);
    quint8 getGroupsT();
    void setGroupsT(quint8);
    quint16 getPred();
    void setPred(quint16);
    qreal getAlbedo();
    void setAlbedo(qreal);
    QVector<UNKZone>* getZones();
    void setZones(quint8 num);
    QVector<UNKMaterial>* getMaterials();
    void setMaterials(quint8 num);
    bool load(QFileInfo path);
    bool save(QFileInfo path);
    bool addMaterial();
    bool removeMaterial();
    bool changeAllMaterials();
    bool changeTemp();

private:
    quint8 geometry;
    quint8 groups;
    quint8 groupsT;
    quint16 pred;
    qreal albedo;
    QVector<UNKZone> zones;
    QVector<UNKMaterial> materials;
};

#ifndef YY_DECL
#define	YY_DECL						\
    int				\
    UNKMacsinScanner::lex(				\
    UNKMacsin* s                      \
    )
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer UNKFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif

class UNKMacsinScanner : public UNKFlexLexer
{
public:
    UNKMacsinScanner(std::istream* arg_yyin = 0,
                     std::ostream* arg_yyout = 0);
    virtual ~UNKMacsinScanner();
    virtual int lex(UNKMacsin* s);
};

#endif // UNKMACSIN_H
