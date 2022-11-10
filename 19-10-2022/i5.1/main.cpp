#include <iostream>

using namespace std;

bool is_perfect(int k);

int main() {
    int n;
    cout << "Введите n: ";
    cin >> n;
    int *a = new int(n);
    cout << "Введите a:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << "\n Последовательности совершенных чисел:\n";
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (is_perfect(a[i])) {
            if (!flag) {
                cout << endl;
                flag = true;
            }
            cout << a[i] << " ";
        } else {
            flag = false;
        }
    }
    delete a;
    return 0;
}

bool is_perfect(int k) {
    int s = 0;
    for (int i = 1; i < k / 2 + 1; ++i) {
        if (k % i == 0) {
            s += i;
        }
    }
    return s == k;
}
