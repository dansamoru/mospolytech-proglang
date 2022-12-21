#include <iostream>

using namespace std;

/* Структура-пара
 *
 * метод инициализации init()
 * ввод с клавиатуры read()
 * вывод на экран display()
 * ipart() - возвращает целую часть с проверкой на ноль
 *
 * first - целое положительное число
 * second - целое положительное число
 */

struct Pair {
    int first;
    int second;
    
    void init(int f, int s) {
        first = f;
        second = s;
    }
    
    void read() {
        cin >> first >> second;
    }
    
    void display() {
        cout << first << " " << second << endl;
    }
    
    int ipart() {
        if (second == 0) {
            cout << "Error: division by zero" << endl;
            return 0;
        }
        return first / second;
    }
};

/* make_mun() - возвращает структуру-пару
 *
 * a - первое число
 * b - второе число
 */

Pair make_pair(int a, int b) {
    Pair p;
    p.init(a, b);
    return p;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    Pair p = make_pair(a, b);
    p.display();
    return 0;
}
