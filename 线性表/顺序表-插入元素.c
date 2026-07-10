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
	L->length++;
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

//插入元素
void insertElem(SeqList* L, int pos, ElemType e) 
{
	if (pos <= L->length)
	{
		for (int i = L->length-1;i >= pos-1;i--)
		{
			L->data[i+1] = L->data[i];
		}
		L->data[pos-1] = e;
		L->length++;
	}
	return 1;
}
int main() {
	SeqList list;
	initList(&list);
	appendElem(&list, 87);
	appendElem(&list, 56);
	appendElem(&list, 43);
	appendElem(&list, 45);
	appendElem(&list, 12);
	listElem(&list);
	insertElem(&list, 2, 77);
	listElem(&list);
	return 0;
}