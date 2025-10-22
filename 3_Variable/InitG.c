#include <stdio.h>

int x = 0;
int f() {
	x = x+1;
	return x;
}

int main() {
	printf("%d\n", f());
	printf("%d\n", f());
	printf("%d\n", f());
	printf("x는 전역변수로 함수 f 바깥에 선언되서, f()를 호출할 때마다 같은 x를 증가시켜서 1, 2, 3이 출력")
}