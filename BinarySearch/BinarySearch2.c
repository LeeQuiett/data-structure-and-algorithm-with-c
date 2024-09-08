#include "Point.h"

int comparePoint(const void* a, const void* b)
{
	Point* pointA = (Point*)a;
	Point* pointB = (Point*)b;

	if (pointA->point > pointB->point)
		return 1;
	else if (pointA->point < pointB->point)
		return -1;
	else 
		return 0;
}

int main(void)
{
	int lenght = sizeof DataSet / sizeof DataSet[0];

	Point target;
	Point* found = NULL;

	target.id = 0;
	target.point = 671.78;

	found = bsearch((void*)&target, (void*)DataSet, lenght, sizeof(Point), comparePoint);

	printf("found.. ID: %d, Point: %f \n", found->id, found->point);

	return 0;
}