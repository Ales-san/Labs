#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
 
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
 
double get_dist(int a, int b, vector<pair<int, int>> &v) {
    return sqrt((v[a].first - v[b].first) * (v[a].first - v[b].first) +
        (v[a].second - v[b].second) * (v[a].second - v[b].second));
}
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ifstream cin("spantree.in");
    ofstream cout("spantree.out");
 
    int n, m;
    cin >> n;
    //vector <vector <int>> g(n);
    vector<pair<int, int>> v(n);
    vector<double> dist(n, INF);
    set<int> nused;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        nused.insert(i);
    }
 
    int cur = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int ncur = cur;
        double min_dist = INF;
        for (auto u : nused) {
            dist[u] = min(dist[u], get_dist(cur, u, v));
            if (min_dist > dist[u]) {
                min_dist = dist[u];
                ncur = u;
            }
        }
        nused.erase(ncur);
        cur = ncur;
        ans += min_dist;
    }
    cout << fixed << setprecision(5) << ans;
    return 0;
}
