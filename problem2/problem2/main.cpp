#include <stdio.h>
#include <stdlib.h>
/**
* @brief 백신 냉장고의 온도, 문 상태, 시간 정보를 입력받아 상태 경고를 출력합니다.
*/
int main() {
	double temp; // 현재 온도 (°C)
	int door_status; // 문 상태 (0: 닫힘, 1: 열림)
	int time_abnormal; // 비정상 상태 유지 시간 (초)
	const double TEMP_MIN = 2.0;
	const double TEMP_MAX = 8.0;
	printf("--- 백신 냉장고 온도 상태 경고장치 ---\n");
	printf("현재 온도 (°C), 문 상태 (0/1), 비정상 유지 시간 (초)를 입력하세요 (예: 4.5 0 10)");
		if (scanf_s("%lf %d %d", &temp, &door_status, &time_abnormal) != 3) {
			printf("Invalid input: 모든 값을 정확히 입력해야 합니다.\n");
			return 1;
		}
	// if문을 활용한 물리적 조건 유효성 검사 및 강제 종료
	if (door_status != 0 && door_status != 1) {
		printf("Invalid input: 문 상태는 0(닫힘) 또는 1(열림)만 가능합니다.\n");
		exit(1);
	}
	if (time_abnormal < 0) {
		printf("Invalid input: 시간은 음수가 될 수 없습니다.\n");
		exit(1);
	}
	const char* status;
	// 온도가 범위를 벗어났는지 확인
	int is_temp_out = (temp < TEMP_MIN || temp > TEMP_MAX);
	// if-else if-else 구조를 활용한 상태 판단
	if (door_status == 0) { // 문이 닫힌 상태 (내부 기계 고장)
		if (!is_temp_out) {
			status = "Normal";
		}
		else if (time_abnormal <= 30) {
			status = "Warning";
		}
		else { // time_abnormal > 30
			status = "Critical";
		}
		
	}
	else { // 문이 열린 상태
		if (time_abnormal >= 60 && is_temp_out) {
			status = "Critical";
		}
		else {
			status = "Normal";
		}
	}
	printf("\n[if문 활용 결과] 냉장고 상태: %s\n", status);
	// 조건 연산자 (?:) 활용 예시
	const char* door_str = (door_status == 0) ? "닫힘" : "열림";
	printf("[조건 연산자 활용] 문 상태: %s\n", door_str);
	return 0;
}