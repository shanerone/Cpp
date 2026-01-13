#include "parkingspot.h"

ParkingSpot::ParkingSpot(QObject *parent) : QObject(parent), m_id(0) {}

ParkingSpot::ParkingSpot(int id, QString spotNumber, QString spotType, QString status, QObject *parent)
    : QObject(parent), m_id(id), m_spotNumber(spotNumber), m_spotType(spotType), m_status(status) {}

int ParkingSpot::id() const { return m_id; }
QString ParkingSpot::spotNumber() const { return m_spotNumber; }
QString ParkingSpot::spotType() const { return m_spotType; }
QString ParkingSpot::status() const { return m_status; }

void ParkingSpot::setSpotNumber(const QString &spotNumber) {
    if (m_spotNumber != spotNumber) {
        m_spotNumber = spotNumber;
        emit spotNumberChanged();
    }
}

void ParkingSpot::setSpotType(const QString &spotType) {
    if (m_spotType != spotType) {
        m_spotType = spotType;
        emit spotTypeChanged();
    }
}

void ParkingSpot::setStatus(const QString &status) {
    if (m_status != status) {
        m_status = status;
        emit statusChanged();
    }
}
