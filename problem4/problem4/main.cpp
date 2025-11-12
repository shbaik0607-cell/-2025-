#include <stdio.h>
#include <stdlib.h>
/**
* @brief 배관 내 유속에 따른 유동 상태(층류/천이/난류)를 판별하고 동압을 계산합니다.
*/
int main() {
	double velocity; // 유속 V (m/s)
	// 물성치 및 배관 정보 (상수)
	const double D = 0.05; // 배관 내경 (m)
	const double RHO = 998.2; // 밀도 ρ (kg/m^3)
	const double MU = 0.001002; // 점도 μ (Pa·s)
	printf("--- 냉각수 배관 유동 상태 및 동압 계산 ---\n");
	printf("배관 내 유체의 유속 V (m/s)를 입력하세요: ");
	if (scanf_s("%lf", &velocity) != 1) {
		printf("Invalid input: 유효한 숫자를 입력해야 합니다.\n");
		return 1;
	}
	// if문을 활용한 물리적 조건 유효성 검사 및 강제 종료
	if (velocity < 0.0) {
		printf("Invalid input: 유속은 음수가 될 수 없습니다.\n");
		exit(1);
	}
	// 레이놀즈 수 (Re) 계산
	double reynolds_number = (RHO * velocity * D) / MU;
	// if-else if-else 구조를 활용한 유동 상태 판별
	const char* flow_state;
	if (reynolds_number < 2300.0) {
		flow_state = "층류 (Laminar)";
	}
	else if (reynolds_number <= 4000.0) {
		flow_state = "천이 (Transition)";
	}
	else { // reynolds_number > 4000.0
		flow_state = "난류 (Turbulent)";
	}
	// 동압 (q) 계산
	double dynamic_pressure = 0.5 * RHO * velocity * velocity;
	// 조건 연산자 (?:) 활용 예시 (유속 0일 때 동압 0)
	dynamic_pressure = (velocity == 0.0) ? 0.0 : dynamic_pressure;
	printf("\n[계산 결과]\n");
	printf("1. 유동 상태 (레이놀즈 수 Re: %.2lf)\n", reynolds_number);
	printf(" -> %s\n", flow_state);
	printf("2. 배관 내 유체의 동압 q: %.2lf Pa\n", dynamic_pressure);
	return 0;
}