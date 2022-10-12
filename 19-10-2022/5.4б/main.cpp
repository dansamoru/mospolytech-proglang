#include <iostream>

using namespace std;

int n, *arr;

void qs(int *s_arr, int f, int l);

int main() {
    cout << "Введи размер массива: ";
    cin >> n;
    arr = new int[n];
    cout << "Введи массив: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    qs(arr, 0, n - 1);
    cout << "Сортированный массива: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}

// Быстрая сортировка
void qs(int *s_arr, int f, int l) {
    int i = f, j = l, m = s_arr[(f + l) / 2];
    do {
        while (s_arr[i] < m) {
            i++;
        }
        while (s_arr[j] > m) {
            j--;
        }
        if (i <= j) {
            if (s_arr[i] > s_arr[j]) {
                swap(s_arr[i], s_arr[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);
    
    if (i < l) {
        qs(s_arr, i, l);
    }
    if (f < j) {
        qs(s_arr, f, j);
    }
}
