#include <iostream>

using namespace std;

const unsigned short int SIZE = 10;

int main() {
    int a[SIZE], n, **arr;
    cout << "Введите массив a: ";
    for (int i = 0; i < SIZE; ++i) {
        cin >> a[i];
    }
    cout << "Введите n: ";
    cin >> n;
    arr = new int *[n];
    cout << "Введите матрицу:" << endl;
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if ((i + j) % 2 == 0) {
                for (int k = 0; k < SIZE; ++k) {
                    if (arr[i][j] == a[k]) {
                        arr[i][j] = 0;
                    }
                }
            }
        }
    }
    
    cout << "Обработанная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

