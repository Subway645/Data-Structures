#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;

void initList(SeqList *L)
{
	L->length = 0;
}

int main() {
	SeqList list;
	initList(&list);
	printf("%d\n", list.length);
	printf("%zu\n", sizeof(list.data));
	return 0;
}
