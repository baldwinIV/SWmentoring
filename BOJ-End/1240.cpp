// https://www.acmicpc.net/problem/1240
//노드 사이의 거리

#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// class Vertax {
//  public:
//   int value;
//   vector<pair<int, int>> edge;  // first :vertax, second : length
// };
vector<pair<int, int>> vertax[1010];
bool visited[1010];
int real_result = 0;

int dfs(int start, int end, int length) {
  visited[start] = true;
  if (start == end) {
    real_result = length;
    // printf("%d is result\n", real_result);
    return real_result;  //방문했다리~
  } else {
    for (int i = 0; i < vertax[start].size();
         i++)  // 인접한 노드 사이즈만큼 탐색
    {
      //   printf("start%d end%d\n", start, i);
      int y = vertax[start][i].first;
      int arg_length = length + vertax[start][i].second;
      if (!visited[y]) {
        dfs(y, end, arg_length);
      }
    }
  }
  return -1;
}
int main() {
  for (int j = 0; j < 1010; j++) {
    visited[j] = false;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    int vertax_a, vertax_b, length;
    scanf("%d %d %d", &vertax_a, &vertax_b, &length);
    vertax[vertax_a].push_back({vertax_b, length});  //간선 넣어줌..
    vertax[vertax_b].push_back({vertax_a, length});  //간선 넣어줌..
  }
  for (int i = 0; i < m; i++) {
    int vertax_a, vertax_b;
    scanf("%d %d", &vertax_a, &vertax_b);
    // printf("%d %d\n", vertax_a, vertax_b);
    dfs(vertax_a, vertax_b, 0);
    printf("%d\n", real_result);
    real_result = 0;
    for (int j = 0; j < 1010; j++) {
      visited[j] = false;
    }
  }
  return 0;
}

// int main() {
//   for (int j = 0; j < 1010; j++) {
//     visited[j] = false;
//   }
//   FILE* fp = fopen("input.txt", "r");
//   if (!fp) {
//     printf("error");
//     return -1;
//   }
//   int n, m;

//   fscanf(fp, "%d %d", &n, &m);
//   for (int i = 0; i < n - 1; i++) {
//     int vertax_a, vertax_b, length;
//     fscanf(fp, "%d %d %d", &vertax_a, &vertax_b, &length);
//     vertax[vertax_a].push_back({vertax_b, length});  //간선 넣어줌..
//     vertax[vertax_b].push_back({vertax_a, length});  //간선 넣어줌..
//   }
//   for (int i = 0; i < m; i++) {
//     int vertax_a, vertax_b;
//     fscanf(fp, "%d %d", &vertax_a, &vertax_b);
//     // printf("%d %d\n", vertax_a, vertax_b);
//     dfs(vertax_a, vertax_b, 0);
//     printf("%d\n", real_result);
//     real_result = 0;
//     for (int j = 0; j < 1010; j++) {
//       visited[j] = false;
//     }
//   }

//   fclose(fp);
//   return 0;
// }