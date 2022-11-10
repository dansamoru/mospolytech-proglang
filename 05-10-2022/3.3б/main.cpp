#include <iostream>

using namespace std;

int main() {
    int n, s = 0, *arr = (int *) malloc(0);
    cout << "Введите число: ";
    cin >> n;
    cout << "Массив: ";
    do {
        arr = (int *) realloc(arr, sizeof(int));
        arr[s] = n % 10;
        n /= 10;
        cout << arr[s++] << " ";
    } while (n > 0);
    delete[] arr;
    delete[] arr;
    return 0;
}

