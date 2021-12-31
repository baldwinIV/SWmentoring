// https://www.acmicpc.net/problem/1260
// dfs와 bfs
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  // FILE* fp = fopen("input.txt", "r");
  // if (!fp) {
  //   printf("error");
  //   return -1;
  // }
  int n, m, v;
  scanf("%d %d %d", &n, &m, &v);
  vector<int> g[n + 1];
  bool visited[n + 1];
  bool ispushed[n + 1];
  for (int i = 0; i < n + 1; i++) {
    visited[i] = false;
    ispushed[i] = false;
  }

  for (int i = 0; i < m; i++) {
    int edge_first, edge_second;
    scanf("%d %d", &edge_first, &edge_second);
    g[edge_second].push_back(edge_first);
    g[edge_first].push_back(edge_second);
  }

  //스타트 방문 처리하고
  queue<int> bfs;
  stack<int> dfs;

  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end(), greater<int>());  //오름차순 정렬
  }

  for (int i = 0; i < n + 1; i++) {
    visited[i] = false;
  }

  dfs.push(v);  //먼저  넣어준다.
  while (!dfs.empty()) {
    int now_searching = dfs.top();
    dfs.pop();
    if (visited[now_searching] == true)
      continue;
    printf("%d ", now_searching);
    visited[now_searching] = true;

    for (int i = 0; i < g[now_searching].size(); i++) {
      if (visited[g[now_searching].at(i)] == false) {
        dfs.push(g[now_searching].at(i));
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());  //오름차순 정렬
  }
  printf("\n");
  
  for (int i = 0; i < n + 1; i++) {
    visited[i] = false;
  }

  bfs.push(v);  //먼저  넣어준다.
  visited[v] = true;
  while (!bfs.empty()) {
    int now_searching = bfs.front();
    bfs.pop();
    printf("%d ", now_searching);
    for (int i = 0; i < g[now_searching].size(); i++) {
      if (visited[g[now_searching].at(i)] == false) {
        bfs.push(g[now_searching].at(i));
        visited[g[now_searching].at(i)] = true;
      }
    }
  }

  return 0;
}
