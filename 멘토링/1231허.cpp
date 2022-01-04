#include <stdio.h>

void swap_addr(int* addr_num1, int* addr_num2) {
  int tmp = *addr_num1;
  *addr_num1 = *addr_num2;
  *addr_num2 = tmp;
  //num1의 주소에 저장되어있는 int가 원래 20에서 30으로 바뀜
  return;
}
void swap(int num1, int num2) {
  int tmp = num1;
  num1 = num2;
  num2 = tmp;
  //num1의 주소에 저장되어있는 int가 원래 20에서 30으로 바뀜
  return;
}
void print_add(int a, int b) {
  //a + b의 합을 출력 .
}

int main() {
  int* numPtr;

  int num1 = 20;
  int num2 = 10;

  //num1이랑 num2의 값을 서로 바꾸는 함수를 만들고 싶음
  swap_addr(&num1, &num2);
  printf("%d %d\n", num1, num2);
  swap(num1, num2);
  printf("%d %d", num1, num2);
  //전달할때 num1의 '값'을 전달함.
  //num1과 num2의 주소에 저장되어있는 값을 바꾼게 아니라
  //저장되어있는 값을 복사해서 새로운 함수에 전달했음.
  //그래서 포인터를 배운거임. 만약 주소값을 넘겨준다면?
  //바꿀수 있지 않을까?
  // 1번쨰, 주소값을 넘겨주자! 0
  // 이렇게 함수로 주소를 전달해서 직접 값을 조작하기 위해 포인터를 배운 것.
  return 0;
}

//numPtr의 값은 쓰레기값이 들어있을거에요
// 쓰레기값이 접근해서는 안될 주소였던거임..
// 선언만하고 쓰려면 보통 에러남.
/* 
    int a = 10;
    int* address_of_a = &a; ( &(변수) 는 변수의 주소값을 반환함)
    *은 11번째줄처럼 선언할때 쓰면 선언하는 변수가 포인터변수임을 표시
    *을 사용하게 되면  *(주소)의 형태로 주소로 찾아가서 주소가 저장한 값을 반환
    
    11번 줄을 보면 &연산자 뒤에 변수a를 붙여 address_of_a에 a의 주소를 저장함.
    address_of_a는 int*의 자료형을 갖고 있으며, int변수의 주소를 저장하겠다는 뜻
    
     */
