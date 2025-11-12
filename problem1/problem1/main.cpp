#include <stdio.h>
#include <stdlib.h>
/**
* @brief 공사장 엘리베이터의 총 중량을 입력받아 과부하 여부를 판단하고 출력합니다.
* 정격 중량(600kg)을 초과하면 "Overload", 이하면 "OK"를 출력합니다.
*/
int main() {
	double total_weight;
	const double RATED_CAPACITY = 600.0; // 정격 중량 (kg)
	printf("--- 엘리베이터 과부하 경고장치 ---\n");
	printf("현재 총 중량(kg)을 입력하세요: ");
	// 입력 성공 여부 확인 및 유효성 검사
	if (scanf_s("%lf", &total_weight) != 1) {
		printf("Invalid input: 유효한 숫자를 입력해야 합니다.\n");
		return 1;
	}
	// if문을 활용한 물리적 조건 유효성 검사 및 강제 종료
	if (total_weight < 0.0) {
		printf("Invalid input: 중량은 음수가 될 수 없습니다.\n");
		exit(1);
	}
	// if문을 활용한 판단 및 결과 출력
	printf("\n[if문 활용 결과]\n");
	if (total_weight > RATED_CAPACITY) {
		printf("Overload\n");
	}
	else {
		printf("OK\n");
	}
	// 조건 연산자 (?:)를 활용한 결과 출력
	printf("\n[조건 연산자 활용 결과]\n");
	const char* result = (total_weight > RATED_CAPACITY) ? "Overload" : "OK";
	printf("%s\n", result);
	return 0;
}