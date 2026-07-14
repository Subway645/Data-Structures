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

//删除绝对值相同的结点
void removeNode(Node *L, int n) //n为链表长度
{
    Node *p = L;
    int index; //作为数组下标
    int *q = (int*)malloc(sizeof(int)*(n+1));

    //遍历数组，初始化值为0
    for (int i = 0; i < n+1; i++){
        *(q+i) = 0;
    }

    while(p->next != NULL){
        //abs获取绝对值
        index = abs(p->next->data);
        if(*(q+index) == 0){
            *(q+index) = 1;
            p = p->next;
        }else{
            Node *temp = p->next;
            p->next = temp->next;        //此时p不动，p->next动，可删除连续相同数据结点
            free(temp);
        }
    }
    free(q);
}

int main(){
    Node *list = initList();
    insertTail(list, 10);
    insertTail(list, 8);
    insertTail(list, 7);
    insertTail(list, -8);
    insertTail(list, 8);
    listNode(list);
    removeNode(list,10);
    listNode(list);
    return 0;
}