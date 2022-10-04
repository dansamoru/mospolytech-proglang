#include <iostream>

using namespace std;

int main() {
    const int n = 5;
    int a[n];
    cout << "Введите массив:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "Целочисленный массив a:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    return 0;
}
