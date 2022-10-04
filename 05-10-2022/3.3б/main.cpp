#include <iostream>

using namespace std;

int main() {
    int n, s = 0, *arr = (int *) malloc(sizeof(int));
    cout << "Введите число: ";
    cin >> n;
    do {
        arr[s] = n % 10;
        n /= 10;
        s++;
        arr = (int *) realloc(arr, sizeof(int));
    } while (n > 0);
    return 0;
}

