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

    // ���Ͽ� �����Ϳ� ����ü ���Ǹ� ����
    fprintf(file, "#include <stdio.h>\n");
    fprintf(file, "#include <stdlib.h>\n");
    fprintf(file, "\n");
    fprintf(file, "typedef struct tagPoint\n");
    fprintf(file, "{\n");
    fprintf(file, "    int id;\n");
    fprintf(file, "    double point;\n");
    fprintf(file, "} Point;\n");
    fprintf(file, "\n");
    fprintf(file, "Point DataSet[] =\n");
    fprintf(file, "{\n");

    for (int i = 0; i < size; i++)
    {
        fprintf(file, "    {%d, %.2f}%s\n", dataSet[i].id, dataSet[i].point, (i < size - 1) ? "," : "");
    }

    fprintf(file, "};\n");

    fclose(file);
}

int main() {
	qsort(DataSet, DATASET_SIZE, sizeof(Point), comparePoints);

	saveToFile("Point.h", DataSet, DATASET_SIZE);

	printf("���� �Ϸ��~");

	return 0;
}