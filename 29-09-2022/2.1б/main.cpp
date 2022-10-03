#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите число: " << endl;
    cin >> n;
    if (n % 2 == 0) {
        cout << "Число чётно";
    } else {
        cout << "Число нечётно";
    }
    return 0;
}

