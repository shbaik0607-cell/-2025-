#include <stdio.h>
#define NUM_PRINT 0

void PrintHelloworld(int nCount);

int main(void) 
{
	int nCount = 5;
	PrintHelloworld(nCount);
	return 0;
}

void PrintHelloworld(int nCount)
{
	if (nCount == NUM_PRINT)
	{
		return;
	}
	printf("Hellow World!(%d)\n", nCount);
	PrintHelloworld(--nCount);
	return;
}