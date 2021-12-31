
// https://www.acmicpc.net/problem/1245
//농장관리
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
한점에 대해 같으면? 큐에 넣고, 다확인하는 과정을 거침.
          크면? x
          작으면? ok
          점에대해 visited가 있어야한다.
          한점을 방문하면 이
          1. 모든점에대해 visited일 경우에만 검사.
          2. bfs로 모든 높이가 같은 점에 대해서 검사.
          3. 검사 중간에 한번이라도 아닐경우 -> flag설정
          4. 산봉우리인 점이 검증되면 flag가 true일거임
          5. 검사는 끝까지 하는거임.
          6. 모든 장기판을 한번씩 다 순회해보면. 산봉우리가 몇개인지 나올거임
*/

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> height(n + 2, vector<int>(m + 2, -1));
  vector<vector<int>> visited(n + 2, vector<int>(m + 2, 0));

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      scanf("%d", &height[i][j]);
    }
  }
  // for (int i = 0; i < n + 2; i++) {
  //   for (int j = 0; j < m + 2; j++) {
  //     printf("%d ", height[i][j]);
  //   }
  //   printf("\n");
  // }
  queue<pair<int, int>> bfs;
  // printf("asd");
  int num_of_mountain = 0;
  bool mt_flag = true;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      // printf("제발 되어줘");
      if (visited[i][j]) {
        mt_flag = true;
        continue;
      }
      bfs.push({i, j});
      while (!bfs.empty()) {
        int cur_x = bfs.front().first;
        int cur_y = bfs.front().second;
        //printf("cur_x:%d y:%d value %d\n",cur_x,cur_y,height[cur_x][cur_y]);
        int cur_height = height[cur_x][cur_y];
        // front에 대해 검사한다.
        bfs.pop();
        for (int k = cur_x - 1; k <= cur_x + 1; k++) {
          for (int l = cur_y - 1; l <= cur_y + 1; l++) {
            if (cur_x == k && cur_y == l) continue;
            if (visited[k][l] == 0) {            //방문안해본 점인데.
              if (height[k][l] == cur_height) {  //너 나랑 높이가 같니?
                bfs.push({k, l});
                visited[k][l] = 1;
              }
            }
            if (height[k][l] > cur_height) {
              //printf("검사 %d cur %d \n",height[k][l],cur_height);
              mt_flag = false;
            }
          }
        }
      }
      // bfs탐색이 끝남
      //printf("flag: %d\n", mt_flag);
      if (mt_flag == true) num_of_mountain += 1;
      mt_flag = true;
    }
  }
  printf("%d", num_of_mountain);
}