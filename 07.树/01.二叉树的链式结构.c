#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

//定义二叉树
typedef struct TreeNode{
    ElemType data;
    struct TreeNode *lchild;  //左孩子
    struct TreeNode *rchild;  //右孩子
}TreeNode;

typedef TreeNode* BiTree;

char str[] = "ABDH###E##CFI###G#J##"; 

int idx = 0;

void createTree(BiTree *T) //双指针类型
{
    ElemType ch;
    ch = str[idx++];
    if(ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);

    }
}

//二叉树前序遍历(其顺序可以理解为栈)
void preOrder(BiTree T){
    if(T == NULL){
        return;
    }
    printf("%c ", T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

//中序遍历,可画栈和树图看看
void inOrder(BiTree T){
    if(T == NULL){
        return;
    }
    inOrder(T->lchild);
    printf("%c ", T->data);
    inOrder(T->rchild);
}

//后续遍历
void postOrder(BiTree T){
    if(T == NULL){
        return;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    printf("%c ", T->data);
}

int main(){
    BiTree T;
    createTree(&T);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");
    return 0;
}