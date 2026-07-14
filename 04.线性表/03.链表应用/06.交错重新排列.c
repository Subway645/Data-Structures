//重新排列为(a1,an,a2,an-1,a3,an-2...)

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

//链表重新排序(如123456)
void reOrderList(Node *head){
    Node *fast = head->next;
    Node *slow = head;
    
    //1.先找中间结点
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *first = NULL;
    Node *second = slow->next;
    
    //2.把链表从中间分成两段(123 456)
    slow->next = NULL;
    Node *third = NULL;

    //3.反转链表(123 654)
    while(second != NULL){
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node *p1 = head->next; //指向1
    Node *q1 = first; //指向6
    Node *p2, *q2;

    //两个链表连接
    while(p1 != NULL && q1 != NULL){
        p2 = p1->next;
        q2 = q1->next;
        p1->next = q1;
        q1->next = p2;
        p1 = p2;
        q1 = q2;
    }
}

int main(){
    Node *list = initList();
    insertTail(list, 1);
    insertTail(list, 2);
    insertTail(list, 3);
    insertTail(list, 4);
    insertTail(list, 5);
    insertTail(list, 6);
    listNode(list);
    reOrderList(list);
    listNode(list);
    return 0;
}