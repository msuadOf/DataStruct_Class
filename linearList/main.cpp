#include <iostream>
using namespace std;
typedef enum Status
{
    OK,
    ERROR
} Status;
typedef int ElemType;
typedef struct node
{
    ElemType element;
    struct node *link;
} Node;
typedef struct list
{
    Node *first;
    int n;
} SingleList;

Status Init(SingleList *L)
{
    L->first = NULL;
    L->n = 0;
    return OK;
}

Status Find(SingleList L, int i, ElemType *x)
{
    Node *p;
    int j;
    if (i < 0 || i > L.n - 1) // 对i 进行越界检查
        return ERROR;
    p = L.first;
    for (j = 0; j < i; j++)
        p = p->link; // 从头结点开始查找ai
    *x = p->element; // 通过x 返回ai 的值
    return OK;
}
Status Insert(SingleList *L, int i, ElemType x)
{
    Node *p, *q;
    int j;
    if (i < -1 || i > L->n - 1)
        return ERROR;
    p = L->first;
    for (j = 0; j < i; j++)
        p = p->link;                  // 从头结点开始查找ai
    q = (Node *)malloc(sizeof(Node)); // 生成新结点q
    q->element = x;
    if (i > -1)
    {
        q->link = p->link; // 新结点插在p 所指结点之后
        p->link = q;
    }
    else
    {
        q->link = L->first; // 新结点插在头结点之前，成为新的头结点
        L->first = q;
    }
    L->n++;
    return OK;
}
Status Display(SingleList *L){
    printf("list[%d]: ",L->n);
    for(int i=0;i<L->n;i++){
        ElemType x;
        Find(*L,i,&x);
        printf("%d ",x);
    }
    return OK;
}
int main()
{
    SingleList L;
    Init(&L);
    Insert(&L, 0, 20);
    Insert(&L, 1, 10);

    Display(&L);
    //cout << "hello";
    return 0;
}