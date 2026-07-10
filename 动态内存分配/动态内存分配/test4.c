#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int x;
	int y;
}po;

int main() {
	po* p;
	p = (po*)malloc(sizeof(po));
	p->x = 5;
	p->y = 10;
	printf("%d %d\n", p->x, p->y);
	return 0;
}