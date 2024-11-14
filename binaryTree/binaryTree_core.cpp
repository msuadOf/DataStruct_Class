#include "binaryTree.hpp"

void Create(BinaryTree *bt)
{
    bt->root = NULL;
}
BTNode *NewNode(ElemType x, BTNode *ln, BTNode *rn)
{
    BTNode *p = (BTNode *)malloc(sizeof(BTNode));
    *p = (BTNode){.element = x,
                  .lChild = ln,
                  .rChild = rn};
    return p;
}

BOOL root(BinaryTree *bt, ElemType *x)
{
    if (bt->root)
    {
        x = &bt->root->element;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    (void)(x); // satisfy the compiler
}

void MakeTree(BinaryTree *bt, ElemType e, BinaryTree *left, BinaryTree *right)
{
    if (bt->root)
    {
        return;
    }
    bt->root = NewNode(e, left->root, right->root);
    left->root = right->root = NULL;
}

void Visit(BTNode *p)
{
    printf("%c ", p->element);
}
void PreOrd(BTNode *t) // 递归函数
{
    if (t)
    {
        Visit(t);
        PreOrd(t->lChild);
        PreOrd(t->rChild);
    }
}
void PreOrder(BinaryTree* Bt) // 主要函数
{
    PreOrd(Bt->root);
}
void InOrd(BTNode *t)
{
    if (t)
    {
        InOrd(t->lChild);
        Visit(t);
        InOrd(t->rChild);
    }
}
void InOrder(BinaryTree* Bt)
{
    InOrd(Bt->root);
}
void PostOrd(BTNode *t)
{
    if (t)
    {
        PostOrd(t->lChild);
        PostOrd(t->rChild);
        Visit(t);
    }
}
void PostOrder(BinaryTree* Bt)
{
    PostOrd(Bt->root);
}