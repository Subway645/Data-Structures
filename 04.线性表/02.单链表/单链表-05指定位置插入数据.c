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

/*头插法*/
void insertHead(Node* L, ElemType e){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

/*在指定位置插入,把新结点插到第pos个位置*/
int insertNode(Node *L, int pos, ElemType e){
    Node *p = L;
    int i = 0;
    while(i < pos-1){
        p = p->next;
        i++;
        if (p==NULL){
            return 0;
        }
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

/*遍历*/
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
    insertHead(list, 40);
    insertNode(list, 2, 20);
    listNode(list);
    return 0;
}