#include <stdio.h>

// �Լ� ����
double centi_to_meter(int cm);

int main(void)
{
    // �Լ��� ��ȯ���� ������ ����
    double res;

    // �Լ� ȣ��, ��ȯ���� res�� ����
    res = centi_to_meter(187);

    // ��ȯ�� res�� �� ���
    printf("%.2lfm\n", res);

    return 0;
}

// �Լ� ������ ����
double centi_to_meter(int cm)
{
    // �ʿ��� ���� ����
    double result;

    // �Ű����� cm�� ���� m������ ȯ��
    result = (double)cm / 100.0;

    // ȯ��� �� ��ȯ
    return result;
}