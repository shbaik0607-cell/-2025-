#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
int get_gcd(int a, int b) 
{
    int remainder;

    
    while (b != 0) {
        remainder = a % b; // 나머지를 구함
        a = b;             // a에 이전 b 값을 대입
        b = remainder;     // b에 나머지(remainder)를 대입
    }

    // b가 0이 되었을 때 a가 최대공약수 (GCD)임
    return a;
}

// 두 수의 최소공배수 (LCM)를 구하는 함수
int get_lcm(int a, int b, int gcd) {
    // 최소공배수 = (두 수의 곱) / 최대공약수
    // 오버플로우를 방지하기 위해 (a / gcd) * b 형태로 계산하는 것이 안전함.
    return (a / gcd) * b;
}

int main() {
    int num1, num2;
    int gcd_result, lcm_result;

    printf("두 개의 양의 정수를 입력하세요: ");
    // 사용자로부터 두 개의 정수를 입력받음
    if (scanf("%d %d", &num1, &num2) != 2 || num1 <= 0 || num2 <= 0) {
        printf("잘못된 입력입니다. 양의 정수 두 개를 입력해주세요.\n");
        return 1; // 오류 종료
    }

    // 1. 최대공약수 계산
    // 함수를 호출하여 GCD를 구함
    gcd_result = get_gcd(num1, num2);

    // 2. 최소공배수 계산
    // 최대공약수(gcd_result)를 이용하여 LCM을 구함
    lcm_result = get_lcm(num1, num2, gcd_result);

    // 결과 출력
    printf("\n--- 결과 ---\n");
    printf("입력한 두 수: %d, %d\n", num1, num2);
    printf("최대공약수 (GCD): %d\n", gcd_result);
    printf("최소공배수 (LCM): %d\n", lcm_result);

    return 0; // 정상 종료
}