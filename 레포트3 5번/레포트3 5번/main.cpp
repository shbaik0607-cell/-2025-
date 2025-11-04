#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 1. 함수: 게임 초기화 및 정답 난수 생성 (1~100)
// 주석: 난수 시드를 초기화하고 1부터 100까지의 정답 숫자를 생성하여 반환
int initialize_game() {
	srand((unsigned int)time(NULL));
	int target = rand() % 100 + 1;
	printf("Up & Down 게임을 시작합니다. (1~100 사이)\n"); return target;
}
// 2. 함수: 게임 로직 실행
// 주석: 반복문(while)을 사용하여 기회가 남아있는 동안 게임을 진행
void play_game(int target) {
	int chances = 10; // 남은 기회
	int guess = 0; // 사용자 입력
	int is_correct = 0; // 정답 여부 (선택문 사용을 위한 변수)
	// 주석: 10번의 기회(chances > 0) 동안 반복
	while (chances > 0) {
		printf("남은 기회: %d 번\n", chances);
		printf("숫자를 입력하세요: ");
		scanf_s("%d", &guess);
		// 주석: 선택문(if-else if-else)을 사용하여 정답, UP, DOWN 판단
		if (guess == target) {
			printf(" 축하합니다! 정답입니다.\n");
			is_correct = 1; // 정답임을 표시
			break; // 정답이면 반복문(while) 즉시 종료 (break 사용)
		}
		else if (guess > target) {
			printf("DOWN ↓\n\n");
		}
		else { // guess < target
			printf("UP ↑\n\n");
		}
		chances--; // 기회 1회 감소
	}
	// 주석: 반복문이 끝난 후 정답을 맞추지 못했을 경우 최종 결과 출력 (선택문 사용)
	if (!is_correct) {
		printf("아쉽게도 기회를 모두 소진했습니다. 정답은 %d 였습니다.\n", target);
	}
}
// 메인 함수
int main() {
	// [1] 게임 초기화 및 정답 생성 함수 호출
	int target_number = initialize_game();
	// [2] 게임 실행 함수 호출
	play_game(target_number);
	return 0;
}