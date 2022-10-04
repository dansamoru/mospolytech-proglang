#include <iostream>
#include <ctime>

using namespace std;

int main() {
    const int n = 7;
    int a[n], maxA = -150;
    
    srand(time(NULL));
    cout << "Целочисленный массив из " << n << " случайных чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 200 - 100;
        maxA = max(maxA, a[i]);
        cout << "a[" << i << "]=" << a[i] << ", ";
    }
    cout << endl << endl << "Максимальное значение в массиве = " << maxA << endl;
    return 0;
}
