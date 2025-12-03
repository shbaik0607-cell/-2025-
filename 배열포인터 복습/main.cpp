#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 10
#define MIN_VAL -100.0
#define MAX_VAL 100.0


typedef enum {
    ASCENDING,  
    DESCENDING  
} SortOrder;


void CalcSortArray(double* arr, int size, SortOrder order) {
    
    int i, j;
    double temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            

            int should_swap = 0;

            if (order == ASCENDING) {
                // 오름차순: 앞의 값이 뒤의 값보다 크면(잘못된 순서) 교환
                if (*(arr + j) > *(arr + j + 1)) {
                    should_swap = 1;
                }
            }
            else if (order == DESCENDING) {
                // 내림차순: 앞의 값이 뒤의 값보다 작으면(잘못된 순서) 교환
                if (*(arr + j) < *(arr + j + 1)) {
                    should_swap = 1;
                }
            }

            if (should_swap) {
                // 값 교환 (스와핑)
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}



void PrintArray(const double* arr, int size, const char* title) {
    printf("--- %s ---\n", title);
    printf("[");
    for (int i = 0; i < size; i++) {
        // 배열 접근: arr[i] 또는 *(arr + i)
        printf(" %.1lf", *(arr + i));
        if (i < size - 1) {
            printf(",");
        }
    }
    printf(" ]\n");
}



void GenerateRandomArray(double* arr, int size) {
    double range = MAX_VAL - MIN_VAL;
    for (int i = 0; i < size; i++) {
        // 난수 생성 공식: MIN_VAL + (rand() / (double)RAND_MAX) * range
        *(arr + i) = MIN_VAL + ((double)rand() / RAND_MAX) * range;
    }
}



int main(void) {
    // 난수 시드 초기화 (현재 시간을 기반으로)
    srand((unsigned int)time(NULL));

    // 배열 선언
    double data[ARRAY_SIZE];

    // 1. 랜덤 생성
    GenerateRandomArray(data, ARRAY_SIZE);

    // 2. 랜덤 생성된 배열 출력
    // 배열 이름 'data' 자체가 배열의 첫 번째 요소의 주소(포인터)이므로 그대로 전달
    PrintArray(data, ARRAY_SIZE, "랜덤 생성된 배열 (정렬 전)");

    // 3. 오름차순 정렬 및 출력
    CalcSortArray(data, ARRAY_SIZE, ASCENDING);
    PrintArray(data, ARRAY_SIZE, "오름차순 정렬 후");

    // 4. 내림차순 정렬 및 출력 (재정렬을 위해 배열을 다시 랜덤 생성해야 깔끔하지만, 여기서는 정렬된 배열을 다시 내림차순 정렬)
    // CalcSortArray는 현재 data 배열의 상태를 기반으로 정렬을 수행
    CalcSortArray(data, ARRAY_SIZE, DESCENDING);
    PrintArray(data, ARRAY_SIZE, "내림차순 정렬 후");

    return 0;
}