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

QString ExampleSingleton::color() const {
  return QString::fromUtf8(_mColor.data(), _mColor.size());
}

void ExampleSingleton::setColor( const QString &color ) {
  if ( _mColor != color.toStdString() ){
    _mColor = color.toStdString();
    emit colorChanged( color );
  }
}
