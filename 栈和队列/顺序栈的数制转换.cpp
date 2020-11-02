/* ���һ��˳��ջ�������ø�˳��ջ��������ʮ����������ת��Ϊ�˽��Ʋ������ */
#include <iostream>
using namespace std;

#define STACKSIZE 10
typedef int DataType;
typedef struct
{
    DataType *base;
    DataType *top;
    int stacksize;
} SqStack;

//��ʼ����˳��ջ
int InitStack(SqStack &S);

//��ջ��
int StackEmpty(SqStack S);

//��ջ
int Push(SqStack &S, DataType item);

//��ջ
int Pop(SqStack &S, DataType &item);

void conversion(int N)
{ //��������һ���Ǹ�ʮ����������ӡ��������ֵ�İ˽�����
    SqStack S;
    InitStack(S); //��ʼ����ջS
    while (N)
    {                   //��N����ʱ,ѭ��
        Push(S, N % 8); //��N��8����õ��İ˽�����ѹ��ջS
        N = N / 8;      //N����ΪN��8����
    }
    int e;
    cout << "ת���İ˽�����Ϊ��";
    while (!StackEmpty(S)) //��ջS�ǿ�ʱ��ѭ��
    {
        Pop(S, e); //����ջ��Ԫ��e
        cout << e; //���e
    }
}
int main()
{
    int m, n;
    cout << "������ʮ������:";
    cin >> m;
    conversion(m);
    return 0;
}

/* ����������д�� */
//��ʼ����˳��ջ
int InitStack(SqStack &S)
{
    S.base = new DataType[STACKSIZE]; //Ϊ˳��ջ��̬����һ���������ΪSTACKSIZE������ռ�
    if (!S.base)
    {
        return 0; //�洢����ʧ��
    }
    S.top = S.base;          //top��ʼΪbase����ջ
    S.stacksize = STACKSIZE; //stacksize��Ϊջ���������STACKSIZE
    return 1;
}
//�ж�ջ��
int StackEmpty(SqStack S)
{
    if (S.top == S.base)
    {
        return 1; //ջ��
    }
    else
    {
        return 0; //ջ�ǿ�
    }
}
//��ջ
int Push(SqStack &S, DataType item)
{
    if (S.top - S.base == S.stacksize)
    {
        return 0; //ջ��
    }
    *S.top++ = item; //Ԫ��itemѹ��ջ����ջ��ָ���1
    return 1;
}
//��ջ
int Pop(SqStack &S, DataType &item)
{
    if (S.top == S.base)
    {
        return 0; //ջ��
    }
    item = *--S.top; //ջ��ָ���1����ջ��Ԫ�ظ���e
    return 1;
}