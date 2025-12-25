#include <iostream>
#include <string>
#include "za1.cpp"

using namespace std;

int main()
{
    // setlocale(LC_ALL, "ru_RU.UTF-8");

    int n;
    cout << "Количество сладкоежек: ";
    cin >> n;
    cin.ignore();

    HashSet<string>* people = new HashSet<string>[n];

    // Вводим данные для каждого
    for (int i = 0; i < n; i++)
    {
        cout << "\nСладкоежка " << (i + 1) << " (вводите шоколады, 'готово' чтобы завершить):\n";
        string chocolate;
        while (true)
        {
            getline(cin, chocolate);
            if (chocolate == "готово")
                break;
            if (!chocolate.empty())
            {
                people[i].Add(chocolate);
            }
        }
    }

    if (n > 0)
    {
        // Находим пересечение (нравится ВСЕМ)
        HashSet<string> forAll = people[0];
        for (int i = 1; i < n; i++)
        {
            forAll = forAll.Intersect(people[i]);
        }

        // Находим объединение (нравится НЕКОТОРЫМ)
        HashSet<string> forSome = people[0];
        for (int i = 1; i < n; i++)
        {
            forSome = forSome.Union(people[i]);
        }

        cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;

        cout << "\nНравится ВСЕМ:\n";
        if (forAll.GetSize() == 0)
            cout << "Нет\n";
        else
            forAll.Print();

        cout << "\nНравится НЕКОТОРЫМ:\n";
        forSome.Print();

        cout << "\nДля поиска шоколадов, которые НИКОМУ не нравятся, введите все доступные (вводите, 'готово' для завершения):\n";
        HashSet<string> allExisting;
        string chocolate;
        while (true)
        {
            getline(cin, chocolate);
            if (chocolate == "готово")
                break;
            if (!chocolate.empty())
            {
                allExisting.Add(chocolate);
            }
        }

        HashSet<string> forNone = allExisting.Except(forSome);

        cout << "\nНравится НИКОМУ:\n";
        if (forNone.GetSize() == 0)
            cout << "Нет\n";
        else
            forNone.Print();
    }

    delete[] people;
    return 0;
}
