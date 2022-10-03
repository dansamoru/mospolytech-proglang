#include <iostream>

using namespace std;

int main() {
    short int d = -25;
    cout << "Программа демонстрации работы цикла while" << endl;
    cout << "------------------------------" << endl;
    while (d <= 25) {
        cout << d << endl;
        d += 5;
    }
    return 0;
}
