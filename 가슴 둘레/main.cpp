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
	printf("�����ѷ��� %d �̰�, ������� %c �Դϴ�.", chest, size);
}