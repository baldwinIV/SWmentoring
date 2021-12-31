#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int deal_str(stack<int>& gui_str, int _prat) {
  int toret = 0;
  while (1) {
    if (gui_str.empty() == true) {
      gui_str.push(_prat);
      toret += 1;
      // cout << "empty";
      return toret;  //한번 누름.
    }                //비었으면.
    if (gui_str.top() < _prat) {
      gui_str.push(_prat);
      toret += 1;  //눌러야지.
      // cout << "big";
      return toret;
    } else if (gui_str.top() > _prat) {
      toret += 1;  //떼야지
      // cout << "small";
      gui_str.pop();
    } else if (gui_str.top() == _prat) {
    //   toret += 1;    //떼야지
      return toret;  //같으면 그냥 치면 되는부분임.
    }
  }
}
// int main() {
//   FILE* fp = fopen("2841.txt", "r");
//   if (!fp) {
//     printf("error");
//     return -1;
//   }
//   int result = 0;
//   int n, p;  // n: 멜로디에 포함된 음의 수 , p 프랫의 수
//   vector<stack<int>> guitar(6);  // 0 to 5
//   fscanf(fp, "%d %d", &n, &p);
//   for (int i = 0; i < n; i++) {
//     int cur_string, cur_prat;
//     fscanf(fp, "%d %d", &cur_string, &cur_prat);
//     cur_string -= 1;  // index와 string input을 맞추기 위함이다.
//                       // result는 몇번 움직이는가..!
//     result += deal_str(guitar[cur_string], cur_prat);
//   }
//   printf("%d", result);
//   fclose(fp);
//   return 0;
// }

int main() {
  int result = 0;
  int n, p;  // n: 멜로디에 포함된 음의 수 , p 프랫의 수
  vector<stack<int>> guitar(6);  // 0 to 5
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; i++) {
    int cur_string, cur_prat;
    scanf("%d %d", &cur_string, &cur_prat);
    cur_string -= 1;  // index와 string input을 맞추기 위함이다.
                      // result는 몇번 움직이는가..!
    result += deal_str(guitar[cur_string], cur_prat);
  }
  printf("%d", result);
  return 0;
}