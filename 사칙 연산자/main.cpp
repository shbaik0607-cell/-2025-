#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// 덧셈 함수
double add(double a, double b) {
    return a + b;
}

// 뺄셈 함수
double subtract(double a, double b) {
    return a - b;
}

// 곱셈 함수
double multiply(double a, double b) {
    return a * b;
}

// 나눗셈 함수
double divide(double a, double b) {
    // 0으로 나누는 경우를 처리
    if (b == 0) {
        printf("오류: 0으로 나눌 수 없습니다.\n");
        return 0; // 또는 특정한 오류 값을 반환
    }
    return a / b;
}

// 나머지 연산 함수 (정수형에 대해서만 가능)
// 나머지 연산은 정수형(int)만 지원하므로, 입력값 타입을 int로 변경하고 형변환에 유의
int modulus(int a, int b) {
    // 0으로 나누는 경우를 처리
    if (b == 0) {
        printf("오류: 0으로 나눌 수 없습니다.\n");
        return 0; // 또는 특정한 오류 값을 반환
    }
    return a % b;
}

int main() {
    double num1, num2;
    int int_num1, int_num2;

    // 사용자로부터 두 개의 숫자 입력 받기
    printf("첫 번째 숫자를 입력하세요: ");
    if (scanf_s("%lf", &num1) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    printf("두 번째 숫자를 입력하세요: ");
    if (scanf_s("%lf", &num2) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    // 사칙연산 결과 출력 (나눗셈을 위해 double형 사용)
    printf("\n=== 사칙연산 결과 (실수형) ===\n");
    printf("덧셈 (%.2lf + %.2lf) = %.2lf\n", num1, num2, add(num1, num2));
    printf("뺄셈 (%.2lf - %.2lf) = %.2lf\n", num1, num2, subtract(num1, num2));
    printf("곱셈 (%.2lf * %.2lf) = %.2lf\n", num1, num2, multiply(num1, num2));
    printf("나눗셈 (%.2lf / %.2lf) = %.2lf\n", num1, num2, divide(num1, num2));

    // 나머지 연산은 정수형에 대해서만 가능하므로, 입력받은 실수를 정수로 변환하여 사용
    int_num1 = (int)num1;
    int_num2 = (int)num2;

    printf("\n=== 나머지 연산 결과 (정수형 변환) ===\n");
    printf("나머지 연산을 위해 숫자를 정수(%d, %d)로 변환합니다.\n", int_num1, int_num2);
    printf("나머지 ( %d %% %d ) = %d\n", int_num1, int_num2, modulus(int_num1, int_num2));

    return 0;
}