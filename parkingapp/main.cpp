#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "parkingmanager.h"
#include "parkingspot.h"
#include "owner.h"
#include "vehicle.h"
#include "parkingsession.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
\
    qmlRegisterType<ParkingManager>("com.parkingsystem", 1, 0, "ParkingManager");
    qmlRegisterType<ParkingSpot>("com.parkingsystem", 1, 0, "ParkingSpot");
    qmlRegisterType<Owner>("com.parkingsystem", 1, 0, "Owner");
    qmlRegisterType<Vehicle>("com.parkingsystem", 1, 0, "Vehicle");
    qmlRegisterType<ParkingSession>("com.parkingsystem", 1, 0, "ParkingSession");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
