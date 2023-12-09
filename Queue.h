//
// Created by musta on 12/9/2023.
//

#ifndef QUEUE_H
#define QUEUE_H
#pragma once
#include <queue>

template <typename T>
class MyQueue {
public:
    void enqueue(const T& value) {
        data.push(value);
    }

    void dequeue() {
        if (!data.empty()) {
            data.pop();
        }
    }

    T front() const {
        return data.front();
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

private:
    std::queue<T> data;
};


#endif //QUEUE_H
