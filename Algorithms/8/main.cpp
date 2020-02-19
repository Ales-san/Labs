#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

void bfs(int start, vector <vector <int>> &g, vector <int> &dist) {
	dist[start] = 0;

	queue <int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto to : g[cur]) {
			if (dist[to] == INF) {
				dist[to] = dist[cur] + 1;
				q.push(to);
			}
		}
	}
}

void dfs(int cur, vector <vector <int>> &g, vector <int> &used, int &cnt) {
	used[cur] = cnt;
	for (auto to : g[cur]) {
		if (!used[to]) {
			dfs(to, g, used, cnt);
		}
	}
}

int main() {
	ifstream cin("pathbge1.in");
	ofstream cout("pathbge1.out");
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	vector <int> dist(n, INF);
	int cnt = 1;
	bfs(0, g, dist);

	for (int i = 0; i < n; i++) {
		cout << dist[i] << ' ';
	}

	
	return 0;
}