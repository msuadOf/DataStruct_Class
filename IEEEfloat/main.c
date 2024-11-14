
#include <stdio.h>

#include <stdlib.h>

void  itoa(int num, char* str, int radix)
{
    int i = 0;
    int sum;
    unsigned int num1 = num;  //如果是负数求补码，必须将他的绝对值放在无符号位中在进行求反码
    char str1[33] = { 0 };
    if (num<0) {              //求出负数的补码
        num = -num;
        num1 = ~num;
        num1 += 1;
    }
    if (num == 0) {             
        str1[i] = '0';
        
        i++;
    }
    while(num1 !=0) {                      //进行进制运算
        sum = num1 % radix;
        str1[i] = (sum > 9) ? (sum - 10) + 'a' : sum + '0';
        num1 = num1 / radix;
        i++;
    }
    i--;
    int j = 0;
    for (; i >= 0; i--) {               //逆序输出 
        str[i] = str1[j];
        j++;
    }
    
}
typedef struct FF
{

    uint32_t fraction:23;

    uint32_t exp:8;
            uint32_t sign:1;
}FF;
typedef union Float
{
    FF FF;
    float floath;
}Float;

typedef union  Data {
    struct {
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
    } bits;
    unsigned char byte;
}Data;
void fun(int i,char *a){
    printf("sign:%hhx\n",(*((char*)(a+i)))&(0xF) );
}
int main()
{
    float a=-0.75f;
    FF f=*(FF*)&a;
    FF* fp=(FF*)&a;
    unsigned int *b;
    b=(unsigned int *)&a;
    printf("%x\n",*b);
    char s[100]={0};
    itoa(*b,s,2);//转成字符串，基数为2 
	printf("二进制：%s\n",s);
    printf("sign:%hhx\n",(*( ((char*)&fp) +0))&(0xFF) );
    Float f1={.floath=a};

 #ifdef __clang__//__GNUC__

    printf("==：%x\n",f1.FF.fraction);
     #endif
    return 0;
}