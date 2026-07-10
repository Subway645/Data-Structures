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
		printf("Ë³Ğò±íÒÑÂú£¡\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}

//±éÀú
void listElem(SeqList* L)
{
	for (int i = 0;i < L->length;i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//É¾³ıÔªËØ
void deleteElem(SeqList* L, int pos)
{
	if (pos <= L->length)
	{
		for (int i = pos;i < L->length;i++)
		{
			L->data[i - 1] = L->data[i];
		}
	}
	L->length--;
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
	deleteElem(&list,2);
	listElem(&list);
	return 0;
}