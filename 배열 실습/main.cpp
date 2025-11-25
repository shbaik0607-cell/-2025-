#include <stdio.h>
#include <math.h>

int main(void) 
{
	int score[5];
	int i;
	int total = 0;
	double average;
	double diff = 0.0;
	double stddev;
	int count;

	count = sizeof(score) / sizeof(score[0]);

	for (i = 0; i < count; i++) 
	{
		
		scanf_s("%d", &score[i]);
		
	}
	for (i = 0; i < count; i++) 
	{
		total += score[i];
	}
	average = total / (double)count;

	for (i = 0; i < count; i++)
	{
		diff += pow(score[i] - average, 2);
	}
	stddev = diff / count;

	for	(i = 0; i < count; i++) 
	{
		printf("%5d", score[i]);
	}
	
	printf("--------------------------\n");

	printf("avg: %.1lf\n", average);
	printf("diff: %.1lf\n", diff);
	printf("stddev: %.1lf\n", stddev);


	return 0;
}