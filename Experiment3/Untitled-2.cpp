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
SElemType GetTop(SqStack S)
{                            //����S��ջ��Ԫ�أ����޸�ջ��ָ��
    if (S.top != S.base)     //ջ�ǿ�
        return *(S.top - 1); //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
}
int main(void)
{
    SqStack S;
    InitStack(S); //����һ����ջS
    SElemType e;
    int i = 0, n;
    cout << "������n" << endl;
    cin >> n;
    cout << "�������ַ���" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> e;
        if (n % 2 != 0)
        {
            if (i < n / 2)
                Push(S, e); //����Ԫ��eΪ�µ�ջ��Ԫ��
            else if (i > n / 2 && GetTop(S) == e)
                Pop(S, e); //ɾ��S��ջ��Ԫ�أ���e������ֵ
        }
        else
        {
            if (i < n / 2)
                Push(S, e); //����Ԫ��eΪ�µ�ջ��Ԫ��
            else if (i >= n / 2 && GetTop(S) == e)
                Pop(S, e); //ɾ��S��ջ��Ԫ�أ���e������ֵ
        }
    }
    if (StackEmpty(S)) //�ж�ջ��
        cout << "���ַ������ĶԳ�" << endl;
    else
        cout << "���ַ����������ĶԳ�" << endl;
}