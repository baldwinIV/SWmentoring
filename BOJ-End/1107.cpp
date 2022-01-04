// https://www.acmicpc.net/problem/1107
// 리모콘
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
#define PRINTVEC(x)                 \
  for (auto &macro_iter : x) {      \
    std::cout << macro_iter << ' '; \
  }                                 \
  cout << endl;
#define ci(x) \
  int x;      \
  cin >> x;
#define cs(x) \
  string x;   \
  cin >> x;
vector<int> disable;

bool isokay(int input) {
  string a = to_string(input);
  for (int i = 0; i < a.size(); i++) {
    int tmp = a[i] - '0';
    for (int j = 0; j < disable.size(); j++) {
      if (disable[j] == tmp) return false;
    }
  }
  return true;
}

int main() {
  int now = 100;
  ci(target);
  ci(disabled);

  for (int i = 0; i < disabled; i++) {
    ci(tmp);
    disable.push_back(tmp);
  }
  if (target == 100) {
    cout << '0';
    return 0;
  }
  // PRINTVEC(available);
  int min = abs(target - 100);       //무지성으로 버튼누르기
  for (int i = 0; i < 1000001; i++)  // 12345버튼이 고장난 경우도 있을걸?
  {
    if (isokay(i)) {  //이거 되는 버튼임. 그러면 여기로 가고.
      string tmp = to_string(i);
      int tmp_size = tmp.size();
      int push_button = abs(target - i);
      if (min > tmp_size + push_button) min = tmp_size + push_button;
    }
  }
  cout << min;
  return 0;
}
