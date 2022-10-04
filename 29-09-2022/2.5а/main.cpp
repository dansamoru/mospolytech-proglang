#include <iostream>

using namespace std;

int main() {
    cout << "Программа вычисления факториала целого неотрицательного числа" << endl;
    cout << "-------------------------------------------------" << endl;
    int n;
    double factorial = 1;
    cout << "Введите целое неотрицательное число: ";
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        factorial *= i;
    }
    cout << "Ответ: " << n << "! = " << factorial;
    return 0;
}
