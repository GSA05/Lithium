#ifndef UNKCASE_H
#define UNKCASE_H

#include <QAbstractItemModel>
#include <QStandardItem>

class UNKCase: public QAbstractItemModel
{
public:
    UNKCase(QObject *parent = 0);
    ~UNKCase();

    void setRootItem(QStandardItem *item);

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QStandardItem *itemFromIndex(const QModelIndex &index) const;

    QStandardItem *rootItem;
};

#endif // UNKCASE_H
