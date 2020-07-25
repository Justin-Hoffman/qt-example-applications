#include "primefactorsmodel.h"

PrimeFactorsModel::PrimeFactorsModel(QObject *parent)
  : QAbstractListModel(parent)
{
  this->factors = {1,2,3};
}

int PrimeFactorsModel::rowCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);

  return this->factors.size();
}

QVariant PrimeFactorsModel::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  switch(role){
    case NumberRole:
        return QVariant(QString::number( factors[index.row()] ));
  }

  return QVariant();
}

QHash<int, QByteArray> PrimeFactorsModel::roleNames() const
{
  QHash<int, QByteArray> names;
  names[NumberRole] = "number";
  return names;
}
