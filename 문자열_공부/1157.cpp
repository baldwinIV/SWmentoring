// https://www.acmicpc.net/problem/1157
//단어 공부

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define PRINTVEC(x) \
  for (auto &macro_iter : x) std::cout << macro_iter << '\n';

int main() {
  string word;
  map<char, int> dict;
  cin >> word;
  for (int i = 0; i < word.size(); i++) {
    char tmp = toupper(word[i]);
    if (dict.count(tmp)) {  //존재쓰
      dict[tmp] += 1;
    } else {  //안존재쓰
      dict.insert({tmp, 1});
    }
  }
  vector<pair<char, int>> tosorted(dict.begin(), dict.end());
  sort(tosorted.begin(), tosorted.end(),
       [](pair<char, int> a, pair<char, int> b) -> bool { return a.second > b.second ? true : false; });

//   for (int i = 0; i < tosorted.size(); i++) {
//     cout << tosorted[i].second << endl;
//   }
  if (tosorted.size() == 1) {
    cout << dict.find(tosorted[0].first)->first;
  } else {
    int biggest = dict.find(tosorted[0].first)->second;
    int second = dict.find(tosorted[1].first)->second;
    if (biggest == second) {
      cout << "?";
    } else {
      cout << dict.find(tosorted[0].first)->first;
    }
  }
}
