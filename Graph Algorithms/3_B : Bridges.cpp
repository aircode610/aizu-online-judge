#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+10;
int V, E, dep[M];
bool mark[M];
vector<int> g[M];
vector<pair<int, int> > bridges;

int dfs(int v, int par, int h){
  mark[v] = true;
  dep[v] = h;
  int ret = M;
  for (auto u : g[v]){
    if (!mark[u]){
      int back = dfs(u, v, h+1);
      if (back > h)
	bridges.push_back({min(u, v), max(u, v)});
      ret = min(ret, back);
    }
    else if (u != par)
      ret = min(ret, dep[u]);
  }
  return ret;
}

int main() {
  cin >> V >> E;
  for (int i = 1; i <= E; i++){
    int s, t;
    cin >> s >> t;
    g[s].push_back(t);
    g[t].push_back(s);
  }
  dfs(0, 0, 0);
  sort(bridges.begin(), bridges.end());
  for (int i = 0; i < bridges.size(); i++)
    cout << bridges[i].first << ' ' << bridges[i].second << endl;
  return 0;
}
