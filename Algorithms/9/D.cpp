#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(int v, int color, vector <vector <int>> &g, vector <int> &used, vector<int> &order) {
	used[v] = color;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, color, g, used, order);
		}
	}
	order.push_back(v);
}

int main() {
	ifstream cin("cond.in");
	ofstream cout("cond.out");

	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n), h(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		h[b - 1].push_back(a - 1);
	}
	vector <int> order;
	order.reserve(n);
	vector <int> used(n, 0);

	int color = 1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, color, g, used, order);	
			color++;
		}
	}
	used.assign(n, 0);
	color = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (!used[order[i]]) {
			dfs(order[i], color, h, used, order);
			color++;
		}
	}
	cout << color - 1 << '\n';
	for (int i = 0; i < n; i++) {
		cout << used[i] << ' ';
	}
	return 0;
}
