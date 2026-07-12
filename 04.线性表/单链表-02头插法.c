#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
/*带头结点链表里的头插，就是插在头结点的后一位，也就是整个数据链表的最开头*/
void insertHead(Node* L, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

int main(){
    Node *list = initList();
    insertHead(list, 10);
    return 0;
}