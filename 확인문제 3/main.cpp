#include <stdio.h>

// 함수 선언
double centi_to_meter(int cm);

int main(void)
{
    // 함수의 반환값을 저장할 변수
    double res;

    // 함수 호출, 반환값을 res에 저장
    res = centi_to_meter(187);

    // 반환된 res의 값 출력
    printf("%.2lfm\n", res);

    return 0;
}

// 함수 정의의 시작
double centi_to_meter(int cm)
{
    // 필요한 변수 선언
    double result;

    // 매개변수 cm의 값을 m단위로 환산
    result = (double)cm / 100.0;

    // 환산된 값 반환
    return result;
}