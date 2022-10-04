#include <iostream>

using namespace std;

int main() {
    int n, m, s = 0;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> m;
    for (int i = 0; i < n; ++i) {
        s += m % 10;
        m /= 10;
    }
    cout << "Сумма равняется " << s;
    return 0;
}

