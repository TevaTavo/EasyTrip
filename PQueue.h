#ifndef EASYTRIP_PQUEUE_H
#define EASYTRIP_PQUEUE_H

#include "Node.h"
#include <iostream>

template<class T>
class PriorityQueue {
protected:
    Node<T>* front;

public:
    // Constructor
    PriorityQueue() : front(nullptr) {
    }

    // Priority Queue Operations
    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T data, int priority) {
        Node<T>* temp = new Node<T>(data, priority);

        if (isEmpty() || front->getPriority() > priority) {
            temp->setNext(front);
            front = temp;
        } else {
            Node<T>* current = front;
            while (current->getNext() != nullptr && current->getNext()->getPriority() <= priority) {
                current = current->getNext();
            }
            temp->setNext(current->getNext());
            current->setNext(temp);
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty" << std::endl;
            return;
        }
        Node<T>* temp = front;
        front = front->getNext();
        delete temp;
    }

    T frontElement() const {
        if (isEmpty()) {
            std::cerr << "Priority Queue is empty" << std::endl;
            return T(); // Return default-constructed T if the queue is empty
        }
        return front->getData();
    }

    void printPriorityQueue() const {
        if (isEmpty()) {
            std::cout << "Priority Queue is empty" << std::endl;
            return;
        }
        Node<T>* temp = front;
        while (temp != nullptr) {
            std::cout << "(" << temp->getData() << ", " << temp->getPriority() << ") ";
            temp = temp->getNext();
        }
        std::cout << std::endl;
    }

    int size() const {
        int count = 0;
        Node<T>* temp = front;
        while (temp != nullptr) {
            count++;
            temp = temp->getNext();
        }
        return count;
    }



};

#endif //EASYTRIP_PQUEUE_H
