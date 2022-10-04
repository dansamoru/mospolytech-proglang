#include <iostream>

using namespace std;

int main() {
    cout << "Программа демонстрации работы не цикла while" << endl;
    cout << "------------------------------" << endl;
    for (int d = -25; d <= 25; ++d) {
        cout << d << endl;
        d += 5;
    }
    return 0;
}
