#include <iostream>
#include <string>

using namespace std;

int main() {
    const int len = 81;
    string word, line;
    cout << "Введите текст: ";
    getline(cin, line);
    cout << "Введите слово для поиска: ";
    getline(cin, word);
    
    if (line.find(word) != -1) {
        cout << "Присутствует!" << endl;
    } else {
        cout << "Отсутствует!" << endl;
    }
    return 0;
}
