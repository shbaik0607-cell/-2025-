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
               
                if (*(arr + j) > *(arr + j + 1)) {
                    should_swap = 1;
                }
            }
            else if (order == DESCENDING) {
                
                if (*(arr + j) < *(arr + j + 1)) {
                    should_swap = 1;
                }
            }

            if (should_swap) {
                
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
       
        *(arr + i) = MIN_VAL + ((double)rand() / RAND_MAX) * range;
    }
}



int main(void) {
    
    srand((unsigned int)time(NULL));

    
    double data[ARRAY_SIZE];

   
    GenerateRandomArray(data, ARRAY_SIZE);

   
    PrintArray(data, ARRAY_SIZE, "랜덤 생성된 배열 (정렬 전)");

    
    CalcSortArray(data, ARRAY_SIZE, ASCENDING);
    PrintArray(data, ARRAY_SIZE, "오름차순 정렬 후");

    
    CalcSortArray(data, ARRAY_SIZE, DESCENDING);
    PrintArray(data, ARRAY_SIZE, "내림차순 정렬 후");

    return 0;
}