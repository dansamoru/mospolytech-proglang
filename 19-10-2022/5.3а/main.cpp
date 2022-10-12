#include <iostream>

using namespace std;

int sum(const int *mas, const int n);

const int n = 10;

int main() {
    int marks[n] = {2, 7, 5, 0, 4};
    cout << "Сумма элементов массива: " << sum(marks, n) << endl;
    return 0;
}

// Суммирование массива
int sum(const int *mas, const int n) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += mas[i];
    }
    return s;
}

