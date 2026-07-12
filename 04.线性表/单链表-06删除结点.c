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

/*遍历*/
void listNode(Node* L){
    Node *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

/*删除结点*/
int deleteNode(Node* L, int pos){
    Node *p = L;
    int i = 0;
    while(i < pos-1){
        p = p->next;
        i++;
        if(p->next == NULL) return 0;
    }
    Node* q = p->next;
    p->next = q->next;
    //释放要删除结点的内存空间
    free(q);
    return 1;
}
int main(){
    Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 30);
    insertHead(list, 40);
    deleteNode(list, 2);
    listNode(list);
    return 0;
}