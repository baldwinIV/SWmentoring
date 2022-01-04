//https://www.acmicpc.net/problem/1003
//피보나치

#include <iostream>
#include <vector>
using namespace std;
vector<int> mem_zero(42, -1);
vector<int> mem_one(42, -1);
vector<int> mem_fibo(42, -1);
int fibonacci(int n) {
  int n_toret_1;
  int n_toret_2;
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    if (mem_fibo[n - 1] != -1) {
      n_toret_1 = mem_fibo[n - 1];
    } else {
      mem_fibo[n - 1] = fibonacci(n - 1);
      n_toret_1 = mem_fibo[n - 1];
    }
    if (mem_fibo[n - 2] != -1) {
      n_toret_2 = mem_fibo[n - 2];
    } else {
      mem_fibo[n - 2] = fibonacci(n - 2);
      n_toret_2 = mem_fibo[n - 2];
    }
    mem_zero[n] = mem_zero[n - 1] + mem_zero[n - 2];
    mem_one[n] = mem_one[n - 1] + mem_one[n - 2];
    return n_toret_1 + n_toret_2;
  }
}
vector<int> input;
int main() {
  int tc_num;
  cin >> tc_num;
  for (int i = 0; i < tc_num; i++) {
    int tocalcul;
    cin >> tocalcul;
    input.push_back(tocalcul);
  }
  mem_zero[0] = 1;
  mem_one[0] = 0;
  mem_fibo[0] = 0;
  mem_zero[1] = 0;
  mem_one[1] = 1;
  mem_fibo[1] = 1;
  for (int i = 0; i < tc_num; i++) {
    fibonacci(input[i]);
    cout << mem_zero[input[i]] << " " << mem_one[input[i]] << endl;
  }
}