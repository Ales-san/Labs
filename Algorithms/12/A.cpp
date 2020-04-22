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
    int weight, flow;
    edge() {};
    edge(int b, int e, int w, int f) : begin(b), end(e), weight(w), flow(f) {};
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
 
    ifstream cin("maxflow.in");
    ofstream cout("maxflow.out");
 
    int n, m;
    cin >> n >> m;
    vector <vector<int>> g(n);
 
    vector<edge> edges;
    vector<int> dist(n, INF);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a - 1].push_back(2 * i);
        g[b - 1].push_back(2 * i + 1);
        edges.push_back({ a - 1, b - 1, w, 0 });
        edges.push_back({ b - 1, a - 1, 0, 0 });
    }
 
    cout << get_flow(0, n - 1, g, edges);
 
    return 0;
}
