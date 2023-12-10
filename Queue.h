//
// Created by musta on 12/9/2023.
//


#ifndef EASYTRIP_QUEUE_H
#define EASYTRIP_QUEUE_H

#include "Node.h"
#include <iostream>

template<class T>
class Queue {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Queue Operations
    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node<T> *temp = front;
        front = front->getNext();
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    T frontElement() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            return T(); // Return default-constructed T if the queue is empty
        }
        return front->getData();
    }

    void printQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node<T> *temp = front;
        while (temp != nullptr) {
            std::cout << temp->getData();
            if (temp->getNext() != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->getNext();
        }
        std::cout << "end" << std::endl;
    }
};


#endif //EASYTRIP_QUEUE_H

