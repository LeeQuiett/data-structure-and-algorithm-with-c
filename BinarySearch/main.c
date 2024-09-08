#include "Point.h"

// 배열 크기
#define DATASET_SIZE (sizeof(DataSet) / sizeof(DataSet[0]))

// qsort를 위한 비교 함수(오름차순)
int comparePoints(const void* a, const void* b)
{
	Point* pointA = (Point*)a;
	Point* pointB = (Point*)b;

	if (pointA->point > pointB->point) return 1;
	if (pointA->point < pointB->point) return -1;
	return 0;
}

// 결과를 파일에 저장하는 함수
void saveToFile(const char* filename, Point* dataSet, int size)
{
	FILE* file = fopen(filename, "w");
	if (file == NULL)
	{
		perror("파일 열기 실패");
		exit(1);
	}

	// 파일에 데이터 쓰기
	for (int i = 0; i < size; i++)
	{
		 fprintf(file, "{%d, %.2f},\n", dataSet[i].id, dataSet[i].point);
	}
	fclose(file);
}

int main() {
	qsort(DataSet, DATASET_SIZE, sizeof(Point), comparePoints);

	saveToFile("Point.h", DataSet, DATASET_SIZE);

	printf("정렬 완료옹~");

	return 0;
}