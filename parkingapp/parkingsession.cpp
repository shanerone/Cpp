#include "parkingsession.h"

ParkingSession::ParkingSession(QObject *parent) : Vehicle(parent), m_sessionId(0), m_spotId(0) {}

ParkingSession::ParkingSession(int sessionId, int spotId, int vehicleId, QString licensePlate,
                               QString vehicleType, int ownerId, QDateTime entryTime, QDateTime exitTime, QObject *parent)
    : Vehicle(vehicleId, licensePlate, vehicleType, ownerId, parent),
    m_sessionId(sessionId), m_spotId(spotId), m_entryTime(entryTime), m_exitTime(exitTime) {}

int ParkingSession::sessionId() const {
    return m_sessionId;
}

int ParkingSession::spotId() const {
    return m_spotId;
}

QDateTime ParkingSession::entryTime() const {
    return m_entryTime;
}

QDateTime ParkingSession::exitTime() const {
    return m_exitTime;
}

void ParkingSession::setSpotId(int spotId) {
    if (m_spotId != spotId) {
        m_spotId = spotId;
        emit spotIdChanged();
    }
}

void ParkingSession::setEntryTime(const QDateTime &entryTime) {
    if (m_entryTime != entryTime) {
        m_entryTime = entryTime;
        emit entryTimeChanged();
    }
}

void ParkingSession::setExitTime(const QDateTime &exitTime) {
    if (m_exitTime != exitTime) {
        m_exitTime = exitTime;
        emit exitTimeChanged();
    }
}
