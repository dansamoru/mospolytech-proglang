#include <iostream>

using namespace std;

int main() {
    int n, m, s = 0;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите m: ";
    cin >> m;
    for (int i = 0; i < m; ++i) {
        s += n % 10;
        n /= 10;
    }
    cout << "Сумма равняется " << s;
    return 0;
}

