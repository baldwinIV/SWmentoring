//https://www.acmicpc.net/problem/1013
//아레시보 천체 망원경

#include <algorithm>
#include <iostream>
#include <regex>
#include <vector>
using namespace std;
//(100+1+ | 01)+ 의 패턴을 지니는 전파를 가려내는 프로그램을 필요로 한다.
//정규표현식을 사용하여 해결한다.
bool pattern(string input) {
  regex hundred("((100+1+)|01)+");
  return regex_match(input, hundred);
}
//pattern을 지니는 친구는..

int main() {
  int num_tc;
  cin >> num_tc;
  vector<string> input(num_tc, string());
  for (int i = 0; i < num_tc; i++) {
    cin >> input[i];

  }
  for (int i = 0; i < num_tc; i++) {
    if (pattern(input[i]))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
