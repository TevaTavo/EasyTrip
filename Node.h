//
// Created by musta on 12/9/2023.
//

#ifndef NODE_H
#define NODE_H
#pragma once

template <typename T>
class Node {
public:
    Node(const T& value) : data(value), next(nullptr) {}

    T getData() const {
        return data;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* newNode) {
        next = newNode;
    }

private:
    T data;
    Node* next;
};


#endif //NODE_H
