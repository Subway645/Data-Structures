#include<stdio.h>
struct point
{
	int x;
	int y;
};
struct point creatPoint(int x, int y) {
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}
int main() {
	struct point p = creatPoint(10, 5);
	printf("%d %d", p.x, p.y);
	return 0;
}