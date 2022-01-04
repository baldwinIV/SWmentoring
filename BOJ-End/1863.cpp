#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
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
//맨 밑서부터 한줄씩 스캔한다.
// row 줄 덩어리에 대해 위에도 본인과 똑같지 않으면 +1해준다
// 1.표시하기. 2. row줄 덩어리 scan하기. 3. 위에랑 똑같은지 확인하기.
// 올라갔다 내려오면.. 1다음에 0으로가.. 그러면 높이 1인 건물이 하나 있는거임
// 2다음에 0으로가 .. 그러면 높이 2인 건물이 하나 있는거임
// 어쨌든 나보다 내려가면.. 건물 높이 +1해주면 되는 부분
// 2로 올라갔다가.. 2-> 1로 내려오면,, 2인 건물 높이 하나 추가..
// 다시 1-> 3갔다가. 3에서 1로 오르막길 내리막길 쳤으니.. 3인 건물 높이 하나 추가.
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ci(num);
  vector<pair<int, int>> list;
  stack<pair<int, int>> _stack;
  list.push_back({0, 0});
  _stack.push({0, 0});
  for (int i = 0; i < num; i++) {
    ci(first);
    ci(second);
    list.push_back({first, second});
  }
  list.push_back({num + 1, 0});
  int buildings = 0;
  for (int i = 1; i < num + 2; i++) {  //인풋만 검사, 앞뒤로는 x
    //cout << list[i].first << " " << list[i].second << " ";
    pair<int, int> examine_now = list[i];
    if (list[i - 1].second < list[i].second) {  // 내가 전거보다 커 (나는 올라가)
      _stack.push(examine_now);
      //cout << "push" << _stack.top().second << " " << _stack.size() << endl;
      //전거보다 크면 내가 암온 탑임.
    }                                           //스택에는 이제까지 최정상 후보가 유지됨..
    if (list[i - 1].second > list[i].second) {  //내가 전거보다 작아..
      while (_stack.top().second > list[i].second) {
        //cout << "pop " << _stack.top().second << " " << _stack.size() << endl;
        _stack.pop();
        buildings += 1;
      }
      if (_stack.top().second < list[i].second) {
        _stack.push(examine_now);
      }
    }
  }
  cout << buildings;
  return 0;
}
//다음 높이가 낮을때? 그 높이일때까지 stack을 pop.. stack은 현재 최고 높이가 유지되는거..
/*
1
12
123
12345
1234
1
1

1
1234
12345
123
12
1
1

1
111
11
1

 */
