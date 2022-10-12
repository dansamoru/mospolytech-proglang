#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n);

int main() {
    int counter = 0, i = 2;
    while (counter < 100) {
        if (is_prime(i)) {
            cout << i << " ";
            counter++;
        }
        i++;
    }
    return 0;
}

// Определение, является ли число простым
bool is_prime(int n) {
    int s = 0, i = 2;
    while (i <= sqrt(n) && s == 0) {
        if (n % i == 0) {
            s++;
        }
        i++;
    }
    return !s;
}
