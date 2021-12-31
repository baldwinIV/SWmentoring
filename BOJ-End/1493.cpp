//https://www.acmicpc.net/problem/1493
//박스 채우기

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
  cout << l << " " << w << " " << h << "called" << endl;
  if (l == 0 || w == 0 || h == 0) return 0;
  int toreturn = 0;
  int bcube_size, bcube_num;
  int bindex = 0;
  int howManyBigCube;
  //가장 큰 큐브를 고르는 단계.
  while (1) {
    bcube_size = cubes[bindex].first;
    bcube_num = cubes[bindex].second;
    if (bindex >= cube_num) {
      cout << "-1";
      exit(1);  //종료조건
    }
    if (bcube_num == 0) { // 그냥 현재 제일 큰게 없어서 넘기는거임.
      bindex++;
      cout << "next " << bindex;
      continue;
    } else {
      int divlen = l / bcube_size;
      int divwid = w / bcube_size;
      int divhei = h / bcube_size;
      howManyBigCube = divlen * divwid * divhei;  //젤 큰놈 몇개나 들어갈수 있는지?
      if (howManyBigCube != 0) { // 채울수 있을경우!
        break;
      }
      bindex +=1; //다음 친구를 봐야함.
      //못채우는 경우에는? 늘려야지..
    }
    cout << "loop" << bindex;
  }
  cout << "bindex " << bindex << "bcubesize "
       << bcube_size << " bcubenum " << bcube_num
       << " hmbc" << howManyBigCube << endl;

  if (bcube_num >= howManyBigCube) {  //제일 큰 큐브가 남음, 이제 쓸일 없음
    cubes[bindex].second -= howManyBigCube;
    toreturn += howManyBigCube;
  } else if (bcube_num < howManyBigCube) {  //제일 큰 큐브 다씀 근데 더 필요
    cout << "added";
    cubes[bindex].second = 0;
    toreturn += bcube_num;
    for (int i = 0; i < howManyBigCube - bcube_num; i++) {
      toreturn += cube_func(bcube_size, bcube_size, bcube_size);
    }
  }

  int modlen = l % bcube_size;
  int modwid = w % bcube_size;
  int modhei = h % bcube_size;
  toreturn += cube_func(l, w, modhei);
  cout << "call" << l << " " << w << " " << modhei << endl;
  toreturn += cube_func(modlen, w, bcube_size);
  cout << "call" << modlen << " " << w << " " << bcube_size << endl;
  toreturn += cube_func(modwid, bcube_size, bcube_size);
  cout << "call" << bcube_size << " " << modwid << " " << bcube_size << endl;
  cout << l << " " << w << " " << h << " toreturn" << toreturn << endl;
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