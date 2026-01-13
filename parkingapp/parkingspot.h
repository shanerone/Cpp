#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <QObject>
#include <QString>

/// <summary>
/// Класс для управления информацией о парковочном месте.
/// Хранит идентификатор, номер места, тип парковки и статус занятости.
/// Наследуется от QObject для использования в Qt.
/// </summary>
class ParkingSpot : public QObject
{
    Q_OBJECT

    /// <summary>
    /// Уникальный идентификатор парковочного места (только для чтения).
    /// </summary>
    Q_PROPERTY(int id READ id NOTIFY idChanged)

    /// <summary>
    /// Номер парковочного места на стоянке.
    /// </summary>
    Q_PROPERTY(QString spotNumber READ spotNumber WRITE setSpotNumber NOTIFY spotNumberChanged)

    /// <summary>
    /// Тип парковочного места (например, "Обычное", "Инвалид", "VIP").
    /// </summary>
    Q_PROPERTY(QString spotType READ spotType WRITE setSpotType NOTIFY spotTypeChanged)

    /// <summary>
    /// Статус парковочного места (например, "Свободно", "Занято", "Зарезервировано").
    /// </summary>
    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY statusChanged)

public:
    /// <summary>
    /// Конструктор по умолчанию. Инициализирует пустой объект ParkingSpot.
    /// </summary>
    explicit ParkingSpot(QObject *parent = nullptr);

    /// <summary>
    /// Конструктор с инициализацией всех полей парковочного места.
    /// </summary>
    ParkingSpot(int id,
                QString spotNumber,
                QString spotType,
                QString status,
                QObject *parent = nullptr);

    /// <summary>
    /// Возвращает уникальный идентификатор парковочного места.
    /// </summary>
    int id() const;

    /// <summary>
    /// Возвращает номер парковочного места на стоянке.
    /// </summary>
    QString spotNumber() const;

    /// <summary>
    /// Возвращает тип парковочного места.
    /// </summary>
    QString spotType() const;

    /// <summary>
    /// Возвращает статус парковочного места.
    /// </summary>
    QString status() const;

    /// <summary>
    /// Устанавливает номер парковочного места.
    /// </summary>
    void setSpotNumber(const QString &spotNumber);

    /// <summary>
    /// Устанавливает тип парковочного места.
    /// </summary>
    void setSpotType(const QString &spotType);

    /// <summary>
    /// Устанавливает статус парковочного места.
    /// </summary>
    void setStatus(const QString &status);

signals:
    /// <summary>
    /// Сигнал об изменении идентификатора парковочного места.
    /// </summary>
    void idChanged();

    /// <summary>
    /// Сигнал об изменении номера парковочного места.
    /// </summary>
    void spotNumberChanged();

    /// <summary>
    /// Сигнал об изменении типа парковочного места.
    /// </summary>
    void spotTypeChanged();

    /// <summary>
    /// Сигнал об изменении статуса парковочного места.
    /// </summary>
    void statusChanged();

private:
    /// <summary>
    /// Уникальный идентификатор парковочного места.
    /// </summary>
    int m_id;

    /// <summary>
    /// Номер парковочного места на стоянке.
    /// </summary>
    QString m_spotNumber;

    /// <summary>
    /// Тип парковочного места.
    /// </summary>
    QString m_spotType;

    /// <summary>
    /// Статус парковочного места (Свободно/Занято/Зарезервировано).
    /// </summary>
    QString m_status;
};

#endif // PARKINGSPOT_H
