#include<stdio.h>
typedef struct  //也可以写成typedef struct point{...}po;
{
	int x;
	int y;
}po;

int main() {
	po p;
	p.x = 5;
	p.y = 10;
	printf("x: %d, y: %d\n", p.x, p.y);
	return 0;
}

