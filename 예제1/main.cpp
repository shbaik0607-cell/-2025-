#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable: 4996) // Disable deprecation warning for fopen, etc.
#include <stdio.h>

int main(void) {

	char name[50] = "�����";
	int studentid = 2024010666;
	double height = 170;
	double weight = 68.2;// 1: ���� ����(�̸� �й� Ű ������)
	double bmi = weight * height;

	scanf("%s %d %lf %lf", name, &studentid, &height, &weight);// 2. scanf �Ǵ� scanf_s�� �� ������ �� �ٷ� �Է� �ޱ�
	printf("bmi: %.2f\n", bmi);// 3. bmi ��ġ ���
	// 4-1. ��� ���(�̸�, �й�, Ű, ������)
	// 4-2. bmi ��ġ�� ���� ��� ���

	return 0;
}