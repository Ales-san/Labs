#include <iostream>

#include "Set.h"

using namespace std;

int main() {
	Set a = Set();
	for (int i = 0; i < 10; i++) {
		a.add(i);
	}
	a.print();

	a.exclude(3);
	a.exclude(4);
	cout << "size is " << a.get_size() << "\n";
	a.print();

	Set b = Set(5);
	for (int i = 1; i < 6; i++) {
		b.add(i);
	}
	b.print();

	Set c = Set(a.intersection(b));
	c.print();

	Set d = Set(a.integration(b));
	d.print();

	system("pause");
}
