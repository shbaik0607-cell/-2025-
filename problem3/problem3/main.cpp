#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
/**
* @brief 램프 경사각에 따른 파렛트의 정지 여부 및 가속도를 계산합니다.
*/
int main() {
	double angle_deg; // 경사각 (도)
	const double MU_S = 0.5; // 정지 마찰 계수
	const double MU_K = 0.4; // 운동 마찰 계수
	const double G = 9.8; // 중력 가속도 (m/s^2)
	printf("--- 램프 위 파렛트 가속도 계산 ---\n");
	printf("램프의 경사각 (도)을 입력하세요 (0 ~ 90): ");
	if (scanf_s("%lf", &angle_deg) != 1) {
		printf("Invalid input: 유효한 숫자를 입력해야 합니다.\n");
		return 1;
	}
	// if문을 활용한 물리적 조건 유효성 검사 및 강제 종료
	if (angle_deg < 0.0 || angle_deg > 90.0) {
		printf("Invalid input: 경사각은 0도에서 90도 사이여야 합니다.\n");
		exit(1);
	}
	// 각도 변환 (도 -> 라디안)
	double angle_rad = angle_deg * (M_PI / 180.0);
	double tan_theta = tan(angle_rad);
	printf("\n[계산 결과]\n");
	// if문을 활용한 정지/미끄러짐 판단
	if (tan_theta <= MU_S) {
		printf("파렛트는 정지상태를 유지합니다 (미끄러지지 않음).\n");
		printf("가속도: 0.00 m/s^2\n");
	}
	else {
		// 미끄러짐 발생 시 가속도 계산
		double sin_theta = sin(angle_rad);
		double cos_theta = cos(angle_rad);
		double acceleration = G * (sin_theta - MU_K * cos_theta);
		// 조건 연산자 활용 예시: 계산상 0 미만이더라도 0으로 처리 (물리적 유효성)
		acceleration = (acceleration > 0.0) ? acceleration : 0.0;
		printf("파렛트가 미끄러지기 시작합니다.\n");
		printf("경사면 아래로의 가속도: %.2lf m/s^2\n", acceleration);
	}
	return 0;
}