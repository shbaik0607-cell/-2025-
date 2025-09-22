#include <stdio.h>

int main() {
	const char* title = "Basic Constants";
    const char* name = "Sungwook";
    char initial = 'S';
    int age = 28;
    float score = 93.5f;
    unsigned int count = 3000000000U;

	printf(" === %s === \n\n",title);
	printf("Name\t: %s\n\n", name);
    printf("Initial\t: %c\n\n", initial);
    printf("Age : %d\n\n", age);
    printf("Score\t: %.2f\n\n", score);
    printf("Count\t: %u\n\n", count);
	return 0;
}