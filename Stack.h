//
// Created by musta on 12/9/2023.
//

#ifndef STACK_H
#define STACK_H
#pragma once
#include <stack>

template <typename T>
class MyStack {
public:
    void push(const T& value) {
        data.push(value);
    }

    void pop() {
        if (!data.empty()) {
            data.pop();
        }
    }

    T top() const {
        return data.top();
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

private:
    std::stack<T> data;
};


#endif //STACK_H
