#include <iostream>
#include <cmath>

using namespace std;

int calc(string s);

int main() {
    string s;
    cout << "Введите число в шестнадцатеричном формате: ";
    cin >> s;
    cout << "Десятичная запись: " << calc(s);
    return 0;
}

// Перевод шестнадцатеричного символа в десятеричный
int calc(string s) {
    int n = 0, mlt = 0;
    while (s.length() > 0) {
        if (isdigit(s[s.length() - 1])) {
            n += pow(16, mlt++) * (s[s.length() - 1] - '0');
        } else {
            n += pow(16, mlt++) * (10 + s[s.length() - 1] - 'A');
        }
        s.pop_back();
    }
    return n;
}
