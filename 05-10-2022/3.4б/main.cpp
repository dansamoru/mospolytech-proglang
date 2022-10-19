#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int nstr, nstb;
    int Max0 = 0, str0 = -1;
    int s0 = 0;
    srand(time(NULL));
    
    cout << "Введите кол-во строк: ";
    cin >> nstr;
    cout << "Введите кол-во столбцов:";
    cin >> nstb;
    
    auto **b = new int *[nstr];
    
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < nstr; ++i) {
        b[i] = new int[nstb];
        for (int j = 0; j < nstb; ++j) {
            b[i][j] = rand() % 3 - 1;
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
        free(b[i]);
    }
    if (str0 == -1) {
        cout << "Нулевых элементов нет!";
    } else {
        cout << "Номер строки с наибольшим кол-вом 0: " << str0 << " (начиная с 0-й)" << endl;
    }
    
    free(b);
    return 0;
}


