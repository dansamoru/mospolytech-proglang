#include <iostream>

using namespace std;

int main() {
    unsigned char mask = 0b1000000;
    unsigned char n;
    cout << "Введите число: ";
    cin >> n;
    n = (n - '0') | mask;
    cout << "Изменённое число: " << int(n);
    return 0;
}

