#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

int dfs(int v, vector <vector<int>> &g, vector<int> &used, vector<int> &match) {
	used[v] = 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			used[u] = 1;
			if (match[u] == INF || dfs(match[u], g, used, match)) {
				match[v] = u;
				match[u] = v;
				return 1;
			}
			
		}

	}
	return 0;
}

int get_flow(int n, int m, vector <vector<int>> &g, vector<int> &used, vector<int> &match) {
	used.assign(n + m, 0);
	for (int i = 0; i < n; i++) {
		if (match[i] == INF && !used[i]) {
			if (dfs(i, g, used, match)) {
				return 1;
			}
		}
	}
	return 0;
}


int kun(int n, int m, vector <vector<int>> &g) {
	vector<int> used, match(n + m, INF);
	int ans = 0;
	while (get_flow(n, m, g, used, match)) {
		ans++;
	}
	return ans;
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ifstream cin("matching.in");
	ofstream cout("matching.out");

	int n, m, k;
	cin >> n >> m >> k;
	vector <vector<int>> g(n + m);

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(n + b - 1);
		g[n + b - 1].push_back(a - 1);
	}

	cout << kun(n, m, g);

	return 0;
}
