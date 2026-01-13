#include "vehicle.h"

Vehicle::Vehicle(QObject *parent) : QObject(parent), m_id(0), m_ownerId(0) {}

Vehicle::Vehicle(int id, QString licensePlate, QString vehicleType, int ownerId, QObject *parent)
    : QObject(parent), m_id(id), m_licensePlate(licensePlate), m_vehicleType(vehicleType), m_ownerId(ownerId) {}

int Vehicle::id() const {
    return m_id;
}

QString Vehicle::licensePlate() const {
    return m_licensePlate;
}

QString Vehicle::vehicleType() const {
    return m_vehicleType;
}

int Vehicle::ownerId() const {
    return m_ownerId;
}

void Vehicle::setLicensePlate(const QString &licensePlate) {
    if (m_licensePlate != licensePlate) {
        m_licensePlate = licensePlate;
        emit licensePlateChanged();
    }
}

void Vehicle::setVehicleType(const QString &vehicleType) {
    if (m_vehicleType != vehicleType) {
        m_vehicleType = vehicleType;
        emit vehicleTypeChanged();
    }
}

void Vehicle::setOwnerId(int ownerId) {
    if (m_ownerId != ownerId) {
        m_ownerId = ownerId;
        emit ownerIdChanged();
    }
}
