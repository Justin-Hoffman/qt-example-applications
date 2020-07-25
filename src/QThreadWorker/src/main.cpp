//#include "mainwindow.h"
#include <QApplication>
#include <QQmlApplicationEngine>

#include "work_manager.h"
#include "primefactorsmodel.h"

int main(int argc, char *argv[])
{
    //Instantiate application
    QApplication exampleApp(argc, argv);

    QScopedPointer<WorkManager> workManager(new WorkManager);
    qmlRegisterSingletonInstance("QThreadWorker", 0, 1, "WorkManager", workManager.get());
    
    qmlRegisterType<PrimeFactorsModel>("QThreadWorker", 0, 1, "PrimeFactorsModel");

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:res/main.qml")));

    if(engine.rootObjects().isEmpty())
      return -1;
    
    PrimeFactorsModel *model = engine.rootObjects()[0]->findChild<PrimeFactorsModel*>("factors_model");
    QObject::connect(workManager.get(), SIGNAL(factorsReady( const std::vector<unsigned int> )), model, SLOT(setFactors( const std::vector<unsigned int> )));
    return exampleApp.exec();
}
