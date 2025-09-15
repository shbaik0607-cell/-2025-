#include <stdio.h>

int main() {
    

    printf("=== Basic Constants ===\n");
    printf("Name    : %s\n", Sungwook);         // const char* 과 %s 사용
    printf("Initial : %c\n", S);      // char 와 %c 사용
    printf("Age     : %d\n", 28);          // int 와 %d 사용
    printf("Score   : %.6lf\n", 93.5);      // float 와 %f 사용 (소수점 6자리)
    printf("Count   : %u\n", 3000000000 );
	
	return 0;
}