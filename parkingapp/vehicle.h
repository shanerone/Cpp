#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include <QString>

/// <summary>
/// Класс для управления информацией об автомобиле.
/// Хранит идентификатор, госномер, тип транспортного средства
/// и идентификатор владельца. Наследуется от QObject для использования в Qt.
/// </summary>
class Vehicle : public QObject
{
    Q_OBJECT

    /// <summary>
    /// Уникальный идентификатор автомобиля (только для чтения).
    /// </summary>
    Q_PROPERTY(int id READ id NOTIFY idChanged)

    /// <summary>
    /// Государственный регистрационный номер автомобиля.
    /// </summary>
    Q_PROPERTY(QString licensePlate READ licensePlate WRITE setLicensePlate NOTIFY licensePlateChanged)

    /// <summary>
    /// Тип транспортного средства (например, "Легковой", "Грузовой").
    /// </summary>
    Q_PROPERTY(QString vehicleType READ vehicleType WRITE setVehicleType NOTIFY vehicleTypeChanged)

    /// <summary>
    /// Идентификатор владельца автомобиля.
    /// </summary>
    Q_PROPERTY(int ownerId READ ownerId WRITE setOwnerId NOTIFY ownerIdChanged)

public:
    /// <summary>
    /// Конструктор по умолчанию. Инициализирует пустой объект Vehicle.
    /// </summary>
    explicit Vehicle(QObject *parent = nullptr);

    /// <summary>
    /// Конструктор с инициализацией всех полей автомобиля.
    /// </summary>
    Vehicle(int id,
            QString licensePlate,
            QString vehicleType,
            int ownerId,
            QObject *parent = nullptr);

    /// <summary>
    /// Возвращает уникальный идентификатор автомобиля.
    /// </summary>
    int id() const;

    /// <summary>
    /// Возвращает государственный регистрационный номер автомобиля.
    /// </summary>
    QString licensePlate() const;

    /// <summary>
    /// Возвращает тип транспортного средства.
    /// </summary>
    QString vehicleType() const;

    /// <summary>
    /// Возвращает идентификатор владельца автомобиля.
    /// </summary>
    int ownerId() const;

    /// <summary>
    /// Устанавливает государственный номер автомобиля.
    /// </summary>
    void setLicensePlate(const QString &licensePlate);

    /// <summary>
    /// Устанавливает тип транспортного средства.
    /// </summary>
    void setVehicleType(const QString &vehicleType);

    /// <summary>
    /// Устанавливает идентификатор владельца автомобиля.
    /// </summary>
    void setOwnerId(int ownerId);

signals:
    /// <summary>
    /// Сигнал об изменении идентификатора автомобиля.
    /// </summary>
    void idChanged();

    /// <summary>
    /// Сигнал об изменении государственного номера автомобиля.
    /// </summary>
    void licensePlateChanged();

    /// <summary>
    /// Сигнал об изменении типа транспортного средства.
    /// </summary>
    void vehicleTypeChanged();

    /// <summary>
    /// Сигнал об изменении идентификатора владельца.
    /// </summary>
    void ownerIdChanged();

private:
    /// <summary>
    /// Уникальный идентификатор автомобиля.
    /// </summary>
    int m_id;

    /// <summary>
    /// Государственный регистрационный номер автомобиля.
    /// </summary>
    QString m_licensePlate;

    /// <summary>
    /// Тип транспортного средства.
    /// </summary>
    QString m_vehicleType;

    /// <summary>
    /// Идентификатор владельца автомобиля.
    /// </summary>
    int m_ownerId;
};

#endif // VEHICLE_H
