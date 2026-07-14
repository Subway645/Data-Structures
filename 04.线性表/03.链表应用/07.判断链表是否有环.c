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

//判断是否有环：快慢指针
int isCycle(Node *head){
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL &&fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}

int main(){
    Node *list = initList();
    insertTail(list, 1);
    insertTail(list, 2);
    insertTail(list, 3);
    Node *three = get_tail(list);
    insertTail(list, 4);
    insertTail(list, 5);
    insertTail(list, 6);
    get_tail(list)->next = three;
    if(isCycle(list)){
        printf("有环\n");
    }else{
        printf("无环\n");
    }
    return 0;
}