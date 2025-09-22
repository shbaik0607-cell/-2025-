#include <stdio.h>

int main() {
    // 1. char 1��, const char* 1�� �̻� ���
    char char_example = 'A'; // char ����
    const char* message_part1 = "First line"; // const char* ���ڿ�
    const char* message_part2 = "Indented second line";
    const char* message_part3 = "Third line";
    const char* double_quote_text = "double quotes"; // ū����ǥ ���� ���ڿ�
    const char* single_quote_text = "single quotes"; // ��������ǥ ���� ���ڿ�

    // �Ǽ� ��+���е� ���ø� ���� ����
    float average_value = 87.35f; // float ����

    printf("=== Char/String & Escapes ===\n"); // ����
    printf("Char : %c, code: %d\n", char_example, char_example); // char ���� �ƽ�Ű �ڵ� ���

    printf("Message:\n"); // Message: ��� �� �� �ٲ�

    printf("%s\n", message_part1); // First line
    printf("\t%s\n", message_part2); // \t�� ����Ͽ� �鿩����� Indented second line
    printf("%s\n", message_part3); // Third line

    // Quotes: "double quotes" and 'single quotes' ���
    // \" : ū����ǥ ���, \' : ��������ǥ ���
    printf("Quotes: \"%s\" and \'%s\'\n", double_quote_text, single_quote_text);

    // Backslash: \ ���
    printf("Backslash: \\\n"); // \\ : �������� ��ü�� ���

    // Average: [  87.35] ��� (8ĭ Ȯ��, �Ҽ��� 2�ڸ� ���е�, ������ ����)
    printf("Average: [%8.2f]\n", average_value);

    return 0;
}