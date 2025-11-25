#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_COUNT 6
#define MAX_NUMBER 45

// 1. 함수: 난수 생성 및 중복 확인
// 주석: 배열에 이미 존재하는 숫자인지 확인
int is_duplicate(const int* arr, int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) return 1;
    }
    return 0;
}

// 2. 함수: 로또 번호 생성 (당첨 번호 6개와 보너스 번호 1개)
// 주석: 1~45 사이의 중복 없는 난수 6개와 보너스 번호 1개를 생성 (반복문 사용)
void generate_lotto_numbers(int* winners, int* bonus) {
    srand((unsigned int)time(NULL));
    int temp_num;

    // 당첨 번호 6개 생성
    for (int i = 0; i < LOTTO_COUNT; i++) {
        do {
            temp_num = rand() % MAX_NUMBER + 1; // 1 ~ 45
        } while (is_duplicate(winners, i, temp_num)); // 중복 시 다시 생성 (do-while 사용)
        winners[i] = temp_num;
    }

    // 보너스 번호 생성 (당첨 번호와 중복되지 않도록)
    do {
        temp_num = rand() % MAX_NUMBER + 1;
    } while (is_duplicate(winners, LOTTO_COUNT, temp_num));
    *bonus = temp_num; // 포인터를 사용하여 보너스 번호 저장
}

// 3. 함수: 사용자 번호 입력 받기
// 주석: 사용자로부터 6개의 번호를 입력 받으며 유효성 검사 (1~45, 중복 여부) 수행
void get_user_numbers(int* user_nums) {
    int input;
    printf("로또 번호 6개를 입력하세요 (1~45, 중복 없이):\n");
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d번째 번호: ", i + 1);

        // 주석: 유효성 검사를 위해 do-while 및 선택문(if) 사용
        if (scanf_s("%d", &input) != 1 || input < 1 || input > MAX_NUMBER || is_duplicate(user_nums, i, input)) {
            printf(" 잘못된 입력입니다. 1~45 범위의 중복 없는 숫자를 다시 입력하세요.\n");
            i--; // 다시 입력 받기 위해 인덱스 감소
            // 입력 버퍼 비우기
            while (getchar() != '\n');
            continue;
        }
        user_nums[i] = input;
    }
}

// 4. 함수: 당첨 여부 확인 및 등수 결정
void check_winning(const int* winners, int bonus, const int* user_nums) {
    int match_count = 0;
    int bonus_match = 0;

    // 주석: 사용자 번호와 당첨 번호를 비교하여 일치 개수 확인 (중첩 반복문 사용)
    for (int i = 0; i < LOTTO_COUNT; i++) {
        for (int j = 0; j < LOTTO_COUNT; j++) {
            if (user_nums[i] == winners[j]) {
                match_count++;
                break;
            }
        }
        // 보너스 번호 일치 확인 (중첩 반복문 밖에서 확인하는 것이 효율적)
        if (user_nums[i] == bonus) {
            bonus_match = 1;
        }
    }

    printf("\n=== 당첨 결과 ===\n");
    printf("일치 개수: %d개, 보너스 일치: %s\n", match_count, bonus_match ? "O" : "X");

    // 주석: 선택문(if-else if-else)을 사용하여 당첨 등수 결정
    if (match_count == 6) {
        printf("1등에 당첨되었습니다!\n");
    }
    else if (match_count == 5 && bonus_match) {
        printf(" 2등에 당첨되었습니다!\n");
    }
    else if (match_count == 5) {
        printf(" 3등에 당첨되었습니다!\n");
    }
    else if (match_count == 4) {
        printf("4등에 당첨되었습니다!\n");
    }
    else if (match_count == 3) {
        printf("5등에 당첨되었습니다!\n");
    }
    else {
        printf("아쉽지만 다음 기회에...\n");
    }
}

// 메인 함수
int main() {
    int winning_numbers[LOTTO_COUNT];
    int user_numbers[LOTTO_COUNT];
    int bonus_number;

    // [1] 컴퓨터 로또 번호 생성
    generate_lotto_numbers(winning_numbers, &bonus_number);

    printf("로또 6/45 당첨 번호: ");
    for (int i = 0; i < LOTTO_COUNT; i++) {
        printf("%d ", winning_numbers[i]);
    }
    printf(" | 보너스 번호: %d\n\n", bonus_number);

    // [2] 사용자 번호 입력
    get_user_numbers(user_numbers);

    // [3] 당첨 확인
    check_winning(winning_numbers, bonus_number, user_numbers);

    return 0;
}