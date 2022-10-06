#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int len = 81;
    char word[len], line[len];
    cout << "Введите текст: ";
    cin >> line;
    cout << "Введите слово для поиска: ";
    cin >> word;
    
    if (strstr(line, word)) {
        cout << "Присутствует!" << endl;
    } else {
        cout << "Отсутствует!" << endl;
    }
    return 0;
}
