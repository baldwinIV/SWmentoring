// https://www.acmicpc.net/problem/1074
// Z
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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
typedef int ll;
pair<int, int> dxdy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
ll N, R, C;
ll visited = 0;
ll result;
vector<ll> dp(20, 0);
ll recur(ll row, ll col, ll argN) {
  // cout << row << " " << col << " " << argN << endl;
  if (argN == 1) {
    // cout << "visited" << endl;
    visited += 1;
    if (R == row && C == col) {
      // cout << "gay";
      result = visited - 1;
      // exit(0);
    }
    return 1;
  } else {
    ll nextN = argN / 2;
    ll dpN = (ll)(log(nextN) / log(2));
    ll a, b, c, d;
    if (row <= R && R < row + nextN && col <= C && C < col + nextN) {  //여기는 조져야함. if (dp[nextN] != 0) {}
      a = recur(row, col, nextN);
      dp[dpN] = a;
    } else if (dp[dpN] == 0) {  //조건은 아닌데.. 0이면?
      a = recur(row, col, nextN);
      dp[dpN] = a;
    } else if (dp[dpN] != 0) {
      visited += dp[dpN];
      a = dp[dpN];
    }
    if (row <= R && R < row + nextN && col + nextN <= C && C < col + nextN * 2) {
      b = recur(row, col + nextN, nextN);
      dp[dpN] = b;
    } else if (dp[dpN] == 0) {  //조건은 아닌데.. 0이면?
      b = recur(row, col + nextN, nextN);
      dp[dpN] = b;
    } else if (dp[dpN] != 0) {
      visited += dp[dpN];
      b = dp[dpN];
    }
    if (row + nextN <= R && R < row + nextN * 2 && col <= C && C < col + nextN) {
      c = recur(row + nextN, col, nextN);
      dp[dpN] = c;
    } else if (dp[dpN] == 0) {  //조건은 아닌데.. 0이면?
      c = recur(row + nextN, col, nextN);
      dp[dpN] = c;
    } else if (dp[dpN] != 0) {
      visited += dp[dpN];
      c = dp[dpN];
    }
    if (row + nextN <= R && R < row + nextN * 2 && col + nextN <= C && C < col + nextN * 2) {
      d = recur(row + nextN, col + nextN, nextN);
      dp[dpN] = d;
    } else if (dp[dpN] == 0) {  //조건은 아닌데.. 0이면?
      d = recur(row + nextN, col + nextN, nextN);
      dp[dpN] = d;
    } else if (dp[dpN] != 0) {
      visited += dp[dpN];
      d = dp[dpN];
    }
    return a + b + c + d;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  cin >> R;
  cin >> C;
  if (R > pow(2, N) || C > pow(2, N)) {
    return 0;
  }
  recur(0, 0, pow(2, N));
  cout << result << endl;
  return 0;
}
