#include <stdio.h>
#include <limits.h>

int main() {
	short int minShrt = SHRT_MIN; // ㄱ.문항
	short int maxShrt = SHRT_MAX; // ㄴ.문항
	printf("short int 크기: %zu\n", sizeof(short int)); // ㄷ.문항
	printf("short int 자료형 범위: %d ~ %d\n", minShrt, maxShrt);
	return 0;
}