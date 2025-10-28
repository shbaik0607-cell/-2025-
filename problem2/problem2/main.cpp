#include <stdio.h>
#include <stdlib.h>
/**
* @brief ��� ������� �µ�, �� ����, �ð� ������ �Է¹޾� ���� ��� ����մϴ�.
*/
int main() {
	double temp; // ���� �µ� (��C)
	int door_status; // �� ���� (0: ����, 1: ����)
	int time_abnormal; // ������ ���� ���� �ð� (��)
	const double TEMP_MIN = 2.0;
	const double TEMP_MAX = 8.0;
	printf("--- ��� ����� �µ� ���� �����ġ ---\n");
	printf("���� �µ� (��C), �� ���� (0/1), ������ ���� �ð� (��)�� �Է��ϼ��� (��: 4.5 0 10)");
		if (scanf_s("%lf %d %d", &temp, &door_status, &time_abnormal) != 3) {
			printf("Invalid input: ��� ���� ��Ȯ�� �Է��ؾ� �մϴ�.\n");
			return 1;
		}
	// if���� Ȱ���� ������ ���� ��ȿ�� �˻� �� ���� ����
	if (door_status != 0 && door_status != 1) {
		printf("Invalid input: �� ���´� 0(����) �Ǵ� 1(����)�� �����մϴ�.\n");
		exit(1);
	}
	if (time_abnormal < 0) {
		printf("Invalid input: �ð��� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	const char* status;
	// �µ��� ������ ������� Ȯ��
	int is_temp_out = (temp < TEMP_MIN || temp > TEMP_MAX);
	// if-else if-else ������ Ȱ���� ���� �Ǵ�
	if (door_status == 0) { // ���� ���� ���� (���� ��� ����)
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
	else { // ���� ���� ����
		if (time_abnormal >= 60 && is_temp_out) {
			status = "Critical";
		}
		else {
			status = "Normal";
		}
	}
	printf("\n[if�� Ȱ�� ���] ����� ����: %s\n", status);
	// ���� ������ (?:) Ȱ�� ����
	const char* door_str = (door_status == 0) ? "����" : "����";
	printf("[���� ������ Ȱ��] �� ����: %s\n", door_str);
	return 0;
}