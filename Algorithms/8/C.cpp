#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	for (auto v : g) {
		sort(v.begin(), v.end());
		auto last = v.end();
		if (last != unique(v.begin(), v.end())) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
