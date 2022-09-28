#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Введите переменные: " << endl;
    cin >> a >> b;
    
    a += b;
    b = a - b;
    a -= b;
    
    cout << "Переменные в обратном порядке: " << a << " " << b << endl;
    return 0;
}


