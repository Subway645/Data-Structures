#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next, *prev;
}Node;

//初始化链表
Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    head->next = NULL;
    return head;
}

//头插法
int insertHead(Node* L, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    //NULL不能访问->prev
    if(L->next != NULL){
        L->next->prev = p;
    }
    L->next = p;
    return 1;
}

//遍历
void listNode(Node* L){
    Node *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    listNode(list);
    return 0;
}