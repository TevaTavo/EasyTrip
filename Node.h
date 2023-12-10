#ifndef EASYTRIP_NODE_H
#define EASYTRIP_NODE_H

template<class T>
class Node {
private:
    T data;
    int priority;
    Node<T> *next;

public:
    // Constructor
    Node(T data, int priority);
    Node(T data);

    // Setter methods
    void setData(T data);
    void setPriority(int priority);
    void setNext(Node<T> *next);

    // Getter methods
    T getData() const;
    Node<T> *getNext() const;
    int getPriority() const;
};

// Constructor
template<class T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

template<class T>
Node<T>::Node(T data, int priority) : data(data), priority(priority), next(nullptr) {}

// Setter for data
template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template<class T>
void Node<T>::setPriority(int priority) {
    this->priority = priority;
}

// Setter for next
template<class T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next;
}

// Getter for data
template<class T>
T Node<T>::getData() const {
    return data;
}

// Getter for next
template<class T>
Node<T> *Node<T>::getNext() const {
    return next;
}

template<class T>
int Node<T>::getPriority() const {
    return priority;
}

#endif //EASYTRIP_NODE_H
