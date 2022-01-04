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
vector<int> wines;
vector<int> max(10002);
int num_of_wine;
int recursion(int sum, int idx, int flag) {
  if (idx == num_of_wine - 1) {
    if (flag == 2) {
      return sum;
    } else {
      return sum + wines[num_of_wine - 1];
    }
  }
  if (flag == 2) {  //두번 했다.
    return recursion(sum, idx + 1, 0);
  } else {
    int a = recursion(sum + wines[idx], idx + 1, flag + 1);  //더했다.
    int b = recursion(sum, idx + 1, 0);                      //안더했다.
    if (a > b)
      return a;
    else
      return b;
  }
}
int main() {
  cin >> num_of_wine;

  for (int i = 0; i < num_of_wine; i++) {
    int tmp;
    cin >> tmp;
    wines.push_back(tmp);
  }
  cout << recursion(0, 0, 0);
}

/* 

7
100
100
1
1
1
100
100

10
0
0
10
0
5
10
0
0
1
10

 */