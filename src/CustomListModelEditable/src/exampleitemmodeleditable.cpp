#include "exampleitemmodeleditable.h"

ExampleItemModelEditable::ExampleItemModelEditable(QObject *parent)
  : QAbstractListModel(parent)
{
  this->dataContainer = {
    {"one" , "description one" , 1.0, 2.0},
    {"two" , "description two" , 2.1, 2.0},
    {"tre" , "description tre" , 3.2, 2.0},
    {"four", "description four", 4.3, 2.0},
    {"five", "description five", 5.4, 2.0},
    {"six" , "description six" , 6.5, 2.0},
  };
}

int ExampleItemModelEditable::rowCount(const QModelIndex &parent) const
{
  Q_UNUSED(parent);

  return this->dataContainer.size();
}

QVariant ExampleItemModelEditable::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  switch(role){
    case NameRole:
        return QVariant(QString::fromStdString(dataContainer[index.row()].name));
    case DescriptionRole:
        return QVariant(QString::fromStdString(dataContainer[index.row()].description));
    case Value1Role:
        return QVariant(QString::number(dataContainer[index.row()].value1, 'f', 2));
    case Value2Role:
        return QVariant(QString::number(dataContainer[index.row()].value2, 'f', 2));
  }

  return QVariant();
}

QHash<int, QByteArray> ExampleItemModelEditable::roleNames() const
{
  QHash<int, QByteArray> names;
  names[NameRole] = "name";
  names[DescriptionRole] = "description";
  names[Value1Role] = "value1";
  names[Value2Role] = "value2";
  return names;
}

bool ExampleItemModelEditable::setData(const QModelIndex &index, const QVariant &value, int role)
{
  ExampleItem item = dataContainer[index.row()];
  switch(role){
    case NameRole:
      item.name = value.toString().toUtf8().constData();
      break;
    case DescriptionRole:
      item.name = value.toString().toUtf8().constData();
      break;
    case Value1Role:
      item.description = value.toDouble();
      break;
    case Value2Role:
      item.description = value.toDouble();
      break;
  }
  dataContainer[index.row()] = item;
  return true;
}
