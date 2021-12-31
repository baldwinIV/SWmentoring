//https://www.acmicpc.net/problem/2606
//바이러스

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
  int num_computer;
  int num_edge;
  cin >> num_computer >> num_edge;

  vector<vector<int>> computer(num_computer + 2, vector<int>());
  vector<bool> visited(num_computer + 2, false);
  //why? dfs 
  for (int i = 0; i < num_edge; i++) {
    int com1, com2;
    cin >> com1 >> com2;
    computer[com1].push_back(com2);
    computer[com2].push_back(com1);
  }
  stack<int> dfs;

  dfs.push(1);  // 0반 컴퓨터를 넣는다.
  visited[1] = true;
  int visited_num = 0;

  while (!dfs.empty()) {
    int cur_computer = dfs.top();
    int before_visited = visited_num;
    dfs.pop();

    for (int i = 0; i < computer[cur_computer].size(); i++) {
      int topush = computer[cur_computer][i];  //넣을 컴퓨터.
      if (visited[topush] == false) {
        dfs.push(topush);
        visited[topush] = true;
        visited_num++;
      }
    }
  }
  cout << visited_num;
//   for (int i = 1; i < num_computer + 1; i++)
//   {
//       cout << visited[i] << " ";
//   }
  
}