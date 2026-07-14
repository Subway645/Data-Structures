//1.分别求出两个链表的长度
//2.Fast指针指向较长链表，先走|m-n|步
//3.同步移动指针，判断是否指向同一个结点

#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;

//初始化结点
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

/*遍历*/
void listNode(Node* L){
    Node *p = L->next;
    while(p != NULL){
        printf("%c ", p->data);
        p=p->next;
    }
    printf("\n");
}

//尾插(数据)
Node* insertTail(Node *L, ElemType e){
    Node *tail = get_tail(L);
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

//尾插(结点)
Node* insertTailWithNode(Node *tail, Node *node){
    tail->next = node;
    node->next = NULL;
    return node;
}

//初始化结点（带结点数据域参数）
Node* initListWithElem(ElemType e){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
}

//查找两个结点共同后缀的位置
Node* findIntersectionNode(Node *headA, Node *headB){
    if(headA == NULL || headB == NULL){
        return NULL;
    }
    Node *p = headA;
    int lenA = 0;
    int lenB = 0;
    //遍历链表A，获取链表A的长度
    while(p != NULL){
        lenA++;
        p = p->next;
    }
    //遍历链表B，获取链表B的长度
    p = headB;
    while(p != NULL){
        lenB++;
        p = p->next;
    }

    Node *fast;//快指针
    Node *slow;//慢指针
    int step;//两个单词之间的差值，可以用于快指针先走的步数
    if(lenA > lenB){
        step = lenA - lenB;
        fast = headA;
        slow = headB;
    }else{
        step = lenB -lenA;
        fast = headB;
        slow = headA;
    }

    //让快指针先走step步
    for(int i = 0; i < step; i++){
        fast = fast->next;
    }
    //快慢指针同步走，直到指向同一个结点退出循环
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}


int main(){
    Node *listA = initList();
    Node *listB = initList();

    //A单词为：loading,B单词为：being
    insertTail(listA, 'l');
    insertTail(listA, 'o');
    insertTail(listA, 'a');
    insertTail(listA, 'd');
    insertTail(listB, 'b');
    insertTail(listB, 'e');
    Node *tailA = get_tail(listA);
    Node *tailB = get_tail(listB);
    Node *nodeI = initListWithElem('i');
    tailA = insertTailWithNode(tailA, nodeI);
    tailB = insertTailWithNode(tailB, nodeI);
    Node *nodeN = initListWithElem('n');
    tailA = insertTailWithNode(tailA, nodeN);
    tailB = insertTailWithNode(tailB, nodeN);
    Node *nodeG = initListWithElem('g');
    tailA = insertTailWithNode(tailA, nodeG);
    tailB = insertTailWithNode(tailB, nodeG);

    listNode(listA);
    listNode(listB);

    printf("%c\n",findIntersectionNode(listA, listB)->data);
    return 0;
}