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

/*获取尾结点*/
Node* get_tail(Node *L){
    Node *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    return p;
}

/*尾插*/
Node* insertTail(Node *L, ElemType e){
    Node *tail = get_tail(L);
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
};

int findNodeFS(Node *L, int k){
    Node *fast = L->next;
    Node *slow = L->next;
    for(int i = 0; i < k; i++){
        fast = fast->next;
        if(fast == NULL) return 0;
    }
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    printf("倒数第%d个结点值为：%d\n", k, slow->data);
    return 1;
}

int main(){
    Node *list = initList();
    insertTail(list, 10);
    insertTail(list, 20);
    insertTail(list, 30);
    insertTail(list, 40);
    insertTail(list, 50);
    findNodeFS(list, 3);
    return 0;
}