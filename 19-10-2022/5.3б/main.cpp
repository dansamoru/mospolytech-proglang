#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int **arr, arr_size;

bool is_prime(int n);

int maxn();

void print_arr();

int main() {
    srand(time(NULL));
    cout << "Введите n: ";
    cin >> arr_size;
    arr = new int *[arr_size];
    for (int i = 0; i < arr_size; ++i) {
        arr[i] = new int[arr_size];
        for (int j = 0; j < arr_size; ++j) {
            arr[i][j] = rand() % 1000;
        }
    }
    cout << "\nМассив размера " << arr_size << ":\n";
    print_arr();
    int mn = maxn();
    if (mn == 0) {
        cout << "\nПростых чисел не имеется!";
    } else {
        cout << "\nМаксимальное простое значение массива: " << mn;
    }
    
    for (int i = 0; i < arr_size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}

// Проверка простоты числа
bool is_prime(int n) {
    int s = 0, i = 2;
    while (i <= sqrt(n) && s == 0) {
        if (n % i == 0) {
            s++;
        }
        i++;
    }
    return !s;
}

// Поиск максимального значения
int maxn() {
    int m = 0;
    for (int i = 0; i < arr_size; ++i) {
        for (int j = 0; j < arr_size; ++j) {
            if (is_prime(arr[i][j]) && arr[i][j] > m) {
                m = arr[i][j];
            }
        }
    }
    return m;
}

// Вывод массива
void print_arr() {
    for (int i = 0; i < arr_size; ++i) {
        for (int j = 0; j < arr_size; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
