#include <iostream>
#include <string>
#include "za2.cpp"



struct PriceData
{
    int minPrice;
    int count;
};

int main()
{
    using namespace std;    
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Dictionary<int, PriceData> prices;

    PriceData init;
    init.minPrice = INT_MAX;
    init.count = 0;

    prices.Add(15, init);
    prices.Add(20, init);
    prices.Add(25, init);

    int n;
    cout << "Введите количество магазинов: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string firma, ulica;
        int zhirnost, cena;

        cout << "Магазин " << (i + 1) << " (Фирма Улица Жирность Цена): ";
        cin >> firma >> ulica >> zhirnost >> cena;

        if (zhirnost == 15 || zhirnost == 20 || zhirnost == 25)
        {
            PriceData data = prices.Get(zhirnost);

            if (cena < data.minPrice)
            {
                data.minPrice = cena;
                data.count = 1;
            }
            else if (cena == data.minPrice)
            {
                data.count++;
            }

            prices.Add(zhirnost, data);
        }
    }

    PriceData p15 = prices.Get(15);
    PriceData p20 = prices.Get(20);
    PriceData p25 = prices.Get(25);

    int c15 = (p15.minPrice == INT_MAX) ? 0 : p15.count;
    int c20 = (p20.minPrice == INT_MAX) ? 0 : p20.count;
    int c25 = (p25.minPrice == INT_MAX) ? 0 : p25.count;

    cout << "\n" << c15 << " " << c20 << " " << c25 << endl;

    return 0;
}
