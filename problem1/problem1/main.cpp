#include <stdio.h>
#include <stdlib.h>
/**
* @brief ������ ������������ �� �߷��� �Է¹޾� ������ ���θ� �Ǵ��ϰ� ����մϴ�.
* ���� �߷�(600kg)�� �ʰ��ϸ� "Overload", ���ϸ� "OK"�� ����մϴ�.
*/
int main() {
	double total_weight;
	const double RATED_CAPACITY = 600.0; // ���� �߷� (kg)
	printf("--- ���������� ������ �����ġ ---\n");
	printf("���� �� �߷�(kg)�� �Է��ϼ���: ");
	// �Է� ���� ���� Ȯ�� �� ��ȿ�� �˻�
	if (scanf_s("%lf", &total_weight) != 1) {
		printf("Invalid input: ��ȿ�� ���ڸ� �Է��ؾ� �մϴ�.\n");
		return 1;
	}
	// if���� Ȱ���� ������ ���� ��ȿ�� �˻� �� ���� ����
	if (total_weight < 0.0) {
		printf("Invalid input: �߷��� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	// if���� Ȱ���� �Ǵ� �� ��� ���
	printf("\n[if�� Ȱ�� ���]\n");
	if (total_weight > RATED_CAPACITY) {
		printf("Overload\n");
	}
	else {
		printf("OK\n");
	}
	// ���� ������ (?:)�� Ȱ���� ��� ���
	printf("\n[���� ������ Ȱ�� ���]\n");
	const char* result = (total_weight > RATED_CAPACITY) ? "Overload" : "OK";
	printf("%s\n", result);
	return 0;
}