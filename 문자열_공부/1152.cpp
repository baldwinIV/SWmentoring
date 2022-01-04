//https://www.acmicpc.net/problem/1152
//단어의 개수

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define PRINTVEC(x) \
  for (auto &macro_iter : x) std::cout << macro_iter << '\n';

vector<string> split(string input, char delimiter) {
  vector<string> result;
  stringstream ss(input);
  string tmp;
  while (getline(ss, tmp, delimiter)) {
    if (tmp == " ") continue;
    //cout << "[" << tmp << "]";
    result.push_back(tmp);
  }
  return result;
}
int main() {
  vector<string> x;
  x.clear();
  string strbuf;
  getline(cin, strbuf);
  x = split(strbuf, ' ');
  int toret = x.size();
  if (x[0].size() == 0) {
    toret -= 1;
  }

  cout << toret << endl;
}
//  The Curious Case of Benjamin Button