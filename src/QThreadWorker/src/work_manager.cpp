#include "work_manager.h"
#include "math.h"

WorkManager::WorkManager() :
  _mName("A Named Singleton"),
  _mColor("#0047AB"),
  _mFactorizer() {

    QThread* thread = new QThread();
    _mFactorizer = new Factorizer();
    _mFactorizer->moveToThread(thread);
    qRegisterMetaType< std::vector<unsigned int> >( "std::vector<uint>" );
    connect(_mFactorizer, SIGNAL( error( QString ) ), this, SLOT( errorString( QString ) ));
    connect(_mFactorizer, SIGNAL(finished()), _mFactorizer, SIGNAL(deleteLater()));
    
    connect(this, SIGNAL(factors( uint )), _mFactorizer, SLOT(factors( uint )));
    connect(_mFactorizer, SIGNAL(factorsReady( const std::vector<unsigned int> )), this, SLOT(handleFactors(const std::vector<unsigned int> )));

    thread->start();

  };

QString WorkManager::name() const {
  return QString::fromUtf8(_mName.data(), _mName.size());
}

void WorkManager::setName( const QString &name ) {
  if ( _mName != name.toStdString() ){
    _mName = name.toStdString();
    emit nameChanged( name );
  }
}

QString WorkManager::color() const {
  return QString::fromUtf8(_mColor.data(), _mColor.size());
}

void WorkManager::setColor( const QString &color ) {
  if ( _mColor != color.toStdString() ){
    _mColor = color.toStdString();
    emit colorChanged( color );
  }
}
