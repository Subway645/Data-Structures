#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

//栈
typedef struct{
    ElemType *data;
    int top;
}Stack;

//枚举
typedef enum{
    LEFT_PARE, RIGHT_PARE,
    ADD, SUB, MUL, DIV, MOD,
    EOS, NUM
}contentType;

//中缀表达式
char expr[] = "x/(i-j)*y";

//初始化
Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = 0;
    return s;
}

//判断栈是否为空
int isEmpty(Stack *s){
    if(s->top == -1){
        printf("为空\n");
        return 1;
    }
    return 0;
}

//获取栈顶元素
int getTop(Stack *s, ElemType *e) {
    if(s->top == -1){
        printf("为空\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
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
    if(isEmpty(s)){
        printf("为空\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return *e;
}


contentType getToken(char *symbol, int *index){
    *symbol = expr[*index];
    *index += 1;
    switch(*symbol){
        case'(':
            return LEFT_PARE;
        case')':
            return RIGHT_PARE;
        case'+':
            return ADD;
        case'-':
            return SUB;
        case'*':
            return MUL;
        case'/':
            return DIV;
        case'%':
            return MOD;
        case'\0':
            return EOS;
        default:
            return NUM;
    }
}

int print_token(contentType token){
    switch(token){
        case ADD:
            printf("+");
            break;
        case SUB:
            printf("-");
            break;
        case MUL:
            printf("*");
            break;
        case DIV:
            printf("/");
            break;
        case MOD:
            printf("%%");
            break;
        default:
            return 0;
    }
    return 1;
}

/*
如果是操作数，直接输出
如果是运算符，判断优先级，如果优先级大于栈顶元素，压入栈中,否则栈顶元素出栈
当左括号在栈外时，属于最高优先级，当左括号在栈里时，属于最低优先级
如果是右括号，且栈顶元素不是左括号，持续出栈并输出，知道栈顶为左括号出栈结束
*/
void postfix(Stack *s){
    //枚举里token分别在栈里和栈外的优先级
    int in_stack[] = {0, 19, 12, 12, 13,13, 13, 0};
    int out_stack[] = {20, 19, 12, 13, 13, 13, 0};
    contentType token;
    int index = 0;
    //栈顶先填
    s->data[0] = EOS;
    char symbol;
    ElemType e;

    token = getToken(&symbol, &index);
    
    while(token != EOS){
        if(token != EOS){
            if(token == NUM)
            {
                printf("%c",symbol);
            }
            else if(token ==RIGHT_PARE)
            {
                while(s->data[s->top] != LEFT_PARE){
                    pop(s, &e);
                    print_token(e);
                }
                pop(s, &e);
            }else{
                while(in_stack[s->data[s->top]]>=out_stack[token])
                {
                    pop(s, &e);
                    print_token(e);
                }
                push(s, token);
            }
            token = getToken(&symbol, &index);
        }
    }
}

int main(){
    Stack *s;
    s = initStack();
    postfix(s);
    return 0;
}
