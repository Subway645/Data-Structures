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
	printf("初始化成功，目前长度占用%d\n", list.length);
	printf("目前占用内存%zu字节\n", sizeof(list.data));
	return 0;
}
