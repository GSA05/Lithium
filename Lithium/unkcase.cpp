#include "unkcase.h"

UNKCase::UNKCase(QObject *parent): QAbstractItemModel(parent)
{
    rootItem = 0;
}

UNKCase::~UNKCase()
{
    delete rootItem;
}

void UNKCase::setRootItem(QStandardItem *item)
{
    delete rootItem;
    rootItem = item;
    resetInternalData();
}

QModelIndex UNKCase::index(int row, int column, const QModelIndex &parent) const
{
    if (!rootItem)
        return QModelIndex();
    QStandardItem *parentItem = itemFromIndex(parent);
    return createIndex(row, column, parentItem->child(row));
}

QStandardItem *UNKCase::itemFromIndex(const QModelIndex &index) const
{
    if (index.isValid()) {
        return static_cast<QStandardItem *>(index.internalPointer());
    }
    else {
        return rootItem;
    }
}

int UNKCase::rowCount(const QModelIndex &parent) const
{
    QStandardItem *parentItem = itemFromIndex(parent);
    if (!parentItem)
        return 0;
    return parentItem->rowCount();
}

int UNKCase::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QModelIndex UNKCase::parent(const QModelIndex &child) const
{
    QStandardItem *item = itemFromIndex(child);
    if (!item)
        return QModelIndex();
    QStandardItem *parentItem = item->parent();
    if (!parentItem)
        return QModelIndex();
    QStandardItem *grandparentItem = parentItem->parent();
    if (!grandparentItem)
        return QModelIndex();

    int row = parentItem->row();
    return createIndex(row, child.column(), parentItem);
}

QVariant UNKCase::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    QStandardItem *item = itemFromIndex(index);
    if (!item)
        return QVariant();

    if (index.column() == 0)
        return item->data(Qt::DisplayRole);
    return QVariant();
}

QVariant UNKCase::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        if (section == 0)
            return "123";
    }
    return QVariant();
}
