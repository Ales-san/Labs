#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int top_sort(int v, vector <vector <int>> &g, vector <int> &used, vector <int> &ans) {
	used[v] = 1;
	int f = 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			f = top_sort(u, g, used, ans);
		} else if (used[u] == 1) {
			return -1;
		}
		if (f == -1) {
			return f;
		}
	}
	used[v] = 2;
	ans.push_back(v);
	return f;
}

int main() {
	ifstream cin("topsort.in");
	ofstream cout("topsort.out");

	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
	}
	vector <int> ans;
	vector <int> used(n, 0);

	for (int i = 0; i < n; i++) {
		if (!used[i] && top_sort(i, g, used, ans) == -1) {
			cout << -1;
			return 0;
		}
	}
	
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] + 1 << ' ';
	}

	return 0;
}
