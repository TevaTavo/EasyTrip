//
// Created by musta on 12/10/2023.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>

template<class T>
class LinkedList {
private:
    Node<T>* Head;

public:
    // Constructor
    LinkedList() : Head(nullptr) {
    }

    // Basic Operations
    bool isEmpty() const {
        return Head == nullptr;
    }

    void insertAtBeg(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(Head);
        Head = newNode;
    }

    void insertAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (isEmpty()) {
            Head = newNode;
        } else {
            Node<T>* temp = Head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }

    void insertAtIndex(int index, T data) {
        if (index < 0) {
            std::cerr << "Invalid index" << std::endl;
            return;
        }
        if (index == 0) {
            insertAtBeg(data);
            return;
        }
        Node<T>* temp = Head;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->getNext();
        }
        if (temp == nullptr || temp->getNext() == nullptr) {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
    }

    void printList() const {
        Node<T>* temp = Head;
        if (isEmpty()) {
            std::cout << "List is Empty" << std::endl;
        } else {
            while (temp != nullptr) {
                std::cout << temp->getData() << " -> ";
                temp = temp->getNext();
            }
            std::cout << "end" << std::endl;
        }
    }

    // Advanced Operations
    static LinkedList<T> merge(const LinkedList<T>& list1, const LinkedList<T>& list2) {
        LinkedList<T> mergedList;
        Node<T>* temp1 = list1.Head;
        Node<T>* temp2 = list2.Head;
        while (temp1 != nullptr) {
            mergedList.insertAtEnd(temp1->getData());
            temp1 = temp1->getNext();
        }
        while (temp2 != nullptr) {
            mergedList.insertAtEnd(temp2->getData());
            temp2 = temp2->getNext();
        }
        return mergedList;
    }

    // Utility Functions
    T getItem() const {
        Node<T>* temp = Head;
        while (temp != nullptr && temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        return temp != nullptr ? temp->getData() : T();
    }

    void remove(T data) {
        Node<T>* temp = Head;
        Node<T>* prev = nullptr;
        if (isEmpty()) {
            std::cout << "List is empty, cannot remove" << std::endl;
        } else {
            while (temp->getNext() != nullptr) {
                if (temp->getData() == data) {
                    if (prev == nullptr) {
                        // If the node to be removed is the head
                        Head = temp->getNext();
                    } else {
                        // If the node to be removed is not the head
                        prev->setNext(temp->getNext());
                    }

                    // Delete the node and break out of the loop
                    delete temp;
                    break;
                } else {
                    prev = temp;
                    temp = temp->getNext();
                }
            }
        }
    }
};


#endif //LINKEDLIST_H
