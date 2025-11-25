#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 100
#define RANGE_MAX 100 // 정수의 범위: 1 ~ 100

// 1. 함수: 무작위 정수 생성 및 배열 채우기
// 주석: 배열의 크기만큼 1~100 사이의 난수를 생성하여 채웁니다.
void generate_random_numbers(int arr[], int size) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE_MAX + 1; // 1 ~ 100
    }
}

// 2. 함수: 특정 범위의 통계 계산 (총합, 분산, 표준편차)
// 주석: 배열, 시작 인덱스, 종료 인덱스를 받아 해당 범위의 통계를 계산
void calculate_statistics(const int* arr, int start_idx, int end_idx) {
    long sum = 0;
    double mean = 0.0;
    double variance = 0.0;
    double std_dev = 0.0;

    // 주석: 유효성 검사 (선택문 사용)
    if (start_idx < 0 || end_idx >= ARRAY_SIZE || start_idx > end_idx) {
        printf(" 오류: 유효하지 않은 범위입니다 (0~99).\n");
        return;
    }

    int count = end_idx - start_idx + 1;

    // [Step 1] 총합 계산 (반복문 사용)
    // 주석: 포인터 연산을 사용하여 배열 요소에 접근하며 총합 계산
    for (int i = start_idx; i <= end_idx; i++) {
        sum += *(arr + i); // arr[i]와 동일한 포인터 문법
    }

    // [Step 2] 평균 계산
    mean = (double)sum / count;

    // [Step 3] 분산 계산 (반복문 사용)
    double sum_of_squared_diff = 0.0;
    for (int i = start_idx; i <= end_idx; i++) {
        double diff = *(arr + i) - mean;
        sum_of_squared_diff += diff * diff;
    }
    variance = sum_of_squared_diff / count;

    // [Step 4] 표준편차 계산
    std_dev = sqrt(variance);

    printf("\n=== 통계 결과 ===\n");
    printf("추출된 개수 (N): %d\n", count);
    printf("총합: %ld\n", sum);
    printf("평균: %.2lf\n", mean);
    printf("분산: %.2lf\n", variance);
    printf("표준편차: %.2lf\n", std_dev);
}

// 메인 함수
int main() {
    int numbers[ARRAY_SIZE];
    int start_index, end_index;

    // [1] 난수 생성 함수 호출
    generate_random_numbers(numbers, ARRAY_SIZE);

    printf("100개의 정수가 생성되었습니다 (인덱스 0~99).\n");
    printf("시작 인덱스 (0~99): ");
    scanf_s("%d", &start_index);
    printf("종료 인덱스 (0~99): ");
    scanf_s("%d", &end_index);

    // [2] 통계 계산 함수 호출
    calculate_statistics(numbers, start_index, end_index);

    return 0;
}