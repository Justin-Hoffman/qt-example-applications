//#include "mainwindow.h"
#include <QApplication>
#include <QQmlApplicationEngine>

#include "exampleitemmodeleditable.h"
#include "examplesingleton.h"

int main(int argc, char *argv[])
{
    //Instantiate application
    QApplication exampleApp(argc, argv);

    //Register custom QML
    qmlRegisterType<ExampleItemModelEditable>("ExampleItemEditable", 0, 1, "ExampleItemModelEditable");
    QScopedPointer<ExampleSingleton> exampleSingleton(new ExampleSingleton);

    qmlRegisterSingletonInstance("ExampleSingleton", 0, 1, "ExampleSingleton", exampleSingleton.get());

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:res/main.qml")));

    if(engine.rootObjects().isEmpty())
      return -1;
    return exampleApp.exec();
}
