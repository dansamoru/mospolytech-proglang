#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cout << "Введите длины сторон: ";
    cin >> a >> b >> c;
    cout << "Длины биссектрис для введённых сторон: " << endl;
    cout << sqrt(a * b * (a + b + c) * (a + b - c)) / (a + b) << endl;
    cout << sqrt(b * c * (b + c + a) * (b + c - a)) / (b + c) << endl;
    cout << sqrt(c * a * (c + a + b) * (c + a - b)) / (c + a) << endl;
    return 0;
}


