#include <iostream>

using namespace std;

int main() {
    int n, s = 0, *arr = (int *) malloc(0);
    cout << "Введите число: ";
    cin >> n;
    do {
        arr = (int *) realloc(arr, sizeof(int));
        arr[s] = n % 10;
        n /= 10;
        s++;
    } while (n > 0);
    cout << "Массив: ";
    for (int i = 0; i < s; ++i) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}

