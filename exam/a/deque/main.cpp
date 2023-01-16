#include <iostream>

//  Реализовать дек с помощью двунаправленного списка.
//  Протестировать и вывести результат.
//  Добавить комментарии к коду.

struct Node {
    int value;
    Node *next;
    Node *prev;
};

class Deck {
private:
    Node *head;
    Node *tail;
    int size;
public:
    Deck() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    //  Добавление элемента в конец дека
    void push_back(int value) {
        Node *node = new Node;
        node->value = value;
        node->next = nullptr;
        node->prev = tail;
        if (tail != nullptr) {
            tail->next = node;
        }
        tail = node;
        if (head == nullptr) {
            head = node;
        }
        size++;
    }
    
    // Добавление элемента в начало дека
    void push_front(int value) {
        Node *node = new Node;
        node->value = value;
        node->next = head;
        node->prev = nullptr;
        if (head != nullptr) {
            head->prev = node;
        }
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
        size++;
    }
    
    // Удаление элемента из конца дека
    int pop_back() {
        if (tail == nullptr) {
            return -1;
        }
        int value = tail->value;
        Node *node = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        delete node;
        size--;
        return value;
    }
    
    // Удаление элемента из начала дека
    int pop_front() {
        if (head == nullptr) {
            return -1;
        }
        int value = head->value;
        Node *node = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete node;
        size--;
        return value;
    }
    
    // Вывод дека
    void print() {
        Node *node = head;
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Deck deck;
    deck.push_back(1);
    deck.push_back(2);
    deck.push_back(3);
    deck.push_front(4);
    deck.push_front(5);
    deck.push_front(6);
    deck.print();
    std::cout << "Последний элемент: " << deck.pop_back() << std::endl;
    std::cout << "Первый элемент: " << deck.pop_front() << std::endl;
    std::cout << "Дек после удаления: ";
    deck.print();
    return 0;
}