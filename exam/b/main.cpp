#include <iostream>

using namespace std;

/*
 * Дан линейный однонаправленный список L,
 * информационная часть которого содержит однозначные и двузначные числа.
 *
 * 1. Разработать функции вставки нового узла перед первым узлом и удаления узла по ключу.
 * 2. Реализуйте возможность
 *      а) создания нового списка вручную
 *      б) использования уже готового списка.
 * 3. Разработать функцию вывода списка в консоль.
 * 4. Реализуйте текстовое пользовательское меню.
 * 5. В основной программе выполните тестирование каждой функции
 *
 * 6. Разработать функцию, которая создает массив А из 10 указателей
 * на элемент списка и включает в список элемента массива с индексом i,
 * числа списка L, которые начинаются с
 * цифры равной i. Включение в конец списка. Однозначные
 * числа включаются в список массива с индексом 0.
 * 7. Разработать функцию, которая удаляет список L.
 * 8. Разработать функцию, которая создает список L, включая в
 * него списки массива А последовательно от списка с индексом 0
 * до списка с индексом 9.
 *
 */

// Структура узла списка
struct Node {
    int data;
    Node *next;
};

// Функция вывода списка
void printList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функция вставки нового узла перед первым узлом
void insertNode(Node *&head, int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Функция удаления узла по ключу
void deleteNode(Node *&head, int key) {
    Node *current = head;
    Node *previous = nullptr;
    while (current != nullptr) {
        if (current->data == key) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Функция создания списка вручную
void createList(Node *&head) {
    int data;
    cout << "Введите элементы списка: ";
    cin >> data;
    while (data != 0) {
        insertNode(head, data);
        cin >> data;
    }
}

// Функция создания списка
void createArray(Node *array[]) {
    for (int i = 0; i < 10; i++) {
        array[i] = nullptr;
    }
}

// Функция включения в список элемента массива с индексом i
void insertArray(Node *array[], Node *&head) {
    Node *current = head;
    while (current != nullptr) {
        int data = current->data;
        int index = data / 10;
        insertNode(array[index], data);
        current = current->next;
    }
}

// Функция удаления списка
void deleteList(Node *&head) {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Функция создания списка из массива
void createListFromArray(Node *array[], Node *&head) {
    for (int i = 0; i < 10; i++) {
        Node *current = array[i];
        while (current != nullptr) {
            insertNode(head, current->data);
            current = current->next;
        }
    }
}

int main() {
    Node *head = nullptr;
    Node *array[10];
    int choice;
    cout << "1. Создать список вручную" << endl;
    cout << "2. Использовать уже готовый список" << endl;
    cout << "3. Вывести список" << endl;
    cout << "4. Вставить новый узел перед первым узлом" << endl;
    cout << "5. Удалить узел по ключу" << endl;
    cout << "6. Создать массив А из 10 указателей на элемент списка" << endl;
    cout << "7. Удалить список L" << endl;
    cout << "8. Создать список L, включая в него списки массива А" << endl;
    cout << "0. Выход" << endl;
    do {
        cout << "Выберите пункт меню: ";
        cin >> choice;
        switch (choice) {
            case 1:
                createList(head);
                break;
            case 2:
                insertNode(head, 10);
                insertNode(head, 20);
                insertNode(head, 30);
                insertNode(head, 40);
                insertNode(head, 50);
                insertNode(head, 60);
                insertNode(head, 70);
                insertNode(head, 80);
                insertNode(head, 90);
                insertNode(head, 1);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                int data;
                cout << "Введите элемент: ";
                cin >> data;
                insertNode(head, data);
                break;
            case 5:
                int key;
                cout << "Введите ключ: ";
                cin >> key;
                deleteNode(head, key);
                break;
            case 6:
                createArray(array);
                insertArray(array, head);
                break;
            case 7:
                deleteList(head);
                break;
            case 8:
                createListFromArray(array, head);
                break;
            case 0:
                break;
            default:
                cout << "Неверный пункт меню" << endl;
        }
    } while (choice != 0);
    return 0;
}