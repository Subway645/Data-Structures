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

//遍历
void listNode(Node* L){
    Node *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

//头插法
void insertHead(Node* L, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    //NULL不能访问->prev
    if(L->next != NULL){
        L->next->prev = p;
    }
    L->next = p;
}

//获得尾结点
Node* getTail(Node *L){
    while(L->next != NULL){
        L = L->next; 
    }
    return L;
}

//尾插法
void insertTail(Node *L, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    Node *tail = getTail(L);
    tail->next = p;
    p->prev = tail;
    p->next = NULL;
}

int main(){
    Node *list = initList();
    insertTail(list, 10);
    insertTail(list, 20);
    insertTail(list, 30);
    listNode(list);
    return 0;
}