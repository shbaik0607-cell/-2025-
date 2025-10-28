#include <stdio.h>
#include <stdlib.h>
/**
* @brief ��� �� ���ӿ� ���� ���� ����(����/õ��/����)�� �Ǻ��ϰ� ������ ����մϴ�.
*/
int main() {
	double velocity; // ���� V (m/s)
	// ����ġ �� ��� ���� (���)
	const double D = 0.05; // ��� ���� (m)
	const double RHO = 998.2; // �е� �� (kg/m^3)
	const double MU = 0.001002; // ���� �� (Pa��s)
	printf("--- �ð��� ��� ���� ���� �� ���� ��� ---\n");
	printf("��� �� ��ü�� ���� V (m/s)�� �Է��ϼ���: ");
	if (scanf_s("%lf", &velocity) != 1) {
		printf("Invalid input: ��ȿ�� ���ڸ� �Է��ؾ� �մϴ�.\n");
		return 1;
	}
	// if���� Ȱ���� ������ ���� ��ȿ�� �˻� �� ���� ����
	if (velocity < 0.0) {
		printf("Invalid input: ������ ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	// ���̳��� �� (Re) ���
	double reynolds_number = (RHO * velocity * D) / MU;
	// if-else if-else ������ Ȱ���� ���� ���� �Ǻ�
	const char* flow_state;
	if (reynolds_number < 2300.0) {
		flow_state = "���� (Laminar)";
	}
	else if (reynolds_number <= 4000.0) {
		flow_state = "õ�� (Transition)";
	}
	else { // reynolds_number > 4000.0
		flow_state = "���� (Turbulent)";
	}
	// ���� (q) ���
	double dynamic_pressure = 0.5 * RHO * velocity * velocity;
	// ���� ������ (?:) Ȱ�� ���� (���� 0�� �� ���� 0)
	dynamic_pressure = (velocity == 0.0) ? 0.0 : dynamic_pressure;
	printf("\n[��� ���]\n");
	printf("1. ���� ���� (���̳��� �� Re: %.2lf)\n", reynolds_number);
	printf(" -> %s\n", flow_state);
	printf("2. ��� �� ��ü�� ���� q: %.2lf Pa\n", dynamic_pressure);
	return 0;
}