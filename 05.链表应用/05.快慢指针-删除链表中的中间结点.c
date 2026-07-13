//若为偶数个结点，中间两个靠后的是中间结点
//如1 2 3 4，3是中间结点
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

//删除中间结点
void delMiddleNode(Node *head){
    Node *fast = head->next;
    Node *slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q);
}

int main(){
    Node *list = initList();
    insertTail(list, 10);
    insertTail(list, 20);
    insertTail(list, 30);
    insertTail(list, 40);
    insertTail(list, 50);
    listNode(list);
    delMiddleNode(list);
    listNode(list);
    delMiddleNode(list);
    listNode(list);
    return 0;
}