#include "Point.h"

Point* BinarySearch(Point pointList[], int size, double target)
{
	int left, right, mid;

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (target == pointList[mid].point)
			return &(pointList[mid]);
		else if (target > pointList[mid].point)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return NULL;
}

int main(void)
{
	int length = sizeof DataSet / sizeof DataSet[0];
	Point* found = NULL;

	// 구매포인트가 671.78점인 고객 찾기
	found = BinarySearch(DataSet, length, 671.78);

	printf("found... ID: %d, Point: %f \n", found->id, found->point);

	return 0;
}