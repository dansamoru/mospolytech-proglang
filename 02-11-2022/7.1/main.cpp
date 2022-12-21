#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int arr1[1000], arr2[1000], n;

auto delFirstMethod(int key) {
    unsigned count = 0;
    
    int i = 0;
    count++;
    
    count++;
    while (i <= n) {
        count++;
        count++;
        if (arr1[i] == key) {
            for (int j = 0; j < n; j++) {
                count++;
                arr1[j] = arr1[j + 1];
                count++;
            }
            n--;
            count++;
        } else {
            i++;
            count++;
        }
    }
    return count;
}

auto delSecondMethod(int key) {
    unsigned count = 0;
    
    int j = 0;
    count++;
    
    count++;
    for (int i = 0; i < n; ++i) {
        count++;
        arr2[j] = arr2[i];
        count++;
        if (arr2[i] != key) {
            count++;
            j++;
            count++;
        }
    }
    n = j;
    count++;
    return count;
}


int main() {
    unsigned short int command = 9, subcommand;
    while (command != 0) {
        switch (command) {
            case 1:
                cout << "--- Заполнение ---" << endl;
                cout << "1. Вручную" << endl;
                cout << "2. Случайными числами" << endl;
                cout << "3. Одним значением" << endl;
                cout << "Введите номер команды: ";
                cin >> subcommand;
                switch (subcommand) {
                    case 1:
                        cout << "Введите количество элементов: ";
                        cin >> n;
                        cout << "Введите элементы: ";
                        for (int i = 0; i < n; ++i) {
                            int tmp;
                            cin >> tmp;
                            arr1[i] = tmp;
                            arr2[i] = tmp;
                        }
                        break;
                    case 2:
                        cout << "Введите количество элементов: ";
                        cin >> n;
                        cout << "Задайте левую границу диапазона: ";
                        int left;
                        cin >> left;
                        cout << "Задайте правую границу диапазона: ";
                        int right;
                        cin >> right;
                        for (int i = 0; i < n; ++i) {
                            arr1[i] = left + rand() % (right - left + 1);
                            arr2[i] = arr1[i];
                        }
                        break;
                    case 3:
                        cout << "Введите количество элементов: ";
                        cin >> n;
                        cout << "Введите значение: ";
                        int value;
                        cin >> value;
                        for (int i = 0; i < n; ++i) {
                            arr1[i] = value;
                            arr2[i] = value;
                        }
                        cout << "Массив заполнен" << endl;
                        break;
                    default:
                        cout << "Неверная команда" << endl;
                        break;
                }
                break;
            case 2:
                for (int i = 0; i < n; ++i) {
                    cout << arr1[i] << " ";
                }
                cout << endl;
                break;
            case 3:
                int key;
                
                cout << "--- Ввод элемента ---" << endl;
                cout << "1. Вручную" << endl;
                cout << "2. Случайно" << endl;
                cout << "Введите номер команды: ";
                cin >> subcommand;
                
                switch (subcommand) {
                    int tmp;
                    case 1:
                        cout << "Введите элемент: ";
                        cin >> key;
                        break;
                    case 2:
                        tmp = arr1[rand() % n];
                        cout << "Случайный элемент: " << tmp << endl;
                        key = tmp;
                        break;
                    default:
                        cout << "Неверная команда" << endl;
                        break;
                }
                
                static auto start1 = chrono::high_resolution_clock::now();
                cout << "Количество критических операций первого метода: " << delFirstMethod(key) << endl;
                static auto end1 = chrono::high_resolution_clock::now();
                
                static auto start2 = chrono::high_resolution_clock::now();
                cout << "Количество критических операций второго метода: " << delSecondMethod(key) << endl;
                static auto end2 = chrono::high_resolution_clock::now();
                
                cout << "Время выполнения первого метода: " <<
                     chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << " мс" << endl;
                cout << "Время выполнения второго метода: " <<
                     chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << " мс" << endl;
                break;
            case 9:
                cout << "--- Команды ---" << endl;
                cout << "1. Заполнить массив" << endl;
                cout << "2. Вывести массив" << endl;
                cout << "3. Удалить значение" << endl;
                cout << "9. Вывести список команд" << endl;
                cout << "0. Выход" << endl;
                break;
            default:
                cout << "Неверная команда" << endl;
        }
        cout << "Введите номер команды: ";
        cin >> command;
    }
    cout << "Программа завершена" << endl;
    return 0;
}
