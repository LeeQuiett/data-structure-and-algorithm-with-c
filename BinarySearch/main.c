#include "Point.h"

// �迭 ũ��
#define DATASET_SIZE (sizeof(DataSet) / sizeof(DataSet[0]))

// qsort�� ���� �� �Լ�(��������)
int comparePoints(const void* a, const void* b)
{
	Point* pointA = (Point*)a;
	Point* pointB = (Point*)b;

	if (pointA->point > pointB->point) return 1;
	if (pointA->point < pointB->point) return -1;
	return 0;
}

// ����� ���Ͽ� �����ϴ� �Լ�
void saveToFile(const char* filename, Point* dataSet, int size)
{
	FILE* file = fopen(filename, "w");
	if (file == NULL)
	{
		perror("���� ���� ����");
		exit(1);
	}

	// ���Ͽ� ������ ����
	for (int i = 0; i < size; i++)
	{
		 fprintf(file, "{%d, %.2f},\n", dataSet[i].id, dataSet[i].point);
	}
	fclose(file);
}

int main() {
	qsort(DataSet, DATASET_SIZE, sizeof(Point), comparePoints);

	saveToFile("Point.h", DataSet, DATASET_SIZE);

	printf("���� �Ϸ��~");

	return 0;
}