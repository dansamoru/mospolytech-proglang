#include <iostream>
#include <bitset>

using namespace std;

int main() {
    unsigned int x = 25;
    const int n = sizeof(int) * 8;
    unsigned maska = (1 << (n - 1));
    cout << "Начальный вид маски: " << bitset<n>(maska) << endl;
    cout << "Результат: ";
    for (int i = 0; i <= n; ++i) {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
    cout << endl;
    return 0;
}
