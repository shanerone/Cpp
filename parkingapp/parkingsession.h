#ifndef PARKINGSESSION_H
#define PARKINGSESSION_H

#include "vehicle.h"
#include <QDateTime>
#include <QObject>

/// <summary>
/// Класс для управления сеансом парковки.
/// Наследует информацию об автомобиле от класса Vehicle и добавляет
/// данные о парковочном месте и времени начала/окончания сеанса парковки.
/// </summary>
class ParkingSession : public Vehicle
{
    Q_OBJECT

    /// <summary>
    /// Уникальный идентификатор сеанса парковки (только для чтения).
    /// </summary>
    Q_PROPERTY(int sessionId READ sessionId NOTIFY sessionIdChanged)

    /// <summary>
    /// Идентификатор парковочного места, на котором припаркован автомобиль.
    /// </summary>
    Q_PROPERTY(int spotId READ spotId WRITE setSpotId NOTIFY spotIdChanged)

    /// <summary>
    /// Дата и время начала сеанса парковки.
    /// </summary>
    Q_PROPERTY(QDateTime entryTime READ entryTime WRITE setEntryTime NOTIFY entryTimeChanged)

    /// <summary>
    /// Дата и время окончания сеанса парковки (или пусто, если автомобиль ещё припаркован).
    /// </summary>
    Q_PROPERTY(QDateTime exitTime READ exitTime WRITE setExitTime NOTIFY exitTimeChanged)

public:
    /// <summary>
    /// Конструктор по умолчанию. Инициализирует пустой объект ParkingSession.
    /// </summary>
    explicit ParkingSession(QObject *parent = nullptr);

    /// <summary>
    /// Конструктор с инициализацией всех полей сеанса парковки и данных автомобиля.
    /// </summary>
    ParkingSession(int sessionId,
                   int spotId,
                   int vehicleId,
                   QString licensePlate,
                   QString vehicleType,
                   int ownerId,
                   QDateTime entryTime,
                   QDateTime exitTime,
                   QObject *parent = nullptr);

    /// <summary>
    /// Возвращает уникальный идентификатор сеанса парковки.
    /// </summary>
    int sessionId() const;

    /// <summary>
    /// Возвращает идентификатор парковочного места.
    /// </summary>
    int spotId() const;

    /// <summary>
    /// Возвращает дату и время начала сеанса парковки.
    /// </summary>
    QDateTime entryTime() const;

    /// <summary>
    /// Возвращает дату и время окончания сеанса парковки.
    /// Если сеанс ещё активен, может быть пустым (null) значением.
    /// </summary>
    QDateTime exitTime() const;

    /// <summary>
    /// Устанавливает идентификатор парковочного места.
    /// </summary>
    void setSpotId(int spotId);

    /// <summary>
    /// Устанавливает дату и время начала сеанса парковки.
    /// </summary>
    void setEntryTime(const QDateTime &entryTime);

    /// <summary>
    /// Устанавливает дату и время окончания сеанса парковки.
    /// </summary>
    void setExitTime(const QDateTime &exitTime);

signals:
    /// <summary>
    /// Сигнал об изменении идентификатора сеанса парковки.
    /// </summary>
    void sessionIdChanged();

    /// <summary>
    /// Сигнал об изменении идентификатора парковочного места.
    /// </summary>
    void spotIdChanged();

    /// <summary>
    /// Сигнал об изменении времени начала сеанса парковки.
    /// </summary>
    void entryTimeChanged();

    /// <summary>
    /// Сигнал об изменении времени окончания сеанса парковки.
    /// </summary>
    void exitTimeChanged();

private:
    /// <summary>
    /// Уникальный идентификатор сеанса парковки.
    /// </summary>
    int m_sessionId;

    /// <summary>
    /// Идентификатор парковочного места.
    /// </summary>
    int m_spotId;

    /// <summary>
    /// Дата и время начала сеанса парковки.
    /// </summary>
    QDateTime m_entryTime;

    /// <summary>
    /// Дата и время окончания сеанса парковки.
    /// </summary>
    QDateTime m_exitTime;
};

#endif // PARKINGSESSION_H
