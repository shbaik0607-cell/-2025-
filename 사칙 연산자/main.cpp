#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// ���� �Լ�
double add(double a, double b) {
    return a + b;
}

// ���� �Լ�
double subtract(double a, double b) {
    return a - b;
}

// ���� �Լ�
double multiply(double a, double b) {
    return a * b;
}

// ������ �Լ�
double divide(double a, double b) {
    // 0���� ������ ��츦 ó��
    if (b == 0) {
        printf("����: 0���� ���� �� �����ϴ�.\n");
        return 0; // �Ǵ� Ư���� ���� ���� ��ȯ
    }
    return a / b;
}

// ������ ���� �Լ� (�������� ���ؼ��� ����)
// ������ ������ ������(int)�� �����ϹǷ�, �Է°� Ÿ���� int�� �����ϰ� ����ȯ�� ����
int modulus(int a, int b) {
    // 0���� ������ ��츦 ó��
    if (b == 0) {
        printf("����: 0���� ���� �� �����ϴ�.\n");
        return 0; // �Ǵ� Ư���� ���� ���� ��ȯ
    }
    return a % b;
}

int main() {
    double num1, num2;
    int int_num1, int_num2;

    // ����ڷκ��� �� ���� ���� �Է� �ޱ�
    printf("ù ��° ���ڸ� �Է��ϼ���: ");
    if (scanf_s("%lf", &num1) != 1) {
        printf("�߸��� �Է��Դϴ�.\n");
        return 1;
    }

    printf("�� ��° ���ڸ� �Է��ϼ���: ");
    if (scanf_s("%lf", &num2) != 1) {
        printf("�߸��� �Է��Դϴ�.\n");
        return 1;
    }

    // ��Ģ���� ��� ��� (�������� ���� double�� ���)
    printf("\n=== ��Ģ���� ��� (�Ǽ���) ===\n");
    printf("���� (%.2lf + %.2lf) = %.2lf\n", num1, num2, add(num1, num2));
    printf("���� (%.2lf - %.2lf) = %.2lf\n", num1, num2, subtract(num1, num2));
    printf("���� (%.2lf * %.2lf) = %.2lf\n", num1, num2, multiply(num1, num2));
    printf("������ (%.2lf / %.2lf) = %.2lf\n", num1, num2, divide(num1, num2));

    // ������ ������ �������� ���ؼ��� �����ϹǷ�, �Է¹��� �Ǽ��� ������ ��ȯ�Ͽ� ���
    int_num1 = (int)num1;
    int_num2 = (int)num2;

    printf("\n=== ������ ���� ��� (������ ��ȯ) ===\n");
    printf("������ ������ ���� ���ڸ� ����(%d, %d)�� ��ȯ�մϴ�.\n", int_num1, int_num2);
    printf("������ ( %d %% %d ) = %d\n", int_num1, int_num2, modulus(int_num1, int_num2));

    return 0;
}