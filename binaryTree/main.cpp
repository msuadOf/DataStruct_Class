#include "data_struct.hpp"
#include <iostream>
using namespace std;
#include "binaryTree.hpp"
#define T newBinaryTree
int main()
{
    BinaryTree *bt = T('A',
                       T('B',T('D'),T()), T('C',T('E'),T('F'))
                       );
    cout << bt->root->element << bt->root->lChild->element << endl;
    //InOrder(bt);
    int i=0;
    for(;i<2;i++)
        cout << i << endl;
    cout << i << endl;
    return 0;
}