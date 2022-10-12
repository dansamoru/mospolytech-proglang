#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа определения простого числа" << endl;
    cout << "---------------------------" << endl;
    int n, s = 0, i = 2;
    cout << "Введите натуральное число: ";
    cin >> n;
    if (n == 1) {
        cout << "1 не является простым или составным";
    } else {
        while (i <= sqrt(n)) {
            cout << "Итерация " << i - 1 << endl;
            if (n % i == 0) {
                s++;
            }
            i++;
        }
        if (s == 0) {
            cout << "Число простое!";
        
        } else {
            cout << "Число составное!";
        }
    }
    return 0;
}

