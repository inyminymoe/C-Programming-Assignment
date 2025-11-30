#include <stdio.h>
#include <stdlib.h>
/* (가) 구조체 정의
행(row)과 열(col)의 개수, 그리고 실제 데이터를 담을 이중 포인터(data)를 선언. 이중 포인터인 이유는 2차원 배열처럼 [행][열]로 접근하기 위함이다. 
*/

typedef struct {
    int row;      // 행의 수
    int col;      // 열의 수
    int **data;   // 2차원 배열 데이터를 가리킬 포인터 (동적 할당)
} Mat2d;

/* (나) 함수 구현 */

// 1. 구조체를 동적으로 생성하고 초기화하여 반환하는 함수
Mat2d* createMat(int r, int c) {
    // 1단계: Mat2d 구조체 자체를 위한 메모리 할당
    Mat2d *mat = (Mat2d*) malloc(sizeof(Mat2d));
    if (mat == NULL) return NULL; // 메모리 부족 시 NULL 반환

    mat->row = r;
    mat->col = c;

    // 2단계: 각 행의 시작 주소를 저장할 포인터 배열 할당 (행의 개수만큼)
    mat->data = (int**)malloc(sizeof(int*) * r);

    // 3단계: 각 행마다 실제로 데이터를 저장할 공간 할당 (열의 개수만큼)
    for (int i = 0; i < r; i++) {
        mat->data[i] = (int*)malloc(sizeof(int) * c);
    }

    return mat;
    
}


// 2. 특정 행/열 위치에 값을 저장하는 함수
void setValue(Mat2d *mat, int r, int c, int val) {
    // 유효한 범위인지 체크 (인덱스는 0부터 시작하므로 r은 row보다 작아야 한다)
    if ( r >= 0 && r < mat->row && c >= 0 && c < mat->col) {
        mat->data[r][c] = val;
    } else {
        printf("오류: 범위를 벗어난 인덱스입니다.\n");
    }

}

// 3. 특정 행/열 위치의 값을 반환하는 함수
int getValue(Mat2d *mat, int r, int c) {
    // 유효한 범위인지 체크 후 값 반환
    if (r >= 0 && r < mat->row && c >= 0 && c < mat->col) {
        return mat->data[r][c];
    }
    return 0; // 오류 시 0 반환
}

// 4. 동적으로 생성된 메모리를 반납하는 함수
void freeMat(Mat2d *mat) {
    if (mat == NULL) return;

    // 할당의 역순으로 해제
    // 1단계: 각 행의 데이터 공간 해제
    for (int i = 0; i < mat->row; i++) {
        free(mat->data[i]);
    }
    // 2단계: 행 포인터 배열 해제
    free(mat->data);

    // 3단계: 구조체 자체 해제
    free(mat);
}

/* (다) 메인 함수 */
int main() {
    int r, c, val;
    Mat2d *myMat = NULL;

    // 1. 행과 열 크기 입력 받기
    printf("행과 열의 크기를 입력하세요 (예: 3 4): ");
    scanf("%d %d", &r, &c);

    // 2. Mat2d 구조체 생성 (함수 호출)
    myMat = createMat(r, c);
    printf(">> %d행 %d열 크기의 행렬이 생성되었습니다.\n\n", r, c);

    // 3. 표준 입력으로 값 채워 넣기
    printf("행렬에 들어갈 값을 입력하세요:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("[%d][%d] 위치 값: ", i, j);
            scanf("%d", &val);
            setValue(myMat, i, j, val); // 함수 이용해서 값 저장
        }
    }

    // 4. 저장된 값 출력
    printf("\n[저장된 2차원 배열 출력]\n");
    for (int i = 0; i < r; i++) {
        // getValue 함수 이용해서 값 가져오기
        for (int j = 0; j < c; j++) {
            printf("%d\t", getValue(myMat, i, j));
        }
    printf("\n");
    }

    // 5. 메모리 반납
    freeMat(myMat);
    printf("\n>> 메모리 반납.\n");

    return 0;
}