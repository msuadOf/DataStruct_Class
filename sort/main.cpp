#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <stdio.h>
#include <time.h>
 
clock_t start, finish;
double times;

using namespace std;


#define ARRAY_LEN 200000000    //生成多大的数组
#define RANGE 100   //数组的元素大小从1到RAGNE

//#define mi_printf printf
#define mi_printf(...)
void print_array(int *a){

    printf("a[%d] = {",ARRAY_LEN);
    for (int i = 0; i < ARRAY_LEN; i ++)
    {
        if (i == ARRAY_LEN - 1)
            printf("%d",a[i]);
        else
            printf("%d,", a[i]);
    }
    printf("};\n");
    return ;

}
int* init_array(){

    int *a=(int*)malloc(ARRAY_LEN*sizeof(int));

    srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样

    mi_printf("a[%d] = {",ARRAY_LEN);
    for (int i = 0; i < ARRAY_LEN; i ++)
    {
        int number = rand() % RANGE + 1;  //产生1-100的随机数
        a[i] = number;
        if (i == ARRAY_LEN - 1)
            mi_printf("%d",number);
        else
            mi_printf("%d,", number);
    }
    mi_printf("};\n");
    return a;



}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
int* a=init_array();

puts("[enter sort]\n");
    start = clock();
    /**
     * 代码段
     *
     */
    qsort(a, ARRAY_LEN, sizeof(int), cmpfunc);
    //////////
    finish = clock();
    times = (double)(finish - start)/CLOCKS_PER_SEC;
    printf("\n[times:%f]\n", times);

//print_array(a);

    return 0;
}