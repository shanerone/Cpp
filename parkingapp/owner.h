#ifndef OWNER_H
#define OWNER_H

#include <QObject>
#include <QString>

/// <summary>
/// Класс для управления информацией о владельце транспортного средства.
/// Хранит данные о владельце: ФИО, контактный номер телефона и город проживания.
/// Наследуется от QObject для использования в Qt (сигналы, свойства, QML-биндинг).
/// </summary>
class Owner : public QObject
{
    Q_OBJECT

    /// <summary>
    /// Уникальный идентификатор владельца (только для чтения).
    /// </summary>
    Q_PROPERTY(int id READ id NOTIFY idChanged)

    /// <summary>
    /// Полное имя (ФИО) владельца транспортного средства.
    /// </summary>
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

    /// <summary>
    /// Номер телефона владельца для связи.
    /// </summary>
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)

    /// <summary>
    /// Город проживания владельца.
    /// </summary>
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)

public:
    /// <summary>
    /// Конструктор по умолчанию. Инициализирует пустой объект Owner.
    /// </summary>
    explicit Owner(QObject *parent = nullptr);

    /// <summary>
    /// Конструктор с инициализацией всех полей владельца.
    /// </summary>
    Owner(int id,
          QString name,
          QString phone,
          QString city,
          QObject *parent = nullptr);

    /// <summary>
    /// Возвращает уникальный идентификатор владельца.
    /// </summary>
    int id() const;

    /// <summary>
    /// Возвращает полное имя (ФИО) владельца.
    /// </summary>
    QString name() const;

    /// <summary>
    /// Возвращает номер телефона владельца.
    /// </summary>
    QString phone() const;

    /// <summary>
    /// Возвращает город проживания владельца.
    /// </summary>
    QString city() const;

    /// <summary>
    /// Устанавливает новое имя (ФИО) владельца.
    /// </summary>
    void setName(const QString &name);

    /// <summary>
    /// Устанавливает новый номер телефона владельца.
    /// </summary>
    void setPhone(const QString &phone);

    /// <summary>
    /// Устанавливает новый город проживания владельца.
    /// </summary>
    void setCity(const QString &city);

signals:
    /// <summary>
    /// Сигнал об изменении идентификатора владельца.
    /// </summary>
    void idChanged();

    /// <summary>
    /// Сигнал об изменении имени (ФИО) владельца.
    /// </summary>
    void nameChanged();

    /// <summary>
    /// Сигнал об изменении номера телефона владельца.
    /// </summary>
    void phoneChanged();

    /// <summary>
    /// Сигнал об изменении города проживания владельца.
    /// </summary>
    void cityChanged();

private:
    /// <summary>
    /// Уникальный идентификатор владельца.
    /// </summary>
    int m_id;

    /// <summary>
    /// Полное имя (ФИО) владельца.
    /// </summary>
    QString m_name;

    /// <summary>
    /// Номер телефона владельца.
    /// </summary>
    QString m_phone;

    /// <summary>
    /// Город проживания владельца.
    /// </summary>
    QString m_city;
};

#endif // OWNER_H
