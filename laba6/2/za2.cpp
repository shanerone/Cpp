#include "za2.h"

template <typename K, typename V>
int Dictionary<K, V>::FindIndex(const K& key) const
{
    for (int i = 0; i < size; i++)
    {
        if (keys[i] == key)
            return i;
    }
    return -1;
}

template <typename K, typename V>
Dictionary<K, V>::Dictionary()
{
    keys = new K[CAPACITY];
    values = new V[CAPACITY];
    size = 0;
}

template <typename K, typename V>
Dictionary<K, V>::Dictionary(const Dictionary& other)
{
    keys = new K[CAPACITY];
    values = new V[CAPACITY];
    size = other.size;
    for (int i = 0; i < size; i++)
    {
        keys[i] = other.keys[i];
        values[i] = other.values[i];
    }
}

template <typename K, typename V>
Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary& other)
{
    if (this != &other)
    {
        delete[] keys;
        delete[] values;
        keys = new K[CAPACITY];
        values = new V[CAPACITY];
        size = other.size;
        for (int i = 0; i < size; i++)
        {
            keys[i] = other.keys[i];
            values[i] = other.values[i];
        }
    }
    return *this;
}

template <typename K, typename V>
Dictionary<K, V>::~Dictionary()
{
    delete[] keys;
    delete[] values;
}

template <typename K, typename V>
void Dictionary<K, V>::Add(const K& key, const V& value)
{
    int index = FindIndex(key);
    if (index != -1)
    {
        values[index] = value;
    }
    else if (size < CAPACITY)
    {
        keys[size] = key;
        values[size] = value;
        size++;
    }
}

template <typename K, typename V>
void Dictionary<K, V>::Remove(const K& key)
{
    int index = FindIndex(key);
    if (index != -1)
    {
        for (int i = index; i < size - 1; i++)
        {
            keys[i] = keys[i + 1];
            values[i] = values[i + 1];
        }
        size--;
    }
}

template <typename K, typename V>
bool Dictionary<K, V>::ContainsKey(const K& key) const
{
    return FindIndex(key) != -1;
}

template <typename K, typename V>
V Dictionary<K, V>::Get(const K& key) const
{
    int index = FindIndex(key);
    if (index != -1)
        return values[index];
    return V();
}

template <typename K, typename V>
int Dictionary<K, V>::GetSize() const
{
    return size;
}

template <typename K, typename V>
K Dictionary<K, V>::GetKeyAt(int index) const
{
    return keys[index];
}

template <typename K, typename V>
V Dictionary<K, V>::GetValueAt(int index) const
{
    return values[index];
}

template <typename K, typename V>
void Dictionary<K, V>::Print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << keys[i] << " : " << values[i] << std::endl;
    }
}
