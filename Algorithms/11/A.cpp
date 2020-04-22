#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
 
using namespace std;
 
const long long INF = 1e15 + 7;
 
void dijkstra(int s, vector <vector <pair<int, int>>> &g, vector <long long> &dist, vector <int> &done) {
    int cur = s;
    dist[cur] = 0;
    done[cur] = 1;
    long long min_dist = INF;
    int min_v = -1;
    set<pair<long long, int>> rel;
    while (cur != -1) {
        if (!rel.empty()) {
            min_v = rel.begin()->second;
            min_dist = rel.begin()->first;
            rel.erase(rel.begin());
        } else {
            min_v = -1;
            min_dist = INF;
        }
 
        for (auto u : g[cur]) {
            if (!done[u.first]) {
                if (dist[cur] + u.second < dist[u.first]) {
                    rel.erase({ dist[u.first], u.first });
                    dist[u.first] = dist[cur] + u.second;
                    rel.insert({ dist[u.first], u.first });
                }
                if (min_dist > dist[u.first]) {
                    min_dist = dist[u.first];
                    min_v = u.first;
                }
            }
        }
        cur = min_v;
        if (min_v != -1) {
            done[min_v] = 1;
        }
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ifstream cin("pathmgep.in");
    ofstream cout("pathmgep.out");
 
    int n, s, f;
    cin >> n >> s >> f;
    vector <vector <pair<int, int>>> g(n);
 
    vector<int> done(n, 0);
    vector<long long> dist(n, INF);
    for (int i = 0; i < n; i++) {
        int a;
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a != -1) {
                g[i].push_back({ j, a });
            }
        }
    }
    dijkstra(s - 1, g, dist, done);
    if (dist[f - 1] != INF) {
        cout << dist[f - 1];
    } else {
        cout << -1;
    }
    return 0;
}
