#ifndef EXAMPLEITEMMODEL_H
#define EXAMPLEITEMMODEL_H

#include <QAbstractListModel>
#include <ExampleTemplateLib/ExampleItem.h>

class ExampleItemModel : public QAbstractListModel
{
  Q_OBJECT

public:
  explicit ExampleItemModel(QObject *parent = nullptr);

  enum {
    NameRole = Qt::UserRole,
    DescriptionRole,
    Value1Role,
    Value2Role,
  };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  virtual QHash<int, QByteArray> roleNames() const override;

private:
  std::vector<ExampleItem> dataContainer;
};

#endif // EXAMPLEITEMMODEL_H
