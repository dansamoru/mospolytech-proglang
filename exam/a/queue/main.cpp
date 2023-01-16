#include <iostream>

//  Реализовать очередь с помощью однонаправленного списка.
//  Протестировать и вывести результат.
//  Добавить комментарии к коду.

struct Node {
    int data;
    Node *next;
};

class Queue {
    Node *head;
    Node *tail;
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }
    
    //  Добавление элемента в очередь
    void push(int data) {
        Node *node = new Node;
        node->data = data;
        node->next = nullptr;
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    
    //  Удаление элемента из очереди
    int pop() {
        if (head == nullptr) {
            return -1;
        }
        int data = head->data;
        Node *node = head;
        head = head->next;
        delete node;
        return data;
    }
    
    //  Вывод очереди
    void print() {
        Node *node = head;
        while (node != nullptr) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    std::cout << "Очередь: ";
    queue.print();
    std::cout << "Удаляем элемент: " << queue.pop() << std::endl;
    std::cout << "Очередь: ";
    queue.print();
    std::cout << "Удаляем элемент: " << queue.pop() << std::endl;
    std::cout << "Очередь: ";
    queue.print();
    std::cout << "Удаляем элемент: " << queue.pop() << std::endl;
    std::cout << "Очередь: ";
    queue.print();
    return 0;
}
