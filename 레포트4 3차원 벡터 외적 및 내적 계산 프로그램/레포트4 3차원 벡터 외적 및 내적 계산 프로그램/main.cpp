#include <stdio.h>

#define DIMENSION 3 // 3차원 벡터

// 1. 함수: 벡터 입력 받기
// 주석: 포인터(배열)를 통해 두 벡터의 3개 요소를 사용자로부터 입력 받음 (반복문 사용)
void get_vector_input(double *v1, double *v2) {
    printf("첫 번째 벡터 (x y z): ");
    for (int i = 0; i < DIMENSION; i++) {
        scanf_s("%lf", v1 + i); // 포인터 연산으로 요소 접근
    }

    printf("두 번째 벡터 (x y z): ");
    for (int i = 0; i < DIMENSION; i++) {
        scanf_s("%lf", v2 + i);
    }
}

// 2. 함수: 내적 (Dot Product) 계산
// 주석: 내적 수식에 따라 반복문(for)을 사용하여 각 요소의 곱을 더함
double calculate_dot_product(const double *v1, const double *v2) {
    double result = 0.0;
    for (int i = 0; i < DIMENSION; i++) {
        result += v1[i] * v2[i]; // 배열 문법으로 포인터 접근
    }
    return result;
}

// 3. 함수: 외적 (Cross Product) 계산
// 주석: 외적 수식에 따라 계산하며, 결과를 포인터로 전달된 result_v 배열에 저장
void calculate_cross_product(const double *v1, const double *v2, double *result_v) {
    // A_y * B_z - A_z * B_y
    result_v[0] = v1[1] * v2[2] - v1[2] * v2[1]; 
    // A_z * B_x - A_x * B_z
    result_v[1] = v1[2] * v2[0] - v1[0] * v2[2];
    // A_x * B_y - A_y * B_x
    result_v[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

// 메인 함수
int main() {
    double vector1[DIMENSION]; // 벡터 A
    double vector2[DIMENSION]; // 벡터 B
    double cross_product_result[DIMENSION]; // A x B 결과 벡터
    double dot_product_result; // A . B 결과 스칼라

    // [1] 벡터 입력 함수 호출
    get_vector_input(vector1, vector2);

    // [2] 내적 계산 함수 호출
    dot_product_result = calculate_dot_product(vector1, vector2);

    // [3] 외적 계산 함수 호출
    calculate_cross_product(vector1, vector2, cross_product_result);

    printf("\n=== 계산 결과 ===\n");
    printf("벡터 A = (%.2lf, %.2lf, %.2lf)\n", vector1[0], vector1[1], vector1[2]);
    printf("벡터 B = (%.2lf, %.2lf, %.2lf)\n", vector2[0], vector2[1], vector2[2]);
    printf("내적 (A . B): %.2lf\n", dot_product_result);
    printf("외적 (A x B): (%.2lf, %.2lf, %.2lf)\n", 
           cross_product_result[0], cross_product_result[1], cross_product_result[2]);
    
    // 주석: 공학용 계산기 결과와 비교하여 동일한지 확인 필요
    
    return 0;
}