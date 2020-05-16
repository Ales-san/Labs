#include <iterator>

template <typename Iterator, typename Type>
bool all_of(const Iterator& begin, const Iterator& end, bool(&pred)(Type)) {
	for (auto it = begin; it != end; it++) {
		if (!pred(*it)) {
			return false;
		}
	}
	return true;
}

template <typename Iterator, typename Type>
bool is_partitioned(const Iterator& begin, const Iterator& end, bool(&pred)(Type)) {
	int cnt = 0;
	for (auto it = begin; std::next(it) != end; it++) {
		if (pred(*it) != pred(*(std::next(it)))) {
			cnt++;
		}
	}
	return cnt == 1;
}

template <typename Iterator, typename Type>
Iterator find_backward(const Iterator& begin, const Iterator& end, Type element) {
	for (auto it = std::prev(end); it != begin; it--) {
		if (element == (*it)) {
			return it;
		}
	}
	if ((*begin) == element) {
		return begin;
	}
	return end;
}