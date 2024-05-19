#include <iostream>

template <class T>
class Node {
public:
    T data; 
    Node<T>* next; 

    Node(T data) : data(data), next(nullptr) {}
};

template <class T>
class singleLinkedList {
public:
    singleLinkedList() : head(nullptr), tail(nullptr) {}

    ~singleLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void push(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void show() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node<T>* head;
    Node<T>* tail;
};

int main() {
    singleLinkedList<int>* idx = new singleLinkedList<int>;
    idx->push(1);
    idx->push(2);
    idx->push(3);
    idx->push(4);
    idx->push(5);
    idx->show();

    delete idx; 
    return 0;
}
