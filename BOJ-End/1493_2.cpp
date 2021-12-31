//https://www.acmicpc.net/problem/1493
//박스 채우기 2
//진짜 dp버전

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
/* 
37 42 59
여기에서 32 32 32 친구가 하나 들어가면
-> 쪼개줘야함.
000022 여기에 뚜껑전체로 나눈다.
000022 0부분은 이제 2^n승꼴로 주는 인풋, 최대한 넣고..(있다면)
000022 남은 것에 대해서는 재귀로 박아버린다.
000022 한 친구에 대해서, 2^2^2꼴이면, 리턴박아버린다.
111133 1*1*1이어도, return박아버린다.
111133
111133 




분할정복하다가 if 제일 작은큐브의 크기에 범점하면? 1 return

 */
vector<pair<int, int>> cubes(20);
int cube_num;

bool flag = false;

int cube_func(int l, int w, int h) {
  //cout << l << " " << w << " " << h << "called" << endl;
  if (l == 0 || w == 0 || h == 0) {
    return 0;
  }

  int toreturn = 0;
  int bcube_size, bcube_num;
  int bindex = 0;
  //가장 큰 큐브를 고르는 단계.
  while (1) {
    bcube_size = cubes[bindex].first;
    bcube_num = cubes[bindex].second;
    if (bindex >= cube_num) {
      cout << "-1";
      exit(0);  //종료조건
    }
    if (bcube_num == 0) {  // 그냥 현재 제일 큰게 없어서 넘기는거임.
      bindex++;
      continue;
    } else {
      if (l >= bcube_size && w >= bcube_size && h >= bcube_size) {
        cubes[bindex].second -= 1;
        break;
      }
      bindex += 1;  //다음 친구를 봐야함.
    }
  }

  toreturn += 1;
  toreturn += cube_func(l - bcube_size, w, bcube_size);
  toreturn += cube_func(l, w, h - bcube_size);  //뚜껑
  toreturn += cube_func(bcube_size, w - bcube_size, bcube_size);
  return toreturn;
}

int main() {
  int length, width, height;
  cin >> length >> width >> height;

  cin >> cube_num;

  for (int i = cube_num - 1; i >= 0; i--) {
    int first, second;
    cin >> first >> second;
    cubes[i] = {pow(2, first), second};
  }
  int toret = cube_func(length, width, height);
  cout << toret;
  return 0;
  //제일 큰 큐브가 index 0에 있도록.
}