#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, m;
	cin >> n >> m;
	vector <vector <bool>> g(n, vector <bool>(n, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1][b - 1] = 1;
	}
	for (auto v : g) {
		for (auto c : v) {
			cout << c << ' ';
		}
		cout << '\n';
	}
	return 0;
}
