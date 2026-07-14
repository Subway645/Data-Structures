#include<stdio.h>
#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;

void initList(SeqList* L)
{
	L->length = 0;
}

int appendElem(SeqList* L, ElemType e) 
{
	if (L->length >= MAXSIZE) 
	{
		printf("顺序表已满！\n");
		return 0;
	}
	L->data[L->length] = e;
	L -> length++;
	return 1;
}

//遍历
void listElem(SeqList* L) 
{
	for (int i = 0;i < L->length;i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}
int main() {
	SeqList list;
	initList(&list);
	appendElem(&list, 645);
	appendElem(&list, 810);
	listElem(&list);
	printf("目前长度占用%d\n", list.length);
	printf("目前占用内存%zu字节\n", sizeof(list.data));
	return 0;
}