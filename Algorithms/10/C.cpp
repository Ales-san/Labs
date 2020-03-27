#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

void dfs(int v, int color, vector <vector <int>> &g, vector <int> &used) {
	used[v] = color;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, color, g, used);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ifstream cin("spantree3.in");
	ofstream cout("spantree3.out");

	int n, m;
	cin >> n >> m;
	vector <vector <pair<int, int>>> g(n);

	vector<int> dist(n, INF);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a - 1].push_back({ b - 1, w });
		g[b - 1].push_back({ a - 1, w });
	}

	set <pair<int, int>> q;

	int cur = 0;
	long long ans = 0;
	g[cur].push_back({ cur, 0 });
	for (int i = 0; i < n; i++) {
		int ncur = cur;
		int min_dist = INF;
		for (auto u : g[cur]) {
			if (dist[u.first] > u.second) {
				if (dist[u.first] != INF && q.count({ dist[u.first], u.first })) {
					q.erase({ dist[u.first], u.first });
					q.insert({ u.second, u.first });
				}
				else if (dist[u.first] == INF) {
					q.insert({ u.second, u.first });
				}
				dist[u.first] = u.second;
			}
		}

		cur = q.begin()->second;
		ans += q.begin()->first;
		q.erase(q.begin());
	}
	cout << ans;
	return 0;
}
