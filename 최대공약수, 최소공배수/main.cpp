#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int get_gcd(int a, int b) 
{
    int remainder;
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    
    return a;
}


int get_lcm(int a, int b, int gcd) {
    return (a / gcd) * b;
}


int main() 
{
    int num1, num2;
    int gcd_result, lcm_result;

    printf("두 개의 양의 정수를 입력하세요: ");
    if (scanf("%d %d", &num1, &num2) != 2 || num1 <= 0 || num2 <= 0) 
    {
        printf("잘못된 입력입니다. 양의 정수 두 개를 입력해주세요.\n");
        return 1;
    }
    gcd_result = get_gcd(num1, num2);

    
    
    lcm_result = get_lcm(num1, num2, gcd_result);

   
    printf("\n--- 결과 ---\n");
    printf("입력한 두 수: %d, %d\n", num1, num2);
    printf("최대공약수 (GCD): %d\n", gcd_result);
    printf("최소공배수 (LCM): %d\n", lcm_result);

    return 0; // 정상 종료
}