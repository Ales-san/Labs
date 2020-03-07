#pragma once

#include <vector>

class Set {
public:
	Set();
	Set(int size);
	Set(Set const &a);

	int get_size();
	bool contains(int x);
	void add(int x);
	void exclude(int x);
	Set intersection(Set b);
	Set integration(Set b);

	void print() const;
private:
	int _size;
	std::vector<int> _data;
	int _cur = 0;
};
