#ifndef PARKINGMANAGER_H
#define PARKINGMANAGER_H

#include <QObject>
#include <QQmlListProperty>
#include "parkingspot.h"
#include "owner.h"
#include "vehicle.h"
#include "parkingsession.h"

class ParkingManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<ParkingSpot> parkingSpots READ parkingSpots NOTIFY parkingSpotsChanged)
    Q_PROPERTY(QQmlListProperty<Owner> owners READ owners NOTIFY ownersChanged)
    Q_PROPERTY(QQmlListProperty<Vehicle> vehicles READ vehicles NOTIFY vehiclesChanged)
    Q_PROPERTY(QQmlListProperty<ParkingSession> parkingSessions READ parkingSessions NOTIFY parkingSessionsChanged)

public:
    explicit ParkingManager(QObject *parent = nullptr);

    QQmlListProperty<ParkingSpot> parkingSpots();
    QQmlListProperty<Owner> owners();
    QQmlListProperty<Vehicle> vehicles();
    QQmlListProperty<ParkingSession> parkingSessions();

    Q_INVOKABLE void addParkingSpot(const QString &spotNumber, const QString &spotType, const QString &status);
    Q_INVOKABLE void addOwner(const QString &name, const QString &phone, const QString &city);
    Q_INVOKABLE void addVehicle(const QString &licensePlate, const QString &vehicleType, int ownerId);
    Q_INVOKABLE void addParkingSession(int spotId, int vehicleId, const QString &licensePlate,
                                       const QString &vehicleType, int ownerId, const QDateTime &entryTime);

    Q_INVOKABLE void updateParkingSpot(int index, const QString &status);
    Q_INVOKABLE void updateOwner(int index, const QString &name, const QString &phone, const QString &city);
    Q_INVOKABLE void endParkingSession(int index, const QDateTime &exitTime);

    Q_INVOKABLE void deleteParkingSpot(int index);
    Q_INVOKABLE void deleteOwner(int index);
    Q_INVOKABLE void deleteVehicle(int index);
    Q_INVOKABLE void deleteParkingSession(int index);

    Q_INVOKABLE QString getStatistics();

signals:
    void parkingSpotsChanged();
    void ownersChanged();
    void vehiclesChanged();
    void parkingSessionsChanged();

private:
    QList<ParkingSpot*> m_parkingSpots;
    QList<Owner*> m_owners;
    QList<Vehicle*> m_vehicles;
    QList<ParkingSession*> m_parkingSessions;

    int m_nextSpotId = 1;
    int m_nextOwnerId = 1;
    int m_nextVehicleId = 1;
    int m_nextSessionId = 1;
};

#endif // PARKINGMANAGER_H
