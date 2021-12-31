// https://www.acmicpc.net/problem/1013
//미로 탐색
/*
    tip: 붙어있는배열? ->string으로cin하고, cin한 string의 index에 접근하여 처리
   접근하여 '0'를 하나씩 뺴준다.
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef int depth;

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};  //남쪽방향부터 반시계방향
/* 
어떻게 풀어야 할 것인지?
 -> dfs로 길을 모두 찾는다.
 ->
 111111
 111111
 111111
 111111의 경우는 어떻게 할건데? -> 최단거리는 bfs아님?

 */
int main() {
  int row, col;
  scanf("%d %d", &row, &col);
  vector<vector<int>> input(row, vector<int>(col, 1));
  vector<vector<bool>> visited(row, vector<bool>(col, false));
  string input_register;
  for (int i = 0; i < row; i++) {
    cin >> input_register;  // 스트링을 받는다.
    for (int j = 0; j < col; j++) {
      input[i][j] = input_register[j] - '0';
    }
  }
  queue<tuple<int, int, depth>> bfs;
  bfs.push({0, 0, 0});
  visited[0][0] = true;

  while (!bfs.empty()) {
    int cur_row = get<0>(bfs.front());
    int cur_col = get<1>(bfs.front());
    int cur_depth = get<2>(bfs.front());
    if (cur_row == row - 1 && cur_col == col - 1) {
      printf("%d", cur_depth + 1);
      break;
    }
    bfs.pop();
    for (int i = 0; i < 4; i++) {
      int next_row = cur_row + drow[i], next_col = cur_col + dcol[i];
      if (next_row >= row || next_row < 0 || next_col >= col || next_col < 0) continue;  //0부터 범위-1안의 인덱스안에 존재해야함
      if (input[next_row][next_col] == 0) continue; //0이면 못가는길
      if (visited[next_row][next_col] == true) continue; 
      bfs.push({next_row, next_col, cur_depth + 1});
      visited[next_row][next_col] = true;
    }
  }

  return 0;
}