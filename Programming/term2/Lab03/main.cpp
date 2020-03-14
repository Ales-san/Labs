#include <iostream>

#include "Matrix.h"
#include "Queue.h"

using namespace std;

int main() {

	int a;
	cin >> a;
	if (a == 1) {
		cout << "Matrix a:";
		Matrix a;
		a.show();
		Matrix b;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				b.data[i][j] = (i) * 3 + j + 1;
				a.data[i][j] = 1;
			}
		}
		cout << "Matrix a:";
		a.show();
		cout << "Matrix b:";
		b.show();
		Matrix c;
		c = a + b;
		cout << "Matrix c = a + b:";
		c.show();

		c = a - b;
		cout << "Matrix c = a - b:";
		c.show();

		c = a * b;
		cout << "Matrix c = a * b:";
		c.show();

		c = b * 2;
		cout << "Matrix c = b * 2:";
		c.show();

		cout << "a == b: " << (a == b);
		cout << "\na != b: " << (a != b);
		cout << "\na < b: " << (a < b);
		cout << "\na > b: " << (a > b);
	} else {
		Queue a;
		cout << "Queue a: ";
		a.show();
		for (int i = 0; i < 10; i++) {
			a << i;
		}
		cout << "Queue a: ";
		a.show();
		cout << "Delete elements from a: ";
		for (int i = 0; i < 10; i++) {
			int b;
			a >> b;
			cout << b << ' ';;
		}
	}
	system("pause");
	return 0;
}