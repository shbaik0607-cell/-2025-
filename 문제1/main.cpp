#include <stdio.h>

int main() {
    const char* name = "Sungwook";
    char initial = 'S';
    int age = 28;
    float score = 93.5f;
    unsigned int count = 3000000000U;

	printf(" === Basic Constants === \n\n");
	printf("Name: %s\n\n", name);
    printf("Initial: %c\n\n", initial);
    printf("Age: %d\n\n", age);
    printf("Score: %.2f\n\n", score);
    printf("Count: %u\n\n", count);
	return 0;
}