#include <iostream>
#include <ctime>

using namespace std;

int main() {
    const int nstr = 4, nstb = 5;
    int b[nstr][nstb];
    int Max0 = 0, str0 = -1;
    int s0 = 0;
    srand(time(NULL));
    
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < nstr; ++i) {
        for (int j = 0; j < nstb; ++j) {
            b[i][j] = rand() % 2;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < nstr; ++i) {
        s0 = 0;
        for (int j = 0; j < nstb; ++j) {
            if (b[i][j] == 0) {
                s0++;
            }
        }
        if (s0 > Max0) {
            str0 = i;
            Max0 = s0;
        }
    }
    if (str0 == -1) {
        cout << "Нулевых элементов нет!";
    } else {
        cout << "Номер строки с наибольшим кол-вом 0: " << str0 << "(начиная с 0-й)" << endl;
    }
    return 0;
}


