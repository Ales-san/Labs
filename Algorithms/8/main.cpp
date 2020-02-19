#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

void dfs(int cur, vector <vector <int>> &g, vector <int> &used, int &cnt) {
	used[cur] = cnt;
	for (auto to : g[cur]) {
		if (!used[to]) {
			dfs(to, g, used, cnt);
		}
	}
}

int main() {
	ifstream cin("components.in");
	ofstream cout("components.out");
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	vector <int> used(n, 0);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, g, used, cnt);
			cnt++;
		}
	}

	cout << cnt - 1 << '\n';
	for (int i = 0; i < n; i++) {
		cout << used[i] << ' ';
	}

	
	return 0;
}