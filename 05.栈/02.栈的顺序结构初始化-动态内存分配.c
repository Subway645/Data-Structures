#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

typedef struct{
    ElemType *data;
    int top;
}Stack;

//初始化-动态内存分配
Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data =(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s){
    if(s->top == -1){
        printf("栈是空的\n");
        return 1;
    }else{
        return 0;
    }
}

//压栈
int push(Stack *s, ElemType e){
    if(s->top >= MAXSIZE-1){
        printf("栈已满\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

//出栈
ElemType pop(Stack *s, ElemType *e){
    if(s->top == -1){
        printf("栈为空\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

//获取栈顶元素
ElemType getTop(Stack *s, ElemType *e){
    if(s->top == -1){
        printf("栈为空\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

int main(){
    Stack *s;
    s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    ElemType e;
    pop(s, &e);
    printf("%d\n", e);
    getTop(s, &e);
    printf("%d\n", e);
    return 0;
}
