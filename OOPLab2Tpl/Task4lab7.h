#include <iostream>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* first; // Перший елемент списку
    Node* last; // Останній елемент списку

public:
    List() : first(nullptr), last(nullptr) {}

    void add(const T& value) {
        Node* newNode = new Node(value);
        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    // Клас ітератора
    class ListIterator {
    private:
        Node* current;

    public:
        ListIterator(Node* node) : current(node) {}

        // Перевірка на закінчення списку
        bool hasNext() {
            return current != nullptr;
        }

        // Отримання поточного значення і перехід до наступного елемента
        T next() {
            T value = current->data;
            current = current->next;
            return value;
        }
    };

    ListIterator begin() {
        return ListIterator(first);
    }

    ListIterator end() {
        return ListIterator(nullptr);
    }
};

