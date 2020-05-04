#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int INF = 1e9 + 7;

class edge {
public:
	int begin, end;
	int weight, flow, low = 0;
	edge() {};
	edge(int b, int e, int w, int f) : begin(b), end(e), weight(w), flow(f) {};

	edge(int b, int e, int w, int f, int l) : begin(b), end(e), weight(w), flow(f), low(l) {};
};

int bfs(int s, int t, int n, vector <vector<int>> &g, vector <int> &dist, vector<edge> &edges) {
	dist.assign(n, -1);
	queue <int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty() && dist[t] == -1) {
		int v = q.front();
		q.pop();
		for (auto u : g[v]) {
			if (dist[edges[u].end] == -1 && edges[u].flow < edges[u].weight) {
				q.push(edges[u].end);
				dist[edges[u].end] = dist[v] + 1;
			}
		}
	}
	if (dist[t] != -1) {
		return 1;
	}
	return 0;
}

int dfs(int v, int t, int cur, vector <vector<int>> &g, vector<int> &last, vector<int> &dist, vector<edge> &edges) {
	if (v == t) {
		return cur;
	}
	if (!cur) {
		return 0;
	}
	for (; last[v] < g[v].size(); last[v]++) {
		int u = g[v][last[v]];
		if (dist[edges[u].end] == dist[v] + 1) {
			int res = dfs(edges[u].end, t, min(cur, edges[u].weight - edges[u].flow), g, last, dist, edges);
			if (res) {
				edges[u].flow += res;
				if (u % 2) {
					edges[u - 1].flow -= res;
				}
				else {
					edges[u + 1].flow -= res;
				}
				return res;
			}
		}
	}
	return 0;
}

int get_flow(int s, int t, vector <vector<int>> &g, vector<edge> &edges) {
	vector<int> dist, last;
	int ans = 0;
	while (bfs(s, t, t + 1, g, dist, edges)) {
		last.assign(t + 1, 0);
		int f = dfs(s, t, INF, g, last, dist, edges);
		while (f) {
			ans += f;
			f = dfs(s, t, INF, g, last, dist, edges);
		}
	}
	return ans;
}


signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ifstream cin("circulation.in");
	ofstream cout("circulation.out");

	int n, m;
	cin >> n >> m;
	vector <vector<int>> g(n + 2);

	vector<edge> edges;
	vector<int> dist(n, INF);
	for (int i = 0, cnt = 0; i < m; i++) {
		int a, b, w, l;
		cin >> a >> b >> l >> w;
		g[a].push_back(cnt++);
		g[b].push_back(cnt++);
		edges.push_back({ a, b, w - l, 0, l});
		edges.push_back({ b, a, 0, 0 });

		g[0].push_back(cnt++);
		g[b].push_back(cnt++);
		edges.push_back({ 0, b, l, 0 });
		edges.push_back({ b, 0, 0, 0 });

		g[a].push_back(cnt++);
		g[n + 1].push_back(cnt++);
		edges.push_back({ a, n + 1, l, 0 });
		edges.push_back({ n + 1, a, 0, 0 });
	}

	int res = get_flow(0, n + 1, g, edges);
	for (auto u : g[0]) {
		if (edges[u].flow < edges[u].weight) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for (int i = 0; i < edges.size(); i += 2) {
		if (edges[i].begin != 0 && edges[i].end != n + 1) {
			cout << edges[i].flow + edges[i].low << '\n';
		}
	}

	return 0;
}