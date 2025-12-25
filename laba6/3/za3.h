#pragma once
#include <iostream>

/// <summary>
/// Базовый класс двумерной точки.
/// </summary>
class Point
{
protected:
    double x;
    double y;

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    Point();

    /// <summary>
    /// Конструктор с параметрами.
    /// </summary>
    Point(double x, double y);

    /// <summary>
    /// Деструктор.
    /// </summary>
    virtual ~Point();

    /// <summary>
    /// Выводит координаты.
    /// </summary>
    virtual void Print() const;
};

/// <summary>
/// Трехмерная точка. Наследует Point и добавляет координату Z.
/// </summary>
class Point3D : public Point
{
private:
    double z;

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    Point3D();

    /// <summary>
    /// Конструктор с параметрами.
    /// </summary>
    Point3D(double x, double y, double z);

    /// <summary>
    /// Деструктор.
    /// </summary>
    ~Point3D();

    /// <summary>
    /// Вычисляет расстояние между двумя точками.
    /// </summary>
    double Distance(const Point3D& other) const;

    /// <summary>
    /// Выводит координаты.
    /// </summary>
    void Print() const override;
};
