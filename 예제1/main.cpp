#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable: 4996) // Disable deprecation warning for fopen, etc.
#include <stdio.h>

int main(void) {

	char name[50] = "백승한";
	int studentid = 2024010666;
	double height = 170;
	double weight = 68.2;// 1: 변수 선언(이름 학번 키 몸무게)
	double bmi = weight * height;

	scanf("%s %d %lf %lf", name, &studentid, &height, &weight);// 2. scanf 또는 scanf_s로 위 정보를 한 줄로 입력 받기
	printf("bmi: %.2f\n", bmi);// 3. bmi 수치 계산
	// 4-1. 결과 출력(이름, 학번, 키, 몸무게)
	// 4-2. bmi 수치에 따른 결과 출력

	return 0;
}