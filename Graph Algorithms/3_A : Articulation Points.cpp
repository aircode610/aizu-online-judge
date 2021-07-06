#include <bits/stdc++.h>

using namespace std;

const int M = 1e5+10;
int V, E, r, dep[M];
bool mark[M], ap[M];
vector<int> g[M];

int dfs(int v, int h){
  mark[v] = true;
  dep[v] = h;
  int cnt = 0, ret = M;
  for (auto u : g[v]){
    if (!mark[u]){
      cnt++;
      int back = dfs(u, h+1);
      if (back == h)
	ap[v] = true;
      ret = min(ret, back);
    }
    else
      ret = min(ret, dep[u]);
  }
  if (v == r && cnt == 1)
    ap[r] = false;
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
  r = 0;
  dfs(0, 0);
  for (int i = 0; i <= V; i++)
    if (ap[i])
      cout << i << endl;
  return 0;
}
