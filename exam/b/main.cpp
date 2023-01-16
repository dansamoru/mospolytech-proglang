#include <iostream>

using namespace std;

/*
 * Дан линейный однонаправленный список L,
 * информационная часть которого содержит однозначные и двузначные числа.
 *
 * 1. Разработать функцию, которая создает массив А из 10 указателей
 * на элемент списка и включает в список элемента массива с индексом i,
 * числа списка L, которые начинаются с
 * цифры равной i. Включение в конец списка. Однозначные
 * числа включаются в список массива с индексом 0.
 * 2. Разработать функцию, которая удаляет список L.
 * 3. Разработать функцию, которая создает список L, включая в
 * него списки массива А последовательно от списка с индексом
 * 0 до списка с индексом 9.
 *
 * Сделать проверку на правильность ввода данных.
 * Провести тестирование функций и вывести результаты.
 */


// Структура элемента списка
struct Node {
    int data;
    Node *next;
};

// Функция создания списка
void add(Node *&head, int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

// Функция вывода списка
void print(Node *head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Функция удаления списка
void deleteList(Node *&head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Функция создания массива указателей
void createArray(Node *head, Node **array) {
    while (head) {
        int data = head->data;
        int index = data / 10;
        add(array[index], data);
        head = head->next;
    }
}

// Функция создания списка из массива указателей
void createList(Node *&head, Node **array) {
    for (int i = 10; i >= 0; i--) {
        Node *temp = array[i];
        while (temp) {
            add(head, temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    // Создание списка
    Node *head = nullptr;
    Node *array[10] = {nullptr};
    
    // Ввод данных
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите элементы: ";
    
    // Проверка на правильность ввода
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if (data < 0 || data > 99) {
            cout << "Неверный формат введённых данных" << endl;
            return 0;
        }
        add(head, data);
    }
    
    // Создание массива указателей
    createArray(head, array);
    deleteList(head);
    createList(head, array);
    
    print(head);
    
    return 0;
}
