//https://www.acmicpc.net/problem/2688
// 줄어들지 않아

/* 
각 자리 수 가 그 왼쪽 자리보다 작거나 같을때
 0000부터 시작해서
 1의자리수부터 늘림 -> 1의 자리수 리셋.
 2의자리수를 하나 올리고, 2의자리수로 1의자리수를 세팅, 늘림 -> 2의자리수루프가 다돌아서 0099가 됨
 3의자리수를 하나 올리고, 2의자리수, 1의자리수를 세팅, 2의자리수의 과정을 다시 거침 ... 재귀한다!
 전체 자릿수,  현재 검사 자릿수의 숫자.?
 incresing(5,0) -> (4,0) + (4,1) + (4,2) + (4,3) ... + (4,9)

 incresing(4,0) -> 0 000 
    sum increasing(3,0~9)
        000...999
 incresing(4,1) -> 1 111
    sum increasing(3,1~9)
        111...999
 incresing(4,2) -> 2 222
    sum increasing(3,2~9)
        222...999
 incresing(4,3) -> 3 333
    sum increasing(3,3~9)
 ...
 incresing(4,9) -> 9 999
    sum increasing(3,9~9)
        999.999

종료조건 : N == N_number_now이면? 그냥 1리턴
         N == 1이면? 
         incresing(2,0) -> (1,0) -> 9개, ()
.
 */
#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> tomem(100, vector<long long>(100, -1));

long long increasing(int N, int N_number_now) {
  long long count = 0;
  if (N == 1) {
    return 10 - N_number_now;
  }
  if (tomem[N][N_number_now] != -1) {
    return tomem[N][N_number_now];
  }
  for (int i = N_number_now; i < 10; i++) {
    count += increasing(N - 1, i);
  }
  tomem[N][N_number_now] = count;
  return count;
}

int main() {
  int num_testcase;  //자릿수
  cin >> num_testcase;
  vector<int> N(num_testcase);
  for (int i = 0; i < num_testcase; i++) {
    cin >> N[i];
  }
  for (int i = 0; i < num_testcase; i++) {
    cout << increasing(N[i], 0) << endl;
  }
}