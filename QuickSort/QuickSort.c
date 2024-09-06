#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int dataSet[], int left, int right)
{
	int first = left;
	int pivot = dataSet[first];

	++left;

	while (left < right)
	{
		while (dataSet[left] < pivot && left < right)
			++left;

		while (dataSet[right] >= pivot && left <= right)
			--right;

		if (left < right)
			swap(&dataSet[left], &dataSet[right]);
		else
			break;
	}
	swap(&dataSet[first], &dataSet[right]);

	return right;
}


void quickSort(int dataSet[], int left, int right)
{
	if (left < right)
	{
		int index = partition(dataSet, left, right);

		quickSort(dataSet, left, index - 1);
		quickSort(dataSet, index + 1, right);
	}
}

int main(void)
{
	int dataSet[] = { 6,4,2,3,1,5 };
	int length = sizeof dataSet / sizeof dataSet[0];
	
	quickSort(dataSet, 0, length - 1);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", dataSet[i]);
	}

	return 0;
}