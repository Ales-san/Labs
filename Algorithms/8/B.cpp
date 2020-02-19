#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin >> n;
	vector <vector <bool>> g(n, vector <bool>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c;
			cin >> c;
			g[i][j] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && g[i][j] != g[j][i] ||
					 i == j && g[i][j] == 1) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
