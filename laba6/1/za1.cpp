#include "za1.h"

template <typename T>
bool HashSet<T>::FindElement(const T& element) const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == element)
            return true;
    }
    return false;
}

template <typename T>
HashSet<T>::HashSet()
{
    data = new T[CAPACITY];
    size = 0;
}

template <typename T>
HashSet<T>::HashSet(const HashSet& other)
{
    data = new T[CAPACITY];
    size = other.size;
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
HashSet<T>& HashSet<T>::operator=(const HashSet& other)
{
    if (this != &other)
    {
        delete[] data;
        data = new T[CAPACITY];
        size = other.size;
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
HashSet<T>::~HashSet()
{
    delete[] data;
}

template <typename T>
void HashSet<T>::Add(const T& element)
{
    if (!FindElement(element) && size < CAPACITY)
    {
        data[size++] = element;
    }
}

template <typename T>
void HashSet<T>::Remove(const T& element)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == element)
        {
            for (int j = i; j < size - 1; j++)
            {
                data[j] = data[j + 1];
            }
            size--;
            return;
        }
    }
}

template <typename T>
bool HashSet<T>::Contains(const T& element) const
{
    return FindElement(element);
}

template <typename T>
HashSet<T> HashSet<T>::Union(const HashSet& other) const
{
    HashSet result;
    for (int i = 0; i < size; i++)
    {
        result.Add(data[i]);
    }
    for (int i = 0; i < other.size; i++)
    {
        result.Add(other.data[i]);
    }
    return result;
}

template <typename T>
HashSet<T> HashSet<T>::Except(const HashSet& other) const
{
    HashSet result;
    for (int i = 0; i < size; i++)
    {
        if (!other.Contains(data[i]))
        {
            result.Add(data[i]);
        }
    }
    return result;
}

template <typename T>
HashSet<T> HashSet<T>::Intersect(const HashSet& other) const
{
    HashSet result;
    for (int i = 0; i < size; i++)
    {
        if (other.Contains(data[i]))
        {
            result.Add(data[i]);
        }
    }
    return result;
}

template <typename T>
int HashSet<T>::GetSize() const
{
    return size;
}

template <typename T>
void HashSet<T>::Print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T HashSet<T>::Get(int index) const
{
    return data[index];
}
