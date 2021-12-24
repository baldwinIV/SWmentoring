#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class docs {  //문서 클래스
 public:
  docs(){};
  docs(int _prio, int _loc) {
    docs_priorities = _prio;
    location = _loc;
  }

  int docs_priorities;
  int location;

  struct ByPrio {
    bool operator()(const docs &a, const docs &b) const {
      return a.docs_priorities < b.docs_priorities;
    }
  };

};

int solution(vector<int> priorities, int location) {
  int answer = 0;

  vector<docs> docs_vec;
  for (int i = 0; i < priorities.size(); i++) {
    docs_vec.push_back(docs(priorities[i], i));
  }

  while (!docs_vec.empty()) {
    docs cur_docs = docs_vec[0];
    docs_vec.erase(docs_vec.begin());  //지우고, 맥스 확인해봐.
    docs max = *max_element(docs_vec.begin(), docs_vec.end(), docs::ByPrio());
    //최대의 주소를 반환한다.
    if (max.docs_priorities > cur_docs.docs_priorities) {  //뒤로 가버림
      docs_vec.push_back(cur_docs);
    } else {  //출력됨.. 출력되는데.. location이 맞으면?
    // int vector가 아니라. 구조체를 만들어서 해결해야할듯.!
    //   printf("prio %d loc%d answer %d\n", cur_docs.docs_priorities,
    //          cur_docs.location, answer);
      if(cur_docs.location == location){
          break;
      }
      answer++;
    }
  }

  return answer + 1;
}

int main() {
  vector<int> prio = {1, 1, 9, 1, 1, 1};
  int location = 0;
  printf("answer :%d", solution(prio, location));
  return 0;
}