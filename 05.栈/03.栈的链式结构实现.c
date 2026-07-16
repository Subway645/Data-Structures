#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct stack{
    ElemType data;
    struct stack *next;
}Stack;

//初始化
Stack* initStack()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

//判断是否为空结点
int isEmpty(Stack *s)
{
    if(s->next == NULL)
    {
        printf("栈是空的\n");
        return 1;
    }else{
        return 0;
    }
}

//进栈（头插法）
int push(Stack *s, ElemType e){
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

//出栈（删除头结点后的那个结点）
int pop(Stack *s, ElemType *e){
    if(s->next == NULL){
        printf("栈为空\n");
        return 0;
    }
    *e = s->next->data;
    Stack *q = s->next;
    s->next = q->next;
    free(q);
    return 1;
}

//获取栈顶元素
int getTop(Stack *s, ElemType *e){
    if(s->next == NULL){
        printf("栈为空\n");
        return 0;
    }
    *e = s->next->data;
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
