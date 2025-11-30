#include <stdio.h>
#include <string.h>

int main() {
    // 1. strlen() 함수
    char str1[] = "Hello C World";
    size_t len = strlen(str1);
    printf("[strlen] '%s'의 길이는 %zu입니다.\n", str1, len);

    // 2. strncpy 함수
    char src[] = "CopyThisString";
    char dest[10];
    // 자동으로 NULL 이 붙지 않으니 직접 붙여야 안전하다.
    strncpy(dest, src, 5);
    dest[5] = '\0';
    printf("[strncpy] 5글자 복사 결과: %s\n", dest);

    // 3. memcpy 함수
    int nums_src[] = {10, 20, 30};
    int nums_dest[3]; 
    // int형 배열(3개 * 4바이트 = 12바이트) 통째로 복사
    memcpy(nums_dest, nums_src, sizeof(nums_src));
    printf("[memcpy] 정수 배열 복사 결과: %d %d %d\n", 
               nums_dest[0], nums_dest[1], nums_dest[2]);

    return 0;
}