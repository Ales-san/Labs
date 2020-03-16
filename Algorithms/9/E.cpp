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

	ifstream cin("hamiltonian.in");
	ofstream cout("hamiltonian.out");

	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);
	vector<int> dr(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		dr[b - 1]++;
	}

	
	map <int, int> num;
	int v = -1;
	for (int i = 0; i < n; i++) {
		if (dr[i] == 0) {
			v = i;
		}
		if (!num.count(dr[i])) {
			num.insert({ dr[i], 1 });
		} else {
			num.at(dr[i])++;
		}
	}
	
	while (num.count(0) && num.at(0) == 1) {

		num.at(dr[v])--;
		dr[v] = -1;
		for (auto u : g[v]) {
			num.at(dr[u])--;
			dr[u]--;
			if (dr[u] == 0) {
				v = u;
			}
			if (!num.count(dr[u])) {
				num.insert({ dr[u], 1 });
			}
			else {
				num.at(dr[u])++;
			}
		}
	}
	if (!num.at(0)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
