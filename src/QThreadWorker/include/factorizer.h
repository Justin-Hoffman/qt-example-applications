#ifndef FACTORIZER_H
#define FACTORIZER_H
#include <string>
#include <vector>

#include <QObject>
#include <QString>
#include <QThreadPool>

Q_DECLARE_METATYPE(std::vector<unsigned int>);

class Factorizer : public QObject
{
    Q_OBJECT

  public slots:
    void factors( unsigned int n ); 

  signals:
    void factorsReady( const std::vector<unsigned int> factors );

};

#endif /* FACTORIZER_H */
