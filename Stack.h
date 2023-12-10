// Stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>

template<class T>
class Node {
private:
    T data;
    Node<T> *next;

public:
    Node(T newData) : data(newData), next(nullptr) {}
    T getData() const { return data; }
    Node<T>* getNext() const { return next; }
    void setNext(Node<T> *newNext) { next = newNext; }
};

template<class T>
class Stack {
private:
    Node<T> *top;

public:
    Stack() : top(nullptr) {}
    bool isEmpty() const {
        return top == nullptr;
    }
    void push(T data) {
        Node<T> *newNode = new Node<T>(data);
        newNode->setNext(top);
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        Node<T> *temp = top;
        top = top->getNext();
        delete temp;
    }
    T topElement() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            return T(); // Return default-constructed T if the stack is empty
        }
        return top->getData();
    }
    void printStack() const {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        Node<T> *temp = top;
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

#endif // STACK_H
