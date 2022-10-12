#include <iostream>

using namespace std;

int fact(int n);

int main() {
    int n;
    cout << "Введите число для поиска факториала: ";
    cin >> n;
    cout << n << "! = " << fact(n);
    return 0;
}

// Функция поиска факториала
int fact(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

