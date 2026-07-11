#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;
#define MAXSIZE 100

typedef struct {
	ElemType *data;
	int length;
}SeqList;

SeqList* initList(){
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length = 0;
	return L;

}


int main(){
	SeqList* list = initList();
	printf("初始化成功，目前长度占用%d\n",list->length);
	printf("目前内存占用%zu字节\n",sizeof(list));//list 是指针变量，不是结构体本身,64 位系统指针固定占 8 字节,若sizeof(*list)则为16字节
	return 0;
}