#include <iostream>
#include <fstream>

using namespace std;

string search() {
/* Дан файл f, который содержит номера телефонов сотрудников учреждения:
 * указывается фамилия, его инициалы и номер телефона.
 * Найти телефон сотрудника по его фамилии и инициалам. */
    
    string fio1, fio2, fio3, phone;
    string fio_search1, fio_search2, fio_search3;
    cout << "Введите фамилию и инициалы сотрудника: ";
    cin >> fio_search1 >> fio_search2 >> fio_search3;
    ifstream fin("../f.txt");
    while (fin >> fio1 >> fio2 >> fio3 >> phone) {
        if (fio1 == fio_search1 && fio2 == fio_search2 && fio3 == fio_search3) {
            return phone;
        }
    }
    return "Сотрудник не найден";
}

int main() {
    cout << search() << endl;
    return 0;
}
