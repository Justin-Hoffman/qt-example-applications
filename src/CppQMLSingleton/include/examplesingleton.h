#include <string>

#include <QObject>
#include <QString>
#include <qqml.h>

class ExampleSingleton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged )

public:
    ExampleSingleton() :
      _mName("A Named Singleton"),
      _mColor("#0047AB"){}; 
    
    QString color() const ;
    void setColor( const QString &color );
    
    QString name() const ;
    void setName( const QString &name );
    

signals:
    void colorChanged( const QString &newName );
    void nameChanged( const QString &newName );

private:
    std::string _mName;
    std::string _mColor;
};
