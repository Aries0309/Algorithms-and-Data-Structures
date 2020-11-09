#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef char SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;
int InitStack(SqStack &S)
{                                    //����һ����ջS
    S.base = new SElemType[MAXSIZE]; //Ϊ˳��ջ��̬����һ���������ΪMAXSIZE������ռ�
    if (!S.base)
        return 0;          //�洢����ʧ��
    S.top = S.base;        //top��ʼΪbase����ջ
    S.stacksize = MAXSIZE; //stacksize��Ϊջ���������MAXSIZE
    return 1;
}
int StackEmpty(SqStack S)
{ //�ж�ջ��
    if (S.top == S.base)
        return 1; //ջ��
    else
        return 0; //ջ�ǿ�
}
int StackLength(SqStack S)
{ //����ջ�ĳ���
    return S.top - S.base;
}
int Push(SqStack &S, SElemType e)
{ //����Ԫ��eΪ�µ�ջ��Ԫ��
    if (S.top - S.base == S.stacksize)
        return 0; //ջ��
    *S.top++ = e; //Ԫ��eѹ��ջ����ջ��ָ���1
    return 1;
}
int Pop(SqStack &S, SElemType &e)
{ //ɾ��S��ջ��Ԫ�أ���e������ֵ
    if (S.top == S.base)
        return 0; //ջ��
    e = *--S.top; //ջ��ָ���1����ջ��Ԫ�ظ���e
    return 1;
}
int main(void)
{
    SqStack S;
    InitStack(S); //����һ����ջS
    SElemType e;
    Push(S, e);     //����Ԫ��eΪ�µ�ջ��Ԫ��
    StackLength(S); //����ջ�ĳ���
    Pop(S, e);      //ɾ��S��ջ��Ԫ�أ���e������ֵ
    StackEmpty(S);  //�ж�ջ��
}