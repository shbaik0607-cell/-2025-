#include <stdio.h>
#include <stdlib.h> // rand(), srand() 사용
#include <time.h> // time() 사용
#include <math.h> // sqrt() 사용
// 1. 함수: 무작위 정수 10개 생성 (1~100 범위로 가정)
void generate_random_numbers(int arr[], int size) {
	// 주석: 난수 생성을 위해 현재 시간을 시드로 사용, 프로그램 실행 시마다 다른 난수열 생성
	srand((unsigned int)time(NULL));
	printf("생성된 10개의 정수: ");
	// 주석: 반복문(for)을 사용하여 배열에 1부터 100 사이의 난수를 10개 저장
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1; // 1 ~ 100
		printf("%d ", arr[i]);
	}
	printf("\n");
}
// 2. 함수: 총합 계산 (반복문 사용)
// 주석: 반복문(for)을 사용하여 배열 요소들의 합을 계산하고 반환
long calculate_sum(int arr[], int size) {
	long sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}
// 3. 함수: 분산 계산
// 주석: 반복문(for)을 사용하여 분산 수식에 따라 (x_i - 평균)^2의 총합을 구하여 N으로 나눔
double calculate_variance(int arr[], int size, double mean) {
	double sum_of_squared_diff = 0.0;
	for (int i = 0; i < size; i++) {
		double diff = arr[i] - mean;
		sum_of_squared_diff += diff * diff;
	}
	// 주석: 선택문(if)을 사용하여 0으로 나누는 오류 방지
	if (size == 0) return 0.0;
	return sum_of_squared_diff / size;
}
// 메인 함수
int main() {
	int numbers[10]; // 10개의 정수를 저장할 배열
	int size = 10;
	// [1] 무작위 정수 생성 함수 호출
	generate_random_numbers(numbers, size);
	// [2] 총합 계산 함수 호출
	long total_sum = calculate_sum(numbers, size);
	// [3] 평균 계산
	double mean = (double)total_sum / size;
	// [4] 분산 계산 함수 호출
	double variance = calculate_variance(numbers, size, mean);
	// [5] 표준편차 계산 (math.h의 sqrt 함수 사용)
	double std_dev = sqrt(variance);
	printf("총합: %ld\n", total_sum);
	printf("평균: %.2lf\n", mean);
	printf("분산: %.2lf\n", variance);
	printf("표준편차: %.2lf\n", std_dev);
	return 0;
}