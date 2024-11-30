#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue {
private:
    
    struct Node {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head; 
    Node* tail; 
    int count;  

public:
    
    Queue() : head(nullptr), tail(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

  
    bool isEmpty() const {
        return count == 0;
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }

    
    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot dequeue.");
        }

        Node* temp = head;
        T value = head->data;
        head = head->next;

        delete temp;
        --count;

        if (isEmpty()) {
            tail = nullptr; 
        }

        return value;
    }

  
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot peek.");
        }
        return head->data;
    }

   
    int size() const {
        return count;
    }
};

#endif

