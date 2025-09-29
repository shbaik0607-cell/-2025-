#include <stdio.h>

main(void) {
	int nAge = 99;
	float fHeight = 999.01;
	double dWeight = 999.0;

	char chTemp = ' ';
	char chString[100] = " ";


	printf("input your information(age, height, weight):\n ");
	scanf("%c%s", &chTemp, (unsigned int)sizeof(chTemp), chString, (unsigned int)sizeof(chString));
	printf("Output\n");
	printf("(Alphabet:%c)(Word:%s)\n", &chTemp, chString);

	return 0;
}
