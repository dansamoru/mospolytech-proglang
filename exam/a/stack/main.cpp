#include <iostream>


//  Реализовать стек с помощью однонаправленного списка.
//  Протестировать и вывести результат.
//  Добавить комментарии к коду.

struct Node {
    int data;
    Node *next;
};

class Stack {
    Node *head;
public:
    Stack() {
        head = nullptr;
    }
    
    // Добавление элемента в стек
    void push(int data) {
        Node *node = new Node;
        node->data = data;
        node->next = head;
        head = node;
    }
    
    // Удаление элемента из стека
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
    
    // Вывод стека
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
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.print();
    std::cout << stack.pop() << std::endl;
    stack.print();
    return 0;
}