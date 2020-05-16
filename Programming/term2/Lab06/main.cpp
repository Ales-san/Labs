#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "generalized_algorithms.h"

using namespace std;

class Student {
public:
	Student() {};
	Student(int number, string name, int course, char gender) : number_(number), name_(name), course_(course), gender_(gender) {};
private:
	int number_ = 0;
	string name_ = "John Doe";
	int course_ = 1;
	char gender_ = 'M';
public:
	bool operator==(const Student& s) const {
		return ((number_ == s.number_) && (name_ == s.name_) &&
			(course_ == s.course_) && (gender_ == s.gender_));
	}
	bool operator<(const Student& s) const {
		return (number_ < s.number_);
	}
};

bool is_unknown(const Student& el) {
		return el == Student();
}

bool is_less_6(int x) {
	return x < 6;
}

int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 1, 20, 30, 40, 50 };
	vector <char> c = { 'a', 'b', 'a', 'd', 'e' };
	vector <char> d = { 'a', 'a', 'a', 'b', 'f' };
	set <Student> s;
	s.insert(Student());
	

	cout << "All of elements of a are less than 6: " << all_of(a + 0, a + 5, is_less_6);
	cout << "\nAll of elements of b are less than 6: " << all_of(b + 0, b + 5, is_less_6);
	cout << "\nAll of elements of set are unknown: " << all_of(s.begin(), s.end(), is_unknown);
	s.insert({ 1, "Patrick Jane", 2, 'M' });
	s.insert({ 2, "Elisabet Terner", 3, 'F' });
	s.insert({ 3, "Jake Black", 1, 'M' });
	cout << "\nAll of elements of set are unknown: " << all_of(s.begin(), s.end(), is_unknown);
	s.clear();

	cout << "\na is partitioned: " << is_partitioned(a + 0, a + 5, is_less_6);
	cout << "\nb is partitioned: " << is_partitioned(b + 0, b + 5, is_less_6);
	s.insert({ 1, "Patrick Jane", 2, 'M' });
	s.insert({ 2, "Elisabet Terner", 3, 'F' });
	s.insert({ 3, "Jake Black", 1, 'M' });
	cout << "\nSet is partitioned: " << is_partitioned(s.begin(), s.end(), is_unknown);
	s.insert(Student());
	cout << "\nSet is partitioned: " << is_partitioned(s.begin(), s.end(), is_unknown);

	cout << "\nElement was found: " << (find_backward(c.begin(), c.end(), 'f') != c.end());
	cout << "\nElement was found: " << (find_backward(d.begin(), d.end(), 'f') != d.end());
	cout << "\nElement was found: " << (find_backward(s.begin(), s.end(), Student()) != s.end());
	s.erase(Student());
	cout << "\nElement was found: " << (find_backward(s.begin(), s.end(), Student()) != s.end()) << '\n';
	system("pause");
}
