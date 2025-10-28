#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
/**
* @brief ���� ��簢�� ���� �ķ�Ʈ�� ���� ���� �� ���ӵ��� ����մϴ�.
*/
int main() {
	double angle_deg; // ��簢 (��)
	const double MU_S = 0.5; // ���� ���� ���
	const double MU_K = 0.4; // � ���� ���
	const double G = 9.8; // �߷� ���ӵ� (m/s^2)
	printf("--- ���� �� �ķ�Ʈ ���ӵ� ��� ---\n");
	printf("������ ��簢 (��)�� �Է��ϼ��� (0 ~ 90): ");
	if (scanf_s("%lf", &angle_deg) != 1) {
		printf("Invalid input: ��ȿ�� ���ڸ� �Է��ؾ� �մϴ�.\n");
		return 1;
	}
	// if���� Ȱ���� ������ ���� ��ȿ�� �˻� �� ���� ����
	if (angle_deg < 0.0 || angle_deg > 90.0) {
		printf("Invalid input: ��簢�� 0������ 90�� ���̿��� �մϴ�.\n");
		exit(1);
	}
	// ���� ��ȯ (�� -> ����)
	double angle_rad = angle_deg * (M_PI / 180.0);
	double tan_theta = tan(angle_rad);
	printf("\n[��� ���]\n");
	// if���� Ȱ���� ����/�̲����� �Ǵ�
	if (tan_theta <= MU_S) {
		printf("�ķ�Ʈ�� �������¸� �����մϴ� (�̲������� ����).\n");
		printf("���ӵ�: 0.00 m/s^2\n");
	}
	else {
		// �̲����� �߻� �� ���ӵ� ���
		double sin_theta = sin(angle_rad);
		double cos_theta = cos(angle_rad);
		double acceleration = G * (sin_theta - MU_K * cos_theta);
		// ���� ������ Ȱ�� ����: ���� 0 �̸��̴��� 0���� ó�� (������ ��ȿ��)
		acceleration = (acceleration > 0.0) ? acceleration : 0.0;
		printf("�ķ�Ʈ�� �̲������� �����մϴ�.\n");
		printf("���� �Ʒ����� ���ӵ�: %.2lf m/s^2\n", acceleration);
	}
	return 0;
}