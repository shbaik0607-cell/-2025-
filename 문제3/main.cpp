#include <stdio.h>

int main() {
    // 1. char 1개, const char* 1개 이상 사용
    char char_example = 'A'; // char 변수
    const char* message_part1 = "First line"; // const char* 문자열
    const char* message_part2 = "Indented second line";
    const char* message_part3 = "Third line";
    const char* double_quote_text = "double quotes"; // 큰따옴표 안의 문자열
    const char* single_quote_text = "single quotes"; // 작은따옴표 안의 문자열

    // 실수 폭+정밀도 예시를 위한 변수
    float average_value = 87.35f; // float 변수

    printf("=== Char/String & Escapes ===\n"); // 제목
    printf("Char : %c, code: %d\n", char_example, char_example); // char 값과 아스키 코드 출력

    printf("Message:\n"); // Message: 출력 후 줄 바꿈

    printf("%s\n", message_part1); // First line
    printf("\t%s\n", message_part2); // \t를 사용하여 들여쓰기된 Indented second line
    printf("%s\n", message_part3); // Third line

    // Quotes: "double quotes" and 'single quotes' 출력
    // \" : 큰따옴표 출력, \' : 작은따옴표 출력
    printf("Quotes: \"%s\" and \'%s\'\n", double_quote_text, single_quote_text);

    // Backslash: \ 출력
    printf("Backslash: \\\n"); // \\ : 역슬래시 자체를 출력

    // Average: [  87.35] 출력 (8칸 확보, 소수점 2자리 정밀도, 오른쪽 정렬)
    printf("Average: [%8.2f]\n", average_value);

    return 0;
}