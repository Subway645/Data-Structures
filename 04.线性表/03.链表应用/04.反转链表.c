#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

//初始化
Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//获取尾结点
Node* get_tail(Node *L){
    Node *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
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

//尾插
Node* insertTail(Node *L, ElemType e){
    Node *tail = get_tail(L);
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

//反转链表
Node* reverseList(Node* head){
    Node *first = NULL;
    Node *second = head->next;
    Node *third;
    
    while(second != NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third; 
    }
    Node *hd = initList();
    hd->next = first;
    return hd;
}

int main(){
    Node *list = initList();
    insertTail(list, 10);
    insertTail(list, 20);
    insertTail(list, 30);
    insertTail(list, 40);
    insertTail(list, 50);
    listNode(list);
    Node* reverse = reverseList(list);
    listNode(reverse);
    return 0;
}