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

void insertHead(Node* L, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

/*±éÀú*/
void listNode(Node* L){
    Node *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

//ÊÍ·ÅÁ´±í
void freeList(Node *L){
    Node *p = L->next;
    Node *q;
    while(p !=NULL){
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

int main(){
    Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 30);
    insertHead(list, 40);
    listNode(list);
    freeList(list);
    listNode(list);
    return 0;
}