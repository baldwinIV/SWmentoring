//https://www.acmicpc.net/problem/2156
//포도주 문제

#include <iostream>
#include <vector>
using namespace std;
//연속 세개의 잔을 마실수는 없다.
//가장 많은 양의 포도주를 마실 수 있는 방법은?
// n개까지 진행했을때. 가장 많은 포도주의 양을 저장해놓을 수 있다. x 새로운 인풋에 따라
// 그 앞까지의 배열이 바뀔 수 있음
// 모든 경우의 수가 있을거임. 어디에 x를 두느냐
// 재귀로 모든 경우의 수를 들어감..
// 안 먹 먹 안 안 먹
//
vector<int> wines(10002);
vector<int> visited(10002, -1);
int num_of_wine;
int max(int a, int b) { return (a > b ? a : b); }
int dp(int idx) {
  if (idx == 1) {
    return wines[1];
  }
  if (idx == 2) {
    if (visited[idx] == -1) {
      visited[idx] = wines[1] + wines[2];
    }
    return visited[idx];
  }
  if (idx == 3) {
    if (visited[idx] == -1) {
      int aa = wines[1] + wines[2];
      int bb = wines[1] + wines[3];
      int cc = wines[2] + wines[3];
      visited[idx] = max(aa, max(bb, cc));
      return visited[idx];
    } else {
      return visited[idx];
    }
  }
  if (visited[idx] == -1) {
    int a = dp(idx - 2) + wines[idx]; // ~~  x 0
    int b = dp(idx - 3) + wines[idx - 1] + wines[idx]; // ~~ x 0 0
    int c = dp(idx - 1); // ~~  x (현재 선택을 안하는 케이스..)
    visited[idx] = max(a, max(b, c));
  }
  return visited[idx];
}
int main() {
  cin >> num_of_wine;

  for (int i = 1; i <= num_of_wine; i++) {
    int tmp;
    cin >> tmp;
    wines[i] = tmp;
  }
  cout << dp(num_of_wine);
}