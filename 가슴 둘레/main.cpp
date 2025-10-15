#include <stdio.h>
int main() 
{
	int chest = 95;
	char size;
	scanf_s("%d", &chest);
	if (chest <= 90)
	{size = 'S';
	}
	else if (90< chest <= 100)
	{
		size = 'M';
	}
	else
	{
		size = 'L';
	}
	printf("가슴둘레는 %d 이고, 사이즈는 %c 입니다.", chest, size);
}