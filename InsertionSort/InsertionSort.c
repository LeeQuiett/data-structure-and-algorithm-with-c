#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int length)
{
	int value = 0;

	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (DataSet[j - 1] > DataSet[j]) 
			{
				value = DataSet[j - 1];
				DataSet[j - 1] = DataSet[j];
				DataSet[j] = value;
			}
			else
			{
				break;
			}
		}		
	}
}