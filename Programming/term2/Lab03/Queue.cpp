#include "Queue.h"
#include <iostream>

int Queue::next(int t) {
	return (t + 1) % 101;
}

int Queue::get_next() {
	if (next(tail) != head) {
		return next(tail);
	}
	else {
		return -1;
	}
}

Queue::Queue() {
	head = 0;
	tail = 0;
}
Queue& Queue::operator<<(int a) {
	if (get_next() == -1) {
		std::cerr << "Can't add element: queue is full!\n";
		exit(1);
	}
	data[tail] = a;
	tail = get_next();
	return *this;
}

Queue& Queue::operator>>(int &a) {
	if (head == tail) {
		std::cerr << "Can't delete element: queue is empty!\n";
		exit(1);
	}
	a = this->data[head];
	head = next(head);
	return *this;
}

void Queue::show() {
	int i = head;
	while (i != tail) {
		std::cout << this->data[i] << ' ';
		i = next(i);
	}
	std::cout << '\n';
}