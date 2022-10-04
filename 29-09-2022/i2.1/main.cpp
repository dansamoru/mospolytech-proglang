#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x, y;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    
    if (y <= 1 - pow(x, 2) && (pow(x, 2) + pow((y - 1), 2)) <= 1) {
        cout << "Ответ: u = " << x - y;
    } else {
        cout << "Ответ: u = " << x * y + 7;
    }
    return 0;
}


