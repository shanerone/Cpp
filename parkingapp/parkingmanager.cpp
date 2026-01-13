#include "parkingmanager.h"
#include <QDebug>
#include <QDateTime>

ParkingManager::ParkingManager(QObject *parent) : QObject(parent) {
    addOwner("Иванов Иван Иванович", "+79001234567", "Москва");
    addOwner("Петров Петр Петрович", "+79009876543", "Санкт-Петербург");
    addParkingSpot("A001", "Обычное", "Свободно");
    addParkingSpot("C001", "Инвалид", "Свободно");
    addVehicle("A123BC177", "Легковой", 1);
    addVehicle("B456DE178", "Внедорожник", 2);
}

QQmlListProperty<ParkingSpot> ParkingManager::parkingSpots() {
    return QQmlListProperty<ParkingSpot>(this, &m_parkingSpots);
}

QQmlListProperty<Owner> ParkingManager::owners() {
    return QQmlListProperty<Owner>(this, &m_owners);
}

QQmlListProperty<Vehicle> ParkingManager::vehicles() {
    return QQmlListProperty<Vehicle>(this, &m_vehicles);
}

QQmlListProperty<ParkingSession> ParkingManager::parkingSessions() {
    return QQmlListProperty<ParkingSession>(this, &m_parkingSessions);
}

void ParkingManager::addParkingSpot(const QString &spotNumber, const QString &spotType, const QString &status) {
    ParkingSpot* spot = new ParkingSpot(m_nextSpotId++, spotNumber, spotType, status, this);
    m_parkingSpots.append(spot);
    emit parkingSpotsChanged();
    qDebug() << "Добавлено парковочное место:" << spotNumber;
}

void ParkingManager::addOwner(const QString &name, const QString &phone, const QString &city) {
    Owner* owner = new Owner(m_nextOwnerId++, name, phone, city, this);
    m_owners.append(owner);
    emit ownersChanged();
    qDebug() << "Добавлен владелец:" << name;
}

void ParkingManager::addVehicle(const QString &licensePlate, const QString &vehicleType, int ownerId) {
    Vehicle* vehicle = new Vehicle(m_nextVehicleId++, licensePlate, vehicleType, ownerId, this);
    m_vehicles.append(vehicle);
    emit vehiclesChanged();
    qDebug() << "Добавлено ТС:" << licensePlate;
}

void ParkingManager::addParkingSession(int spotId, int vehicleId, const QString &licensePlate,
                                       const QString &vehicleType, int ownerId, const QDateTime &entryTime) {
    ParkingSession* session = new ParkingSession(m_nextSessionId++, spotId, vehicleId,
                                                 licensePlate, vehicleType, ownerId, entryTime, QDateTime(), this);
    m_parkingSessions.append(session);
    
    for (int i = 0; i < m_parkingSpots.size(); i++) {
        if (m_parkingSpots[i]->id() == spotId) {
            m_parkingSpots[i]->setStatus("Занято");
            break;
        }
    }
    
    emit parkingSessionsChanged();
    qDebug() << "Начата парковочная сессия для ТС:" << licensePlate;
}

void ParkingManager::endParkingSession(int index, const QDateTime &exitTime) {
    if (index >= 0 && index < m_parkingSessions.size()) {
        m_parkingSessions[index]->setExitTime(exitTime);
        
        // Освобождаем парковочное место
        int spotId = m_parkingSessions[index]->spotId();
        for (int i = 0; i < m_parkingSpots.size(); i++) {
            if (m_parkingSpots[i]->id() == spotId) {
                m_parkingSpots[i]->setStatus("Свободно");
                break;
            }
        }
        
        emit parkingSessionsChanged();
        qDebug() << "Завершена парковочная сессия";
    }
}

QString ParkingManager::getStatistics() {
    int totalSpots = m_parkingSpots.size();
    int freeSpots = 0;
    for (int i = 0; i < m_parkingSpots.size(); i++) {
        if (m_parkingSpots[i]->status() == "Свободно") freeSpots++;
    }
    
    return QString("Всего мест: %1\nСвободно: %2\nЗанято: %3")
        .arg(totalSpots).arg(freeSpots).arg(totalSpots - freeSpots);
}

void ParkingManager::updateParkingSpot(int index, const QString &status) {
    if (index >= 0 && index < m_parkingSpots.size()) {
        m_parkingSpots[index]->setStatus(status);
        emit parkingSpotsChanged();
        qDebug() << "Обновлено парковочное место с индексом:" << index;
    }
}

void ParkingManager::updateOwner(int index, const QString &name, const QString &phone, const QString &city) {
    if (index >= 0 && index < m_owners.size()) {
        m_owners[index]->setName(name);
        m_owners[index]->setPhone(phone);
        m_owners[index]->setCity(city);
        emit ownersChanged();
        qDebug() << "Обновлен владелец с индексом:" << index;
    }
}

void ParkingManager::deleteParkingSpot(int index) {
    if (index >= 0 && index < m_parkingSpots.size()) {
        // Проверяем, нет ли активных сессий на этом месте
        int spotId = m_parkingSpots[index]->id();
        bool hasActiveSession = false;
        for (int i = 0; i < m_parkingSessions.size(); i++) {
            if (m_parkingSessions[i]->spotId() == spotId && !m_parkingSessions[i]->exitTime().isValid()) {
                hasActiveSession = true;
                break;
            }
        }
        
        if (!hasActiveSession) {
            delete m_parkingSpots.takeAt(index);
            emit parkingSpotsChanged();
            qDebug() << "Удалено парковочное место с индексом:" << index;
        } else {
            qDebug() << "Нельзя удалить место: есть активная парковочная сессия";
        }
    }
}

void ParkingManager::deleteOwner(int index) {
    if (index >= 0 && index < m_owners.size()) {
        // Проверяем, нет ли транспортных средств у этого владельца
        int ownerId = m_owners[index]->id();
        bool hasVehicles = false;
        for (int i = 0; i < m_vehicles.size(); i++) {
            if (m_vehicles[i]->ownerId() == ownerId) {
                hasVehicles = true;
                break;
            }
        }
        
        if (!hasVehicles) {
            delete m_owners.takeAt(index);
            emit ownersChanged();
            qDebug() << "Удален владелец с индексом:" << index;
        } else {
            qDebug() << "Нельзя удалить владельца: есть зарегистрированные ТС";
        }
    }
}

void ParkingManager::deleteVehicle(int index) {
    if (index >= 0 && index < m_vehicles.size()) {
        // Проверяем, нет ли активной сессии у этого ТС
        int vehicleId = m_vehicles[index]->id();
        bool hasActiveSession = false;
        for (int i = 0; i < m_parkingSessions.size(); i++) {
            if (m_parkingSessions[i]->id() == vehicleId && !m_parkingSessions[i]->exitTime().isValid()) {
                hasActiveSession = true;
                break;
            }
        }
        
        if (!hasActiveSession) {
            delete m_vehicles.takeAt(index);
            emit vehiclesChanged();
            qDebug() << "Удалено ТС с индексом:" << index;
        } else {
            qDebug() << "Нельзя удалить ТС: есть активная парковочная сессия";
        }
    }
}

void ParkingManager::deleteParkingSession(int index) {
    if (index >= 0 && index < m_parkingSessions.size()) {
        // Если сессия активна, освобождаем место
        if (!m_parkingSessions[index]->exitTime().isValid()) {
            int spotId = m_parkingSessions[index]->spotId();
            for (int i = 0; i < m_parkingSpots.size(); i++) {
                if (m_parkingSpots[i]->id() == spotId) {
                    m_parkingSpots[i]->setStatus("Свободно");
                    break;
                }
            }
        }
        
        delete m_parkingSessions.takeAt(index);
        emit parkingSessionsChanged();
        qDebug() << "Удалена парковочная сессия с индексом:" << index;
    }
}
