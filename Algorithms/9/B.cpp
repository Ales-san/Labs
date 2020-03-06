#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int top_sort(int v, vector <vector <int>> &g, vector <int> &used, vector <int> &ans) {
	used[v] = 1;
	int f = 1;
	ans.push_back(v);
	for (auto u : g[v]) {
		if (!used[u]) {
			f = top_sort(u, g, used, ans);
		} else if (used[u] == 1) {
			ans.push_back(u);
			return -1;
		}
		if (f == -1) {
			return f;
		}
	}
	ans.push_back(v);
	used[v] = 2;
	return f;
}

int main() {
	ifstream cin("cycle.in");
	ofstream cout("cycle.out");

	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
	}
	vector <int> ans;
	vector <int> used(n, 0);

	vector<int> cycle;
	for (int i = 0; i < n; i++) {
		if (!used[i] && top_sort(i, g, used, ans) == -1) {
			cout << "YES\n";
			for (int i = ans.size() - 2; i >= 0 && ans[i] != ans[ans.size() - 1]; i--) {
				if (cycle.size() == 0 || cycle.back() != ans[i]) {
					cycle.push_back(ans[i]);
				} else {
					cycle.pop_back();
				}
			}
			cycle.push_back(ans[ans.size() - 1]);
			for (int i = cycle.size() - 1; i >= 0; i--) {
				cout << cycle[i] + 1 << ' ';
			}
			
			return 0;
		}
	}

	cout << "NO";

	return 0;
}
