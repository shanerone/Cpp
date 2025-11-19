#include <iostream>
using namespace std;

int sum2 (int x, int y) {
    int sum;
    sum = x + y;
    if (sum >= 10 and sum <= 19) {
        return 20;
    }
    else
        return sum;

}
int main() {
    int a, b;
    cout<<"Введите x и y: ";
    if (!(cin >> a >> b)) {
            cout << "Ошибка ввода" << endl;
            return 1;
        }
    int summ = sum2(a ,b);
    cout<<summ<<endl;
    return 0;
}
