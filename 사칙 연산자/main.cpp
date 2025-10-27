#include <stdio.h>

// 1부터 n까지의 합을 계산하는 재귀 함수
int sum_recursive(int n) {
    // 1. **기저 조건 (Base Case):**
    // n이 1이면 (더 이상 더할 것이 없으면) 1을 반환합니다.
    if (n == 1) {
        return 1;
    }

    // 2. **재귀 호출 (Recursive Step):**
    // n + (1부터 n-1까지의 합)을 반환합니다.
    // 'sum_recursive(n - 1)'이 자기 자신을 다시 호출합니다.
    return n + sum_recursive(n - 1);
}

int main() {
    int target = 10;

    // 재귀 함수 호출
    int result = sum_recursive(target);

    // 결과 출력
    printf("1부터 %d까지의 합은: %d\n", target, result);

    return 0;
}