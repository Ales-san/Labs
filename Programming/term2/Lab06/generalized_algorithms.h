#pragma once

template <typename Iterator, typename Type>
bool all_of(const Iterator& begin, const Iterator& end, bool(&pred)(Type));

template <typename Iterator, typename Type>
bool is_partitioned(const Iterator& begin, const Iterator& end, bool(&pred)(Type));

template <typename Iterator, typename Type>
Iterator find_backward(const Iterator& begin, const Iterator& end, Type element);
#include "generalized_algorithms.cpp"