#include <iostream>

using namespace std;

double inline plKR(double R);

int main() {
    int v;
    cout << "ВОПРОС:\n";
    cout << "Когда пиццы будет больше, если:\n";
    cout << "1) взять две радиусом 20 см\n";
    cout << "2) взять одну радиусом 30 см\n";
    cout << "Введите 1 или 2: ";
    cin >> v;
    cout << "Площадь двух пицц радиусом 20 см равна " << 2 * plKR(20) << "см^2\n";
    cout << "Площадь одной пиццы радиусом 30 см равна " << plKR(30) << "см^2\n";
    cout << "Поэтому Вы ";
    if (v == 2) {
        cout << "правы!\n";
    } else {
        cout << "не правы!\n";
    }
    return 0;
}

//  Вычисление площади окружности
double plKR(double R) {
    double PI = 3.14159265;
    return PI * R * R;
}
