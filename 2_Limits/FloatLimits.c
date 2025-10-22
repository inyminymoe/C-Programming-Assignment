#include <stdio.h>
#include <float.h>

int main() {
	float minFlt = FLT_MIN; // ㄱ.가장 작은 양수값
	float maxFlt = FLT_MAX; // ㄴ.
	printf("float의 크기: %zu\n", sizeof(float)); // ㄷ.
	printf("float 자료형 범위: %e ~ %e\n", minFlt, maxFlt);
	return 0;
}