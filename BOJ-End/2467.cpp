//https://www.acmicpc.net/problem/2467
//용액
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

//산성 1~ 10억
//알칼리성 음수 1~ 10억
// 벡터가 주르륵 있으면,
vector<int> input_negative;
vector<int> input_positive;
vector<int> input_negative_abs;
// 음수 양수로 나누고, 음수에서 양수로 이진탐색 조지기
// 음수끼리 절댓값 제일 작은거 구하기
// 양수끼리 절댓값 제일 작은거 구하기
//셋중에 제일 작은게 답.

int binary_search(int val, int first, int last) {
  if (first > last) {  //가장 비슷한 거라도..
                       //val과 first, val과 last중에서 덧셈해서 더 작은 녀석을 리턴한다.
    if (last < 0) return first;
    int a = abs(input_positive[first] - val);
    int b = abs(input_positive[last] - val);
    return (a > b) ? last : first;
  }
  int mid = (first + last) / 2;
  if (input_positive[mid] == val) {
    return mid;
  } else if (val < input_positive[mid])
    return binary_search(val, first, mid - 1);
  else
    return binary_search(val, mid + 1, last);
}
int main() {
  int numinput;
  cin >> numinput;
  for (int i = 0; i < numinput; i++) {
    int tmp;
    cin >> tmp;
    if (tmp >= 0)
      input_positive.push_back(tmp);
    else
      input_negative.push_back(tmp);
  }
  pair<int, int> answer;
  if (input_negative.empty()) {
    answer.first = input_positive[0];
    answer.second = input_positive[1];
  } else if (input_positive.empty()) {
    int size = input_negative.size();
    answer.first = input_negative[size - 2];
    answer.second = input_negative[size - 1];  //여기 수정ㅈ
  } else {
    int candi1, candi2, candi3;
    if (input_positive.size() >= 2) {
      candi1 = input_positive[0] + input_positive[1];
      //candi1 = 3;
    } else {
      candi1 = INT_MAX;
    }
     //cout << "candi1" << candi1 << "\n";
    if (input_negative.size() >= 2) {
      int size = input_negative.size();
      candi2 = input_negative[size - 1] + input_negative[size - 2];  //수정
    } else {
      candi2 = INT_MAX;
    }
    //cout << "candi2" << candi2 << "\n";
    for (int i = 0; i < input_negative.size(); i++) {
      input_negative_abs.push_back(abs(input_negative[i]));  //절댓값으로 다 넣고,
    }
    int possize = input_positive.size();
    candi3 = INT_MAX;
    pair<int, int> answer_pair = {-1, -1};
    for (int i = 0; i < input_negative_abs.size(); i++) {
      int arg = binary_search(input_negative_abs[i], 0, possize - 1);

     // cout << "||" << arg << " " << input_positive[arg] << " " << input_negative_abs[i] << endl;
      if (arg < 0 || arg >= possize) {
        continue;
      }
      int cal = abs(input_negative_abs[i] - input_positive[arg]);
      if (candi3 > cal) {
        //cout << "can3 " << input_negative_abs[i] << " " << input_positive[arg] << endl;
        candi3 = cal;
        answer_pair = {i, arg};
      }
    }
    //cout << candi3 << endl;
    vector<int> tosorted;
    tosorted.push_back(abs(candi1));
    tosorted.push_back(abs(candi2));
    tosorted.push_back(abs(candi3));
    sort(tosorted.begin(), tosorted.end());
    int real_answer = tosorted[0];
    //cout << "tosorted" << tosorted[0] << " " << tosorted[1] << " " << tosorted[2] << endl;
    if (real_answer == abs(candi1)) {
      //cout << "candi1 " << candi1;
      answer.first = input_positive[0];
      answer.second = input_positive[1];
    } else if (real_answer == abs(candi2)) {
      //cout << "candi2 " << candi2;
      int size = input_negative.size();
      answer.first = input_negative[size - 2];
      answer.second = input_negative[size - 1];
    } else {
      //cout << "candi3 " << candi3;
      answer.first = input_negative[answer_pair.first];
      answer.second = input_positive[answer_pair.second];
    }
  }

  cout << answer.first << " " << answer.second;
}