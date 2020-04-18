#include <cstdio>
#include <vector>
#include "QueueException.h"

#ifndef LABC05TERM2_QUEUE__H
#define LABC05TERM2_QUEUE__H

template <typename T, size_t MaxSize>
class Queue {
private:
    std::vector <T> elements;
    size_t head = 0;
    size_t tail = 0;
    int next(int cur) {
        return (cur + 1) % (MaxSize + 1);
    }

public:
    Queue() : elements(std::vector <T> (MaxSize + 1)) {}
    void push(T element) {
        if(next(tail) != head) {
            elements[tail] = element;
            tail = next(tail);
        } else {
            throw QueueOverflowException();
        }
    }

    T pop() {
        if(head != tail) {
            T res = elements[head];
            head = next(head);
            return res;
        } else {
            throw EmptyQueueException();
        }
    }

    T front() {
        if(head != tail) {
            return elements[head];
        } else {
            throw EmptyQueueException();
        }
    }

    size_t size() {
        return (head <= tail ? tail - head : MaxSize + 1 - head + tail);
    }

};

#endif //LABC05TERM2_QUEUE__H
