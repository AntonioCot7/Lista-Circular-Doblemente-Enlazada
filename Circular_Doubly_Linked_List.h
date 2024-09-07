#ifndef LISTA_CIRCULAR_DOBLEMENTE_ENLAZADA_CIRCULAR_DOUBLY_LINKED_LIST_H
#define LISTA_CIRCULAR_DOBLEMENTE_ENLAZADA_CIRCULAR_DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <typename T>
class CircularDoublyLinkedList {
private:
    Node<T>* head;
    int list_size;

public:
    CircularDoublyLinkedList() : list_size(0) {
        head = new Node<T>(T());
        head->next = head;
        head->prev = head;
    }

    ~CircularDoublyLinkedList() {
        clear();
        delete head;
    }

    T front() {
        if (empty()) throw std::out_of_range("The list is empty");
        return head->next->data;
    }

    T back() {
        if (empty()) throw std::out_of_range("The list is empty");
        return head->prev->data;
    }

    void push_front(T val) {
        Node<T>* new_node = new Node<T>(val);
        new_node->next = head->next;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;
        ++list_size;
    }

    void push_back(T val) {
        Node<T>* new_node = new Node<T>(val);
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        ++list_size;
    }

    void pop_front() {
        if (empty()) throw std::out_of_range("The list is empty");
        Node<T>* temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        --list_size;
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("The list is empty");
        Node<T>* temp = head->prev;
        head->prev = temp->prev;
        temp->prev->next = head;
        delete temp;
        --list_size;
    }

    void insert(int pos, T val) {
        if (pos < 0 || pos > list_size) throw std::out_of_range("Invalid Position");

        Node<T>* new_node = new Node<T>(val);
        Node<T>* temp = head->next;

        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }

        new_node->next = temp;
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
        ++list_size;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= list_size) throw std::out_of_range("Invalid Position");

        Node<T>* temp = head->next;

        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        --list_size;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= list_size) throw std::out_of_range("Invalid Position");

        Node<T>* temp = head->next;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() {
        return list_size == 0;
    }

    int size() {
        return list_size;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void reverse() {
        Node<T>* current = head->next;
        Node<T>* temp = nullptr;

        do {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        } while (current != head);

        temp = head->next;
        head->next = head->prev;
        head->prev = temp;
    }
};

#endif //LISTA_CIRCULAR_DOBLEMENTE_ENLAZADA_CIRCULAR_DOUBLY_LINKED_LIST_H
