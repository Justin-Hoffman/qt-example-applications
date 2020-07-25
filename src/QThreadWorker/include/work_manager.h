#ifndef WORK_MANAGER_H
#define WORK_MANAGER_H
#include <string>
#include <vector>

#include <QObject>
#include <QString>
#include <QThreadPool>

#include "factorizer.h"

class WorkManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned int number READ number WRITE setNumber NOTIFY numberChanged )
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged )

  public:
    WorkManager(); 
    
    QString color() const ;
    void setColor( const QString &color );
    
    QString name() const ;
    void setName( const QString &name );
    
    unsigned int number() const { return _mInteger; };
    void setNumber( const unsigned int n ) { _mInteger = n; };

    const std::vector<unsigned int> factor( unsigned int n ); 

  signals:
    void colorChanged( const QString &newName );
    void nameChanged( const QString &newName );
    void numberChanged( const unsigned int n );
    void factors( unsigned int n );
    void factorsReady( const std::vector<unsigned int> factors );

  public slots: 
    void handleFactors( const std::vector<unsigned int> factors ) { _mFactors = factors; emit factorsReady( _mFactors ); };

  private:
    std::string _mName;
    std::string _mColor;
    Factorizer* _mFactorizer; 
    
    unsigned int _mInteger;
    std::vector<unsigned int> _mFactors;
};
#endif /* WORK_MANAGER_H */
