#include <iostream>

using namespace std;

int main() {
    int a, b, c, ma;
    cout << "Введите три числа: " << endl;
    cin >> a >> b >> c;
    if (a > b) {
        if (a > c) {
            ma = a;
        } else {
            ma = c;
        }
    } else {
        if (b > c) {
            ma = b;
        } else {
            ma = c;
        }
    }
    cout << "Максимальное число из введённых - " << ma;
    return 0;
}


