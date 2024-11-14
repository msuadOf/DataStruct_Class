#include <iostream>
#include <stdlib.h>
#include<stdio.h>
using namespace std;

typedef int ElemType;
typedef struct node
{
    ElemType ele;
    struct node *next;
} LNode;
void foo(int * & x) {
    *x = 10;
}
bool Init(LNode * L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}
int  Len(LNode* L){
    int len=0;
    LNode* p=L;
    while(p->next!=NULL){
        len++;
        p=p->next;
    }
    return len;
}
LNode* Get(LNode* L,int i){

    LNode* p=L;
/*      int j=0; 
   while(p->next!=NULL&&j<i){
        p=p->next;
        j++;
    } */
   for(int j=0;j<i;j++){
    p=p->next;
   }
    return p;
}
typedef int *cc;
int main()
{
    LNode L,A,B,C;
    Init(&L);
    A={1,&B};
    B={2,&C};
    C={3,NULL};
    L.next=&A;
    printf("%d\n",Len(&L));
    printf("%d",Get(&L,1)->ele); //Get(&L,1)->ele;
    cout << "\n";
    int *a ;
    foo( a ); 
    cout << *a;
    cc *b= a;
    cout << *b;
    return 0;
}