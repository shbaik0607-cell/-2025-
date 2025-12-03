#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

// 입력 버퍼(Input Buffer)를 비우는(clear) 역할
void clear_input_buffer(void)
{
    int c;
    // 주석: 입력 버퍼에 남아있는 모든 문자(개행 문자 '\n' 포함)를 제거하는 함수이다.
    // 주석: scanf() 등으로 입력받은 후 버퍼에 남아있는 '\n' 문자로 인해
    // 주석: 다음에 호출되는 getchar()나 gets/fgets가 오작동하는 것을 방지한다.
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ; // 문자를 읽고 버림
    }
}
int main(void)
{
    char str1[100];
    char str2[100];
    char copy[100];
    char sentence[200];
    char temp[200];

    char* pos;
    char ch;

    char* p_str1 = str1;
    char* p_str2 = str2;
    char* p_copy = copy;
    char* p_sentence = sentence;
    char* p_temp = temp;

    printf("Enter first string (no spaces): ");
    scanf("%99s", p_str1); // 주석: str1에 첫 번째 문자열 입력 (최대 99자)

    printf("Enter second string (no spaces): ");
    scanf("%99s", p_str2); // 주석: str2에 두 번째 문자열 입력 (최대 99자)

    printf("\n--- Printed strings (using puts) ---\n");
    puts(p_str1); // 주석: 첫 번째 문자열을 출력하고 자동으로 줄 바꿈
    puts(p_str2); // 주석: 두 번째 문자열을 출력하고 자동으로 줄 바꿈
    
    // strlen 함수로 배열에 저장된 문자열의 길이를 알수있다.
    printf("\n--- strlen practice ---\n"); // 주석: strlen 함수 실습
    // 주석: p_str1이 가리키는 문자열의 길이(널 문자 '\0' 제외)를 출력한다.
    printf("Length of str1: %zu\n", strlen(p_str1));
    // 주석: p_str2가 가리키는 문자열의 길이(널 문자 '\0' 제외)를 출력한다.
    printf("Length of str2: %zu\n", strlen(p_str2));
    // ---------------------------------------------------------------------
   
    // 바로 위 scanf()가 남긴 '\n' 문자를 제거하여, 다음에 호출되는 fgets()가 이를 빈 줄로 처리하는 것을 방지하기 위함이다.
    clear_input_buffer(); 
    
    printf("\n**Note: clear_input_buffer() was called to clear the previous input**\n");
    printf("\nEnter one sentence (can include spaces): ");
    // 주석: p_sentence 배열에 공백을 포함한 한 문장을 입력받는다.
    // 주석: fgets는 버퍼 크기(sizeof(sentence))를 지정하여 오버플로우를 방지한다.
    fgets(p_sentence, sizeof(sentence), stdin);
    printf("\n>>> You entered (sentence) = ");
    puts(p_sentence);
    // ---------------------------------------------------------------------
   
	// strcpy 함수로 문자열 복사를 할수있다. 복사할때는 배열로
    printf("\n--- Practice #1: strcpy ---\n"); // 주석: strcpy 함수 실습
    // 주석: p_str1이 가리키는 문자열을 p_copy가 가리키는 배열로 복사한다.
    strcpy(p_copy, p_str1);
    printf("copy = ");
    puts(p_copy); // 주석: 복사된 결과를 출력
    // ---------------------------------------------------------------------
   
    // strcat 함수는 문자열을 이어붙이는 역할을 한다. 문자열을 최초로 붙을 때는 초기화 해야한다.
    printf("\n--- Practice #2: strcat ---\n"); // 주석: strcat 함수 실습
    // 주석: str1의 버퍼 크기가 str1 길이 + str2 길이보다 큰지 확인하여 버퍼 오버플로우를 방지
    if (strlen(p_str1) + strlen(p_str2) < sizeof(str1)) {
        // 주석: p_str2가 가리키는 문자열을 p_str1이 가리키는 문자열의 끝에 연결한다. (덮어쓰기가 아님)
        strcat(p_str1, p_str2);
        printf("After concatenation, str1 = ");
        puts(p_str1);
    }
    else {
        // 주석: str1 배열의 크기가 연결된 문자열을 담기에는 너무 작을 경우 오류 메시지 출력
        printf("str1 buffer is too small; cannot perform strcat!\n");
    }
    // ---------------------------------------------------------------------
    
    // strcmp 함수로 문자열 비교하여 순서를 정할수있다.
    printf("\n--- Practice #3: strcmp ---\n"); // 주석: strcmp 함수 실습
    // 주석: p_str1과 p_str2 문자열을 사전 순(Lexicographical order)으로 비교한다.
    int cmp = strcmp(p_str1, p_str2);
    if (cmp == 0) {
        // 주석: cmp가 0이면 두 문자열은 동일하다.
        printf("str1 and str2 are equal.\n");
    }
    else if (cmp < 0) {
        // 주석: cmp가 0보다 작으면 str1이 str2보다 사전 순으로 앞에 온다.
        printf("In lexicographical order, str1 comes before str2.\n");
    }
    else { // cmp > 0
        // 주석: cmp가 0보다 크면 str1이 str2보다 사전 순으로 뒤에 온다.
        printf("In lexicographical order, str1 comes after str2.\n");
    }
    // ---------------------------------------------------------------------
    
	// strchr 문자열str에서 특정 문자ch의 위치를 찾는 역할(문자 검색)
    printf("\n--- Practice #4: strchr ---\n"); // 주석: strchr 함수 실습
    printf("\n>>> Enter a character to search for: ");
    // 주석: 검색할 문자(ch)를 입력받는다. %c 앞에 공백을 넣어 입력 버퍼의 잔여 공백을 무시한다.
    scanf(" %c", &ch);
    // 주석: p_str1 문자열에서 ch 문자가 처음 나타나는 위치의 주소(pos)를 찾는다.
    pos = strchr(p_str1, ch);
    if (pos != NULL) {
        // 주석: 문자를 찾았을 경우, 시작 주소(p_str1)와의 차이를 이용해 인덱스(위치)를 계산하여 출력
        printf("'%c' is at index %ld (0-based) in str1.\n",
            ch, (long)(pos - p_str1));
    }
    else {
        // 주석: 문자를 찾지 못했을 경우
        printf("'%c' is not found in str1.\n", ch);
    }
    // ---------------------------------------------------------------------
    
	// strstr 문자열str에서 특정 문자열str2의 위치를 찾는 역할(문자열 검색)
    printf("\n--- Practice #5: strstr ---\n"); // 주석: strstr 함수 실습

    // 주석: p_sentence(긴 문장) 내에서 p_str2(짧은 문자열)가 처음 나타나는 위치의 주소(pos)를 찾는다.
    pos = strstr(p_sentence, p_str2);
    if (pos != NULL) {
        // 주석: 문자열을 찾았을 경우, 찾은 문자열과 해당 위치부터 시작하는 나머지 문자열을 출력
        printf("Found \"%s\" inside sentence.\n",
            p_str2);
        printf("Substring starting from the found position: ");
        puts(pos);
    }
    else {
        // 주석: 문자열을 찾지 못했을 경우
        printf("Could not find \"%s\" in sentence.\n",
            p_str2);
    }
    // ---------------------------------------------------------------------
   
    // 문자열에서 토큰 단위로 자를 때 사용하는 함수
    printf("\n--- Practice #6: strtok ---\n"); // 주석: strtok 함수 실습
    printf("\n--- strtok practice: split sentence by spaces ---\n");

    // 왜 이 실습에서는 temp에 문자열을 복사하는가?
    // 주석: strtok 함수는 문자열을 토큰(token)으로 분리하는 과정에서 원본 문자열의 구분자(Delimiter)를
    // 주석: 널 문자('\0')로 덮어씌워 원본 문자열을 변경(파괴)한다.
    // 주석: 원본 문자열(p_sentence)을 보존하기 위해 p_temp에 복사하여 사용한다.
    strcpy(p_temp, p_sentence); // 주석: 원본 p_sentence를 보존하기 위해 p_temp에 복사

    char* token = strtok(p_temp, " "); // 주석: p_temp에서 공백(" ")을 기준으로 첫 번째 토큰을 찾는다.
    int i = 1;
    // 주석: 토큰(token)이 NULL이 아닐 때까지 반복문(while)을 실행하여 모든 토큰을 처리한다.
    while (token != NULL) {
        printf("Token %d: ", i++);
        puts(token); // 주석: 현재 찾은 토큰을 출력
        // 주석: strtok의 첫 번째 인수로 NULL을 전달하여 이전 호출에 이어 다음 토큰을 찾도록 지시한다.
        token = strtok(NULL, " ");
    }
    // ---------------------------------------------------------------------

    printf("\nProgram finished.\n");
    return 0;
} // main 함수의 끝