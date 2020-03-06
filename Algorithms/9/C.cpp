#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int next(int color) {
	if (color == 1) {
		return 2;
	}
	return 1;
}

int dfs(int v, int p, vector <vector <int>> &g, vector <int> &used) {
	used[v] = next(used[p]);
	int f = 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			f = dfs(u, v, g, used);
		} else if (used[u] != next(used[v]) && u != p || u == v) {
			return -1;
		}
		if (f == -1) {
			return f;
		}
	}
	return f;
}

int main() {
	ifstream cin("bipartite.in");
	ofstream cout("bipartite.out");

	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	vector <int> ans;
	vector <int> used(n, 0);

	vector<int> cycle;
	for (int i = 0; i < n; i++) {
		if (!used[i] && dfs(i, i, g, used) == -1) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}
