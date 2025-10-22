#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
int get_gcd(int a, int b) 
{
    int remainder;

    
    while (b != 0) {
        remainder = a % b; // �������� ����
        a = b;             // a�� ���� b ���� ����
        b = remainder;     // b�� ������(remainder)�� ����
    }

    // b�� 0�� �Ǿ��� �� a�� �ִ����� (GCD)��
    return a;
}

// �� ���� �ּҰ���� (LCM)�� ���ϴ� �Լ�
int get_lcm(int a, int b, int gcd) {
    // �ּҰ���� = (�� ���� ��) / �ִ�����
    // �����÷ο츦 �����ϱ� ���� (a / gcd) * b ���·� ����ϴ� ���� ������.
    return (a / gcd) * b;
}

int main() {
    int num1, num2;
    int gcd_result, lcm_result;

    printf("�� ���� ���� ������ �Է��ϼ���: ");
    // ����ڷκ��� �� ���� ������ �Է¹���
    if (scanf("%d %d", &num1, &num2) != 2 || num1 <= 0 || num2 <= 0) {
        printf("�߸��� �Է��Դϴ�. ���� ���� �� ���� �Է����ּ���.\n");
        return 1; // ���� ����
    }

    // 1. �ִ����� ���
    // �Լ��� ȣ���Ͽ� GCD�� ����
    gcd_result = get_gcd(num1, num2);

    // 2. �ּҰ���� ���
    // �ִ�����(gcd_result)�� �̿��Ͽ� LCM�� ����
    lcm_result = get_lcm(num1, num2, gcd_result);

    // ��� ���
    printf("\n--- ��� ---\n");
    printf("�Է��� �� ��: %d, %d\n", num1, num2);
    printf("�ִ����� (GCD): %d\n", gcd_result);
    printf("�ּҰ���� (LCM): %d\n", lcm_result);

    return 0; // ���� ����
}