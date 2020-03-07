#include "Set.h"
#include <algorithm>
#include <iostream>

Set::Set() : _size(10), _data(std::vector<int>(_size)) {};

Set::Set(int size) : _size(size), _data(std::vector<int>(_size)) {};

Set::Set(Set const &a) : _size(a._size), _data(a._data), _cur(a._cur) {};

int Set::get_size() {
	return _cur;
}

bool Set::contains(int x) {
	if (std::find(_data.begin(), _data.begin() + _cur, x) != _data.begin() + _cur) {
		return true;
	}
	return false;
}
void Set::add(int x) {
	if (_cur < _size) {
		if (!contains(x)) {
			_data[_cur] = x;
			_cur++;
		}
	} else {
		std::cerr << "Can't add element, max size was reached!\n";
		exit(1);
	}
}
void Set::exclude(int x) {
	auto it = std::find(_data.begin(), _data.begin() + _cur, x);
	if (it != _data.begin() + _cur) {
		_data.erase(it);
		_cur--;
	}
}

Set Set::intersection(Set b) {
	Set res = Set(std::min(_cur, b._cur));
	if (_cur < b._cur) {
		for (int i = 0; i < _cur; i++) {
			if (b.contains(_data[i])) {
				res.add(_data[i]);
			}
		}
	} else {
		for (int i = 0; i < b._cur; i++) {
			if (contains(b._data[i])) {
				res.add(b._data[i]);
			}
		}
	}
	return res;
}
Set Set::integration(Set b) {
	std::vector <int> tmp;
	if (_cur < b._cur) {
		for (int i = 0; i < b._cur; i++) {
			tmp.push_back(b._data[i]);
		}
		for (int i = 0; i < _cur; i++) {
			if (!b.contains(_data[i])) {
				tmp.push_back(_data[i]);
			}
		}
	} else {
		for (int i = 0; i < _cur; i++) {
			tmp.push_back(_data[i]);
		}
		for (int i = 0; i < b._cur; i++) {
			if (!contains(b._data[i])) {
				tmp.push_back(b._data[i]);
			}
		}
	}
	Set res = Set(tmp.size());
	res._data = tmp;
	res._cur = tmp.size();
	return res;
}

void Set::print() const {
	std::cout << "{";
	for (int i = 0; i < _cur; i++) {
		std::cout << ' ' << _data[i];
	}
	std::cout << " }\n";
}
