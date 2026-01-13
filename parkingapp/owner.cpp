#include "owner.h"

Owner::Owner(QObject *parent) : QObject(parent), m_id(0) {}

Owner::Owner(int id, QString name, QString phone, QString city, QObject *parent)
    : QObject(parent), m_id(id), m_name(name), m_phone(phone), m_city(city) {}

int Owner::id() const {
    return m_id;
}

QString Owner::name() const {
    return m_name;
}

QString Owner::phone() const {
    return m_phone;
}

QString Owner::city() const {
    return m_city;
}

void Owner::setName(const QString &name) {
    if (m_name != name) {
        m_name = name;
        emit nameChanged();
    }
}

void Owner::setPhone(const QString &phone) {
    if (m_phone != phone) {
        m_phone = phone;
        emit phoneChanged();
    }
}

void Owner::setCity(const QString &city) {
    if (m_city != city) {
        m_city = city;
        emit cityChanged();
    }
}
