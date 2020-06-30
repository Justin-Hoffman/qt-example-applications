#include <string>

#include <QObject>
#include <QString>
#include <qqml.h>

class ExampleSingleton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged )

public:
    ExampleSingleton() :
      _mName("A Named Singleton") {}; 
    QString name() const ;
    void setName( const QString &name );

signals:
    void nameChanged( const QString &newName );

private:
    std::string _mName;
};
