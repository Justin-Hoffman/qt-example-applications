#include "examplesingleton.h"

QString ExampleSingleton::name() const {
  return QString::fromUtf8(_mName.data(), _mName.size());
}

void ExampleSingleton::setName( const QString &name ) {
  if ( _mName != name.toStdString() ){
    _mName = name.toStdString();
    emit nameChanged( name );
  }
}
