//https://www.acmicpc.net/problem/1759
//암호 만들기

#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
vector<char> input(17);
vector<vector<int>> mask(17, vector<int>());
int L, C;

vector<int> recur2(int idx, int len) {
  if (idx == C-1) {  //마지막이면.//모음 자음 둘다 충족 못하는 조건은 x

  }
  if (len <= L) {  //전부 채웠음.
    return recur2(idx,len);
  }
}

vector<char> recursion(int mo, int ja, int len, int idx, vector<char> out) {
  if (idx == C) {  //마지막이면.//모음 자음 둘다 충족 못하는 조건은 x
    if (mo == 0) {
      //모음중 하나를 선택
      cout << "모음선택";
    } else if (ja < 2) {
      //자음중 하나를 선택.
      cout << "자음선택";
    }
  }
  if (len == L) {  //전부 채웠음.
    if (mo >= 1 && ja >= 2) {
      for (int i = 0; i < C; i++) {
        cout << "|";
      }
    }
  }
  recursion(mo, ja, len, idx + 1, out);  //선택x
  char now = input[idx];
  out.push_back(now);
  if (input[idx] == 'a' || input[idx] == 'e' || input[idx] == 'i' || input[idx] == 'o' || input[idx] == 'u') {
    recursion(mo + 1, ja, len + 1, idx + 1, out);  //모음넣음
  } else {
    recursion(mo + 1, ja + 1, len + 1, idx + 1, out);  //자음 넣음
  }
}

int main() {
  //증가하는 문자열 문제(조합 문제)(최소 1개의 모음, 최소 2개의 자음)
  cin >> L >> C;

  for (int i = 0; i < C; i++) {
    cin >> input[i];
  }
  sort(input.begin(), input.end());
  for (int i = 0; i < C; i++) {
    cout << input[i] << " ";
  }
  vector<char> out;
  recur2(0,0);
  
}