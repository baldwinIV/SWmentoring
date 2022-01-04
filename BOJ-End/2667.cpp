//https://www.acmicpc.net/problem/2667
//단지번호 붙이기

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
vector<vector<int>> map(27, vector<int>(27, 0));
vector<vector<bool>> visited(27, vector<bool>(27, false));
vector<int> num_of_house;
pair<int, int> dxdy[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int main() {
  int map_size;
  cin >> map_size;
  for (int i = 1; i <= map_size; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 1; j <= map_size; j++) {
      map[i][j] = tmp[j - 1] - '0';
    }
  }
  queue<pair<int, int>> bfs;

  for (int i = 1; i <= map_size; i++) {
    for (int j = 1; j <= map_size; j++) {
      if (visited[i][j] == true) continue;  //방문한적이 있으면 -> continue
      if (map[i][j] == 0) continue;         // 0인 부분은 관심없다.
      bfs.push({i, j});
      //cout << i << "|" << j << " " << map[i][j] << endl;  //0도아니고 방문한적도 없으면
      int count_house = 1;
      visited[i][j] = true;
      while (!bfs.empty()) {
        pair<int, int> now_search = bfs.front();
        bfs.pop();
        for (int k = 0; k < 4; k++)  // 네 방향을 확인한다.
        {
          int next_row = now_search.first + dxdy[k].first;
          int next_col = now_search.second + dxdy[k].second;
          if (next_row < 1 || next_row > map_size || next_col < 1 || next_col > map_size) continue;
          if (visited[next_row][next_col] == true) continue;
          if (map[next_row][next_col] != 0) {
            bfs.push({next_row, next_col});
            //cout << next_row << " " << next_col << endl;
            count_house += 1;
            visited[next_row][next_col] = true;
          }
        }
      }
      num_of_house.push_back(count_house);
    }
  }
  sort(num_of_house.begin(), num_of_house.end());
  cout << num_of_house.size() << endl;
  for (auto iter = num_of_house.begin(); iter != num_of_house.end(); iter++) {
    cout << *iter << endl;
  }
}
