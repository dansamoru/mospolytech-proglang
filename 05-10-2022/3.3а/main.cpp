#include <iostream>

using namespace std;

int main() {
    int n, i, imin;
    cout << "Задайте размер линейного массива = ";
    cin >> n;
    int *arr = new int[n];
    for (int j = 0; j < n; ++j) {
        cout << "arr[" << j << "]=";
        cin >> arr[j];
    }
    for (int j = 0; j < n - 1; ++j) {
        imin = j;
        for (int k = j + 1; k < n; ++k) {
            if (arr[k] < arr[imin]) {
                imin = k;
            }
        }
        if (imin != j) {
            arr[j] += arr[imin];
            arr[imin] = arr[j] - arr[imin];
            arr[j] = arr[j] - arr[imin];
        }
    }
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    delete[] arr;
    return 0;
}
