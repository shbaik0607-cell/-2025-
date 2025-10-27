#include <stdio.h>

int main() {
    int i, j;
    int size = 5; // 격자의 크기 (0부터 4까지 총 5줄)

    // 바깥쪽 반복문: 행(i)을 제어 (0부터 size-1까지)
    for (i = 0; i < size; i++) {
        // 안쪽 반복문: 열(j)을 제어 (0부터 size-1까지)
        for (j = 0; j < size; j++) {
            // 대각선 조건을 확인
            // 조건 1: i와 j의 값이 같은 경우 (i == j)
            // 조건 2: i와 j의 합이 size-1인 경우 (i + j == size - 1)
            if (i == j || i + j == size - 1) {
                printf("*"); // 조건에 맞으면 아스터리스크 출력
            }
            else {
                printf(" "); // 조건에 맞지 않으면 공백 출력
            }
        }
        printf("\n"); // 한 행의 출력이 끝나면 줄바꿈
    }

    return 0;
}