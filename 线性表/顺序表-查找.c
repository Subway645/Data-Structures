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

//查找
void findElem(SeqList* L, ElemType e) {
	for (int i = 0;i < L->length;i++) {
		if (e == L->data[i]) {
			printf("%d是第%d个元素\n", e, i + 1);
			return 0;
		}
	}
	printf("顺序表中无该元素");
	return 0;
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
	listElem(&list);
	findElem(&list, 45);
	return 0;
}