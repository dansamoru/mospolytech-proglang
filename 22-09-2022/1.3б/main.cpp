#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Введите переменные: " << endl;
    cin >> a >> b;
    
    c = a;
    a = b;
    b = c;
    
    cout << "Переменные в обратном порядке: " << a << " " << b << endl;
    return 0;
}


