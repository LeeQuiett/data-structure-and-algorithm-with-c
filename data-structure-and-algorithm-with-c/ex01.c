#include <stdio.h>

struct Point {
	int x;
	int y;
};

struct forSize {
	int x;
	int y;
	char arr[10];
};

void main(void) {
	struct Point p;
	struct forSize f;
	printf("size: %d\n", (int)sizeof(p));
	printf("size: %d\n", (int)sizeof(f));
	printf("size: %d\n", (int)sizeof(f.arr));
}