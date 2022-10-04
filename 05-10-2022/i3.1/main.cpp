#include <iostream>
#include <ctime>

using namespace std;

int main() {
    const int n = 7;
    int a[n];
    
    srand(time(NULL));
    cout << "Целочисленный массив из " << n << "случайных чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
        cout << "a[" << i << "]=" << a[i] << ", ";
    }
    cout << endl;
    return 0;
}
