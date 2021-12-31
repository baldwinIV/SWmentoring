// https://www.acmicpc.net/problem/3190
// 뱀
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/* 
뱀의 정보를 저장해야한다.
뱀은 몸길이의 좌표, 좌표중 머리의 위치, 꼬리의 위치로 정의한다.
좌표 각각은 pair를 활용해서 사용한다
본인 몸과 부딪히는 거 확인 어떻게?
꼬리 처리후, 다음 대가리가, 대가리를 제외한 몸통과 같은 값을 vector가 갖는지?
어떤 자료구조를 써야하는지? -> 그냥 O(n)으로 한번 움직일떄마다 확인

 */
// 11 12 13
// 21 22 23
// 31 32 33
pair<int, int> direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//북쪽부터 시계방향으로 북 동 남 서
//왼쪽이 반시계 : L, 오른쪽이 시계 : D
// 왼쪽이면 direction의 index가 -1  (%4)
// 오른쪽이면 direction의 index가 +1 (%4)
//{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void printsnake(const vector<pair<int, int>> snake) {
  for (int i = 0; i < snake.size(); i++) {
    cout << "[" << snake[i].first << " " << snake[i].second << "]";
  }
  cout << endl;
}

bool isapple(const pair<int, int> next_head, vector<pair<int, int>> &apple) {
  for (int i = 0; i < apple.size(); i++) {
    if (next_head.first == apple[i].first && next_head.second == apple[i].second) {
      //cout << next_head.first << " " << next_head.second;
      //cout << "사과 ";
      apple.erase(apple.begin() + i);
      return true;
    }
  }
  return false;
}

bool isbody(const vector<pair<int, int>> snake) {
  pair<int, int> head = snake[0];
  for (int i = 1; i < snake.size(); i++) {
    if (head.first == snake[i].first && head.second == snake[i].second) {
      return true;
    }
  }
  return false;
}

int main() {
  int map_size, num_apple;
  cin >> map_size >> num_apple;
  vector<pair<int, int>> snake;  //첫번째가 헤드, 마지막이 꼬리
  vector<pair<int, int>> apple;
  queue<pair<int, char>> commands;

  for (int i = 0; i < num_apple; i++) {
    int apple_row, apple_col;
    cin >> apple_row >> apple_col;
    apple.push_back({apple_row, apple_col});
  }
  int num_commands;
  cin >> num_commands;
  for (int i = 0; i < num_commands; i++) {
    int sec;
    char clockwise;
    cin >> sec >> clockwise;
    commands.push({sec, clockwise});
  }
  snake.push_back({1, 1});  //처음에 head 위치
  //printsnake(snake);
  int time_now = 0;
  int direction_now = 1;  //처음엔 오른쪽으로 진행
  while (1) {
    time_now++;
    pair<int, int> head = snake[0];
    pair<int, int> next_head =
        make_pair(head.first + direction[direction_now].first,
                  head.second + direction[direction_now].second);
    if (next_head.first < 1 || next_head.first > map_size ||
        next_head.second < 1 || next_head.second > map_size) {
      //cout << "밖에 나감";
      break;
    }  //벽에 부딪혔음
    //꼬리를 처리함
    snake.insert(snake.begin(), next_head);

    //자기몸 부딪히는지 처리함
    //cout << time_now << " ";
    //printsnake(snake);
    if (isbody(snake)) {
      //cout << "본인이랑 부딪힘";
      break;
    }
    if (!isapple(snake[0], apple)) {
      //사과를 먹지 않음
      snake.pop_back();  //빼버린다.
    }
    if (!commands.empty()) {
      pair<int, char> next_command = commands.front();
      if (next_command.first == time_now) {
        commands.pop();
        if (next_command.second == 'D') {
          direction_now = (direction_now + 1) % 4;
          //cout << "오른쪽" << direction_now;
        } else {
          //cout << "왼쪽";
          direction_now = (direction_now + 3) % 4;
        }
      }
    }
    //time_now++;
  }
  cout << time_now;
}

/* 
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L

답 13


10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L

답 21
 */