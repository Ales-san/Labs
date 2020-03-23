#include <iostream>
#include <fstream>
#include <vector>
#include <map>
 
using namespace std;
 
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
 
    ifstream cin("input.txt");
    ofstream cout("output.txt");
 
    int n, m;
    cin >> n >> m;
    //vector <vector <int>> g(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        //g[a - 1].push_back(b - 1);
        deg[a - 1]++;
        deg[b - 1]++;
    }
 
    for (auto u : deg) {
        cout << u << ' ';
    }
     
    return 0;
}
