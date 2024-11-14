#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

#include "data_struct.hpp"

typedef struct btnode {
    ElemType element;
    struct btnode *lChild;
    struct btnode *rChild;
} BTNode;

typedef struct {
    BTNode *root;
} BinaryTree;

void Create(BinaryTree *bt);
BTNode *NewNode(ElemType x, BTNode *ln, BTNode *rn);
BOOL Root(BinaryTree *bt,ElemType *x);
void MakeTree(BinaryTree *bt,ElemType e,BinaryTree *left,BinaryTree *right);

void PreOrd(BTNode *t) ;
void PreOrder(BinaryTree* Bt);
void InOrd(BTNode *t);
void InOrder(BinaryTree* Bt);
void PostOrd(BTNode *t);
void PostOrder(BinaryTree* Bt);

BinaryTree* newBinaryTree(ElemType e,BinaryTree *left,BinaryTree *right);
BinaryTree* newBinaryTree();
BinaryTree* newBinaryTree(ElemType e);


#endif