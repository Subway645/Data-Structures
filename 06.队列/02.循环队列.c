#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType *data;
    int front;
    int rear;
}Queue;

//初始化
void initQueue(Queue *Q){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    Q->front = 0;
    Q->rear = 0;
}


//判断是否为空
int isEmpty(Queue *Q){
    if(Q->front == Q->rear){
        printf("队列是空的\n");
        return 1;
    }else{
        return 0;
    }
}
//入队
int equeue(Queue *Q, ElemType e){
    if((Q->rear + 1) % MAXSIZE == Q->front){
        printf("队列已满\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

//出队
int dequeue(Queue *Q)
{
    if(Q->front == Q->rear){
        printf("队列是空的\n");
        return 0;
    }
    int e = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return e;
}

//获取队头元素
int getHead(Queue *Q, ElemType *e){
    if(Q->front == Q->rear){
        printf("队列为空\n");
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}

int main(){
    Queue q;
    initQueue(&q);

    equeue(&q, 10);
    equeue(&q, 20);
    equeue(&q, 30);
    equeue(&q, 40);
    equeue(&q, 50);

    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    ElemType e;
    getHead(&q, &e);
    printf("%d\n", e);
    
    return 0;
}