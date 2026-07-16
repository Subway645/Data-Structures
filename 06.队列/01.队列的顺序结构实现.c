#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

//初始化
void initQueue(Queue *Q)
{
    Q->front = 0; //队列头
    Q->rear = 0;  //队列尾
}

//判断队列是否为空
int isEmpty(Queue *Q){
    if(Q->front == Q->rear){
        printf("队列为空\n");
        return 1;
    }else{
        return 0;
    }
}


//调整队列(队尾满了)
int QueueFull(Queue *Q){
    if(Q->front > 0){
        int step = Q->front;
        for(int i = Q->front; i <= Q->rear; ++i){
            Q->data[i - step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }else{
        printf("队列真的满了\n");
        return 0;
    }
}

//出队，从队列头出去
ElemType dequeue(Queue *Q){
    if(Q->front == Q->rear){
        printf("队列为空\n");
    }
    ElemType e = Q->data[Q->front];
    Q->front++;
    return e;
}

//入队
int equeue(Queue *Q, ElemType e){
    if(Q->rear >= MAXSIZE){
        if(!QueueFull(Q)){
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;
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