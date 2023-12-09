//
// Created by musta on 12/9/2023.
//

#ifndef PQUEUE_H
#define PQUEUE_H
#pragma once
#include <queue>

template <typename T>
class MyPriorityQueue {
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
        return data.top();
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

private:
    std::priority_queue<T> data;
};

#endif //PQUEUE_H
