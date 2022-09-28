#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float ax, ay, bx, by;
    cout << "Программа для вычисления расстояния между двумя точками" << endl;
    cout << "-------------------------" << endl;
    cout << "Введите координаты: " << endl;
    cout << "X для A: ";
    cin >> ax;
    cout << "Y для A: ";
    cin >> ay;
    cout << "X для Б: ";
    cin >> bx;
    cout << "Y для Б: ";
    cin >> by;
    cout << "-------------------------" << endl;
    
    double AB = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
    
    cout << "Расстояние между точками равно: " << endl;
    cout << setprecision(4) << AB << endl;
    return 0;
}


