#pragma once
#include <iostream>

/// <summary>
/// Шаблонный класс для реализации словаря (ключ-значение).
/// Ключи должны быть уникальными.
/// </summary>
/// <typeparam name="K">Тип ключа</typeparam>
/// <typeparam name="V">Тип значения</typeparam>
template <typename K, typename V>
class Dictionary
{
private:
    static const int CAPACITY = 100;
    K* keys;
    V* values;
    int size;

    /// <summary>
    /// Находит индекс по ключу.
    /// </summary>
    int FindIndex(const K& key) const;

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    Dictionary();

    /// <summary>
    /// Конструктор копирования.
    /// </summary>
    Dictionary(const Dictionary& other);

    /// <summary>
    /// Оператор присваивания.
    /// </summary>
    Dictionary& operator=(const Dictionary& other);

    /// <summary>
    /// Деструктор.
    /// </summary>
    ~Dictionary();

    /// <summary>
    /// Добавляет или обновляет пару ключ-значение.
    /// </summary>
    void Add(const K& key, const V& value);

    /// <summary>
    /// Удаляет пару по ключу.
    /// </summary>
    void Remove(const K& key);

    /// <summary>
    /// Проверяет наличие ключа.
    /// </summary>
    bool ContainsKey(const K& key) const;

    /// <summary>
    /// Получает значение по ключу.
    /// </summary>
    V Get(const K& key) const;

    /// <summary>
    /// Возвращает количество пар.
    /// </summary>
    int GetSize() const;

    /// <summary>
    /// Получает ключ по индексу.
    /// </summary>
    K GetKeyAt(int index) const;

    /// <summary>
    /// Получает значение по индексу.
    /// </summary>
    V GetValueAt(int index) const;

    /// <summary>
    /// Выводит все пары.
    /// </summary>
    void Print() const;
};
