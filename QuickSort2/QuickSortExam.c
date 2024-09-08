#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int number;
	double point;
} Point;

Point dataSet[] = {
	1, 877.88,
	2, 176.23,
	3, 365.92,
	4, 162.44
};

int compare(const void* data1, const void* data2)
{
	double thisData1 = ((Point*)data1)->point;
	double thisData2 = ((Point*)data2)->point;

	if (thisData1 > thisData2)
		return -1;
	else if (thisData1 < thisData2)
		return 1;
	else 0;
}

int main(void)
{
	int length = sizeof dataSet / sizeof dataSet[0];

	qsort((void*)dataSet, length, sizeof, compare);

	for (int i = 0; i < length; i++)
	{
		printf("Number: %d, Point: %.2f\n", dataSet[i].number, dataSet[i].point);
	}
	return 0;
}
