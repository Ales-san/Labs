#ifndef LABC05TERM2_QUEUEEXCEPTION_H
#define LABC05TERM2_QUEUEEXCEPTION_H

#include <exception>

class QueueException : public std::exception {};

class QueueOverflowException : public QueueException {
    const char *what() const throw() override {
        return "Queue overflows.\n";
    }
};

class EmptyQueueException : public QueueException {
    const char *what() const throw() override {
        return "Queue is empty.\n";
    }
};

#endif //LABC05TERM2_QUEUEEXCEPTION_H
