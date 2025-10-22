#include <stdio.h>

int main() {
	int a = 369;
	double b = 314.1592;

	printf("***%05d***\n", a);
	printf("***%+5d***\n", a);
	printf("***%-5d***\n", a);
	printf("***%6.1f***\n", a);
	printf("***%10.2e***\n", a);

	return 0;
}