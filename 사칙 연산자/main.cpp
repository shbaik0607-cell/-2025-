#include <stdio.h>

// 1���� n������ ���� ����ϴ� ��� �Լ�
int sum_recursive(int n) {
    // 1. **���� ���� (Base Case):**
    // n�� 1�̸� (�� �̻� ���� ���� ������) 1�� ��ȯ�մϴ�.
    if (n == 1) {
        return 1;
    }

    // 2. **��� ȣ�� (Recursive Step):**
    // n + (1���� n-1������ ��)�� ��ȯ�մϴ�.
    // 'sum_recursive(n - 1)'�� �ڱ� �ڽ��� �ٽ� ȣ���մϴ�.
    return n + sum_recursive(n - 1);
}

int main() {
    int target = 10;

    // ��� �Լ� ȣ��
    int result = sum_recursive(target);

    // ��� ���
    printf("1���� %d������ ����: %d\n", target, result);

    return 0;
}