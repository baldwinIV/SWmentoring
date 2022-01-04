//https://www.acmicpc.net/problem/1139
//울타리 
//메모이제이션을 비트마스크 메모이제이션? 100비트짜리 비트마스크가 필요하다..
// map을 사용해서 비트마스크 값과, 해당 넓이를 저장해놓는다.
// 재귀적으로 탐색하면서 삼각형 넓이의 합이 최대인 부분을 찾는다?
//
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>


using namespace std;

void printwall(vector<double> &wall) {
  for (auto i = wall.begin(); i != wall.end(); i++) {
    cout << *i << " ";
  }
  cout << "\n";
}
int main() {
  int N;
  cin >> N;
  vector<double> wall(N);

  for (int i = 0; i < N; i++) {
    cin >> wall[i];
  }
  //sort하기.
  sort(wall.begin(), wall.end(), less());
  //삼각형의 결정조건 >> 가장 큰 변의 길이가 다른 두 변의 길이의 합보다 작아야한다.(less not equal)
  //삼각형의 넓이 >> (a+b+c)/2 = p일때 (p(p-a)(p-b)(p-c))^(1/2)이다.
  //15 16 21 35 44 50 54 55 63 69 69 70 72 75 76 81
  while (1) {
    double biggest_area = 0;
    for (int i = 0; i < N - 2; i++) {
      for (int j = i + 1; j < N - 1; j++) {
        double sumoftwo = wall[i] + wall[j];
        for (int k = j + 1; k < N; k++) {
          if (wall[k] >= sumoftwo) break;
          double p = (sumoftwo + wall[k]) / 2;
          double area = (p * (p - wall[i]) * (p - wall[j]) * (p - wall[k]));
          area = sqrt(area);
          cout << area << "\n";
          if (area > biggest_area){
            biggest_area = area;
            int biggest;
        }
        cout << endl;
      }
    }
    cout << "\nanswer :" << biggest_area;
  }
}
