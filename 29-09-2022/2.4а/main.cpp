#include <iostream>
#include <ctime>

using namespace std;

int main() {
    cout << "Угадай число!" << endl;
    cout << "---------------------------" << endl;
    int n, rn;
    srand(time(NULL));
    do {
        rn = rand() % 10 + 1;
        cout << "Введите натуральное число от 1 до 10 (0-выход): ";
        cin >> n;
        if (n == rn) {
            cout << "Ура! Вы угадали!" << endl << endl;
        } else {
            if (n != 0) {
                cout << "Упс!... Попробуйте ещё раз!" << endl;
            }
        }
    } while (n != 0);
    return 0;
}
