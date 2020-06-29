#ifndef EXAMPLEITEMMODEL_H
#define EXAMPLEITEMMODEL_H

#include <QAbstractListModel>
#include <ExampleTemplateLib/ExampleItem.h>

class ExampleItemModelEditable : public QAbstractListModel
{
  Q_OBJECT

public:
  explicit ExampleItemModelEditable(QObject *parent = nullptr);

  enum {
    NameRole = Qt::UserRole,
    DescriptionRole,
    Value1Role,
    Value2Role,
  };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  virtual QHash<int, QByteArray> roleNames() const override;

  // The following four functions are necessary for dynamic models
  bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
  //Q_INVOKABLE void insert(int index, const QString& colorValue);
  //Q_INVOKABLE void append(const QString& colorValue);
  //Q_INVOKABLE void remove(int index);
  //Q_INVOKABLE void clear();

private:
  std::vector<ExampleItem> dataContainer;
};

#endif // EXAMPLEITEMMODEL_H
