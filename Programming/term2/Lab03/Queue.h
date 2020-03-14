#pragma once
class Queue {
	int data[101];
	int head;
	int tail;
	int get_next();
	int next(int);
public:
	Queue();

	Queue& operator<<(int);
	Queue& operator>>(int&);

	void show();
};