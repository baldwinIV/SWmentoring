//https://www.acmicpc.net/problem/9184
// 신나는 함수 실행

/* 
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
 */

#include <cstdio>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
map<tuple<int, int, int>, int> dp;
int w(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }
  if (a > 20 || b > 20 || c > 20) {
    if (dp.find(make_tuple(20, 20, 20)) != dp.end()) {
      return dp.find(make_tuple(20, 20, 20))->second;
    }
    int toret = w(20, 20, 20);
    dp.insert({make_tuple(20, 20, 20), toret});
    return toret;
  }
  if (a < b && b < c) {
    int first, second, third;
    if (dp.find(make_tuple(a, b, c - 1)) != dp.end()) {
      first = dp.find(make_tuple(a, b, c - 1))->second;
    } else {
      first = w(a, b, c - 1);
      dp.insert({make_tuple(a, b, c - 1), first});
    }
    if (dp.find(make_tuple(a, b - 1, c - 1)) != dp.end()) {
      second = dp.find(make_tuple(a, b - 1, c - 1))->second;
    } else {
      second = w(a, b - 1, c - 1);
      dp.insert({make_tuple(a, b - 1, c - 1), second});
    }
    if (dp.find(make_tuple(a, b - 1, c)) != dp.end()) {
      third = dp.find(make_tuple(a, b - 1, c))->second;
    } else {
      third = w(a, b - 1, c);
      dp.insert({make_tuple(a, b - 1, c), third});
    }
    return first + second - third;
  } else {
    int first, second, third, fourth;
    if (dp.find(make_tuple(a - 1, b, c)) != dp.end()) {
      first = dp.find(make_tuple(a - 1, b, c))->second;
    } else {
      first = w(a - 1, b, c);
      dp.insert({make_tuple(a - 1, b, c), first});
    }
    if (dp.find(make_tuple(a - 1, b - 1, c)) != dp.end()) {
      second = dp.find(make_tuple(a - 1, b - 1, c))->second;
    } else {
      second = w(a - 1, b - 1, c);
      dp.insert({make_tuple(a - 1, b - 1, c), second});
    }
    if (dp.find(make_tuple(a - 1, b, c - 1)) != dp.end()) {
      third = dp.find(make_tuple(a - 1, b, c - 1))->second;
    } else {
      third = w(a - 1, b, c - 1);
      dp.insert({make_tuple(a - 1, b, c - 1), third});
    }
    if (dp.find(make_tuple(a - 1, b - 1, c - 1)) != dp.end()) {
      fourth = dp.find(make_tuple(a - 1, b - 1, c - 1))->second;
    } else {
      fourth = w(a - 1, b - 1, c - 1);
      dp.insert({make_tuple(a - 1, b - 1, c - 1), fourth});
    }
    return first + second + third - fourth;
    return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  }
}

int main() {
  vector<tuple<int, int, int>> answer;
  int a, b, c;
  cin >> a >> b >> c;
  answer.push_back({a, b, c});
  while (!(a == -1 && b == -1 && c == -1)) {
    cin >> a >> b >> c;
    answer.push_back({a, b, c});
  }
  answer.pop_back();
  for (int i = 0; i < answer.size(); i++) {
    int aa = get<0>(answer[i]);
    int bb = get<1>(answer[i]);
    int cc = get<2>(answer[i]);
    printf("w(%d, %d, %d) = %d\n", aa, bb, cc, w(aa, bb, cc));
  }
}