#pragma once
#include <iostream>

/// <summary>
/// Шаблонный класс для реализации неупорядоченного списка с уникальными элементами.
/// Элементы хранятся в массиве, доступ по индексу запрещен.
/// </summary>
/// <typeparam name="T">Тип данных элементов в коллекции</typeparam>
template <typename T>
class HashSet
{
private:
    static const int CAPACITY = 100;
    T* data;
    int size;

    /// <summary>
    /// Проверяет, существует ли элемент в коллекции
    /// </summary>
    bool FindElement(const T& element) const;

public:
    /// <summary>
    /// Конструктор по умолчанию. Инициализирует пустую коллекцию.
    /// </summary>
    HashSet();

    /// <summary>
    /// Конструктор копирования. Создает глубокую копию коллекции.
    /// </summary>
    HashSet(const HashSet& other);

    /// <summary>
    /// Оператор присваивания. Копирует содержимое коллекции.
    /// </summary>
    HashSet& operator=(const HashSet& other);

    /// <summary>
    /// Деструктор. Освобождает память.
    /// </summary>
    ~HashSet();

    /// <summary>
    /// Добавляет элемент в коллекцию. Дубликаты не добавляются.
    /// </summary>
    /// <param name="element">Добавляемый элемент</param>
    void Add(const T& element);

    /// <summary>
    /// Удаляет элемент из коллекции.
    /// </summary>
    /// <param name="element">Удаляемый элемент</param>
    void Remove(const T& element);

    /// <summary>
    /// Проверяет наличие элемента в коллекции.
    /// </summary>
    /// <param name="element">Элемент для проверки</param>
    /// <returns>true если элемент присутствует, false иначе</returns>
    bool Contains(const T& element) const;

    /// <summary>
    /// Объединяет две коллекции. Результат содержит все уникальные элементы обеих.
    /// </summary>
    /// <param name="other">Вторая коллекция</param>
    /// <returns>Новая коллекция с объединением</returns>
    HashSet Union(const HashSet& other) const;

    /// <summary>
    /// Удаляет из текущей коллекции элементы, которые есть во второй.
    /// </summary>
    /// <param name="other">Коллекция, элементы которой нужно удалить</param>
    /// <returns>Новая коллекция - разность</returns>
    HashSet Except(const HashSet& other) const;

    /// <summary>
    /// Получает пересечение двух коллекций (только общие элементы).
    /// </summary>
    /// <param name="other">Вторая коллекция</param>
    /// <returns>Новая коллекция с общими элементами</returns>
    HashSet Intersect(const HashSet& other) const;

    /// <summary>
    /// Возвращает количество элементов в коллекции.
    /// </summary>
    /// <returns>Размер коллекции</returns>
    int GetSize() const;

    /// <summary>
    /// Выводит все элементы коллекции на экран.
    /// </summary>
    void Print() const;

    /// <summary>
    /// Возвращает элемент по индексу.
    /// </summary>
    /// <param name="index">Индекс элемента</param>
    /// <returns>Элемент на позиции index</returns>
    T Get(int index) const;
};
