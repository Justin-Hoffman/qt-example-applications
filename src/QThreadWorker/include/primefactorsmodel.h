#ifndef EXAMPLEITEMMODEL_H
#define EXAMPLEITEMMODEL_H

#include <QAbstractListModel>

class PrimeFactorsModel : public QAbstractListModel
{
  Q_OBJECT

public:
  explicit PrimeFactorsModel(QObject *parent = nullptr);

  enum {
    NumberRole = Qt::UserRole,
  };

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

  virtual QHash<int, QByteArray> roleNames() const override;

public slots:
  void setFactors( const std::vector<unsigned int> factors ) { 
    emit beginResetModel();
    this->factors = factors;
    emit endResetModel();
  };

private:
  std::vector<unsigned int> factors;
};

#endif // EXAMPLEITEMMODEL_H
