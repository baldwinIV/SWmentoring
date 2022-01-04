// https://www.acmicpc.net/problem/1012
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define PRINTVEC(x) \
  for (auto &macro_iter : x) std::cout << macro_iter << '\n';
#define ci(x) \
  int x;      \
  cin >> x;
#define cs(x) \
  string x;   \
  cin >> x;
pair<int, int> dxdy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
  ci(tc_num);
  vector<vector<vector<int>>> map(tc_num, vector<vector<int>>(54, vector<int>(54, 0)));
  vector<vector<vector<bool>>> visited(tc_num, vector<vector<bool>>(54, vector<bool>(54, false)));
  vector<int> rows(tc_num);
  vector<int> cols(tc_num);
  for (int l = 0; l < tc_num; l++) {
    ci(row);
    ci(col);
    rows[l] = row;
    cols[l] = col;
    ci(coordi_num);
    for (int i = 0; i < coordi_num; i++) {
      int first, second;
      cin >> first >> second;
      map[l][first][second] = 1;
    }
  }
  for (int l = 0; l < tc_num; l++) {
    queue<pair<int, int>> bfs;
    int result = 0;
    for (int i = 0; i < rows[l]; i++) {
      for (int j = 0; j < cols[l]; j++) {
        if (map[l][i][j] == 0) continue;
        if (visited[l][i][j] == true) continue;
        bfs.push({i, j});
        visited[l][i][j] = true;
        while (!bfs.empty()) {
          pair<int, int> coordinate = bfs.front();
          bfs.pop();
          for (int k = 0; k < 4; k++) {
            int nr = dxdy[k].first + coordinate.first;
            int nc = dxdy[k].second + coordinate.second;
            if (nr > rows[l] - 1 || nr < 0 || nc > cols[l] - 1 || nc < 0) continue;
            if (map[l][nr][nc] == 1 && visited[l][nr][nc] == false) {
              bfs.push({nr, nc});
              visited[l][nr][nc] = true;
            }
          }
        }
        result += 1;
      }
    }
    cout << result << endl;
  }

  return 0;
}
