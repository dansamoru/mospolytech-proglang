#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Программа определения простого числа" << endl;
    cout << "---------------------------" << endl;
    int n;
    do {
        int s = 0, i = 2;
        cout << "Введите натуральное число (0-выход): ";
        cin >> n;
        if (n == 1) {
            cout << "1 не является простым или составным";
        }
        while (i <= sqrt(n) && s == 0) {
            if (n % i == 0) {
                s++;
            }
            i++;
        }
        if (s == 0) {
            cout << "Число простое!" << endl;
        } else {
            cout << "Число составное!" << endl;
        }
    } while (n != 0);
    return 0;
}

