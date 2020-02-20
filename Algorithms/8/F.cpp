#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
#include <string>

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

string modified_bfs(int start, int end, int n, vector <vector <pair<int, char>>> &g) {
  vector<pair<int, char>> prev(n, { INF, '!'});
  queue <int> q;
  q.push(start);
  prev[start] = { start, '!' };
  int cur = -1;
  while (!q.empty() && cur != end) {
    cur = q.front();
    q.pop();
    for (auto to : g[cur]) {
      if (prev[to.first].first == INF) {
        prev[to.first] = { cur, to.second };
        q.push(to.first);
      }
    }
  }

  cur = end;
  string ans = "";
  while (cur != start && prev[cur].first != INF) {
    ans += prev[cur].second;
    cur = prev[cur].first;
  }
  if (cur == start) {
      return ans;
  }
  return "1-\n";
}

int get_number(int i, int j, int m) {
    return i * m + j;
}
int main() {
  ifstream cin("input.txt");
  ofstream cout("output.txt");
  int n, m;
  cin >> n >> m;
  vector <vector <pair<int, char>>> g(n * m);
  int start, end;
  for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        char c;
        cin >> c;
        int cur = get_number(i, j, m);
        if(c == 'S') {
            start = cur;
        } else if(c == 'T') {
            end = cur;
        }
        if(c != '#') {
            int to = -1;
            g[cur].push_back({cur, '!'});
            if(i > 0) {
                to = get_number(i - 1, j, m);
                if(g[to][0].first != INF) {
                    g[cur].push_back({to, 'U'});
                    g[to].push_back({cur, 'D'});
                }
            }
            if(j > 0) {
                to = get_number(i, j - 1, m);
                if(g[to][0].first != INF) {
                    g[cur].push_back({to, 'L'});
                    g[to].push_back({cur, 'R'});
                }
            }
            
        } else {
            g[cur].push_back({INF, '!'});
        }
      }
  }
 
  string ans = modified_bfs(start, end, n * m, g);
  
  cout << ans.length() << '\n';
  for(int i = ans.length() - 1; i >= 0; i--) {
  cout << ans[i];
      
  }

  
  return 0;
}
