#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct QueueNode{
    ElemType data;
    struct QueueNode *next;
}QueueNode;


//这个结构体与链表不同，因为是队列，需要有指针分别指向头节点和队尾
typedef struct{
    QueueNode *front;
    QueueNode *rear;
}Queue;

//初始化  (头节点不算队列元素)
Queue* initQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->next = NULL;
    node->data = 0;
    q->front = node;
    q->rear = node;
    return q;
}

//判断队列是否为空
int isEmpty(Queue *q)
{
    if(q->front == q->rear)
    {
        return 1;
    }else{
        return 0;
    }
}

//入队
void equeue(Queue *q, ElemType e)
{
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

//出队
int dequeue(Queue *q, ElemType *e)
{
    QueueNode *node = q->front->next; //相当于队头
    *e = node->data;
    q->front->next = node->next;  //头节点指向的next现在指向了原队头的next
    /*原来front->A(<-rear)->NULL
    若没有下列if语句，front->NULL,而rear仍指向已free的node，悬空指针*/
    if (q->rear == node){
        q->rear = q->front;
    }
    free(node);
    return 1;
}

//获取队头元素
ElemType getFront(Queue *q){
    if(isEmpty(q)){
        printf("空的\n");
        return 0;
    }
    return q->front->next->data;
}