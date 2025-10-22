#include <stdio.h>

int f() {
	int x = 0;
	x = x+1;
	return x;
}

int main() {
	printf("%d\n", f());
	printf("%d\n", f());
	printf("%d\n", f());
	printf("x는 f함수 안에 존재하는 지역변수로 함수를 호출 할 때마다 새로 x=0으로 초기화되므로 1씩 증가해서 항상 1만 리턴")
}