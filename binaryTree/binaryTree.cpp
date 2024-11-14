#include "binaryTree.hpp"


BinaryTree* newBinaryTree(ElemType e,BinaryTree *left,BinaryTree *right){
    BinaryTree *bt=(BinaryTree*)malloc(sizeof(BinaryTree));
    MakeTree(bt,e,left,right);
    return bt;
}

BinaryTree* newBinaryTree(){
    BinaryTree *bt=(BinaryTree*)malloc(sizeof(BinaryTree));
    bt->root=NULL;
    return bt;
}

BinaryTree* newBinaryTree(ElemType e){
    return newBinaryTree( e,newBinaryTree(),newBinaryTree());
}