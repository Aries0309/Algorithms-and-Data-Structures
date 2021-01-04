/* ����Ҫ��ʵ��һ�����ʽ����ƥ���жϺ������������Ϊһ��ָ�����ַ������ַ������Ȳ��ɳ�100��������()
��[] �� {}
������ʽ��������ʽ���磺{[(1 + 2) * 3]} - 9�������ƥ��ɹ�����ú���Ӧ�÷���1��ƥ�䲻�ɹ��򷵻�0�� */
#include <iostream>
using namespace std;

#define STACKSIZE 10
typedef char DataType;
typedef struct
{
    DataType *base;
    DataType *top;
    int stacksize;
} SqStack;
//��ʼ����˳��ջ��ϸ���ڴ˲���
int InitStack(SqStack &S);

//��˳��ջ�գ�ϸ���ڴ˲���
int StackEmpty(SqStack S);

//��ջ��ϸ���ڴ˲���
int Push(SqStack &S, DataType item);

//��ջ��ϸ���ڴ˲���
int Pop(SqStack &S, DataType &item);

//ȡջ����ϸ���ڴ˲���
int GetTop(SqStack S, DataType &item);

//���ʽ����ƥ���жϺ������Զ���
int matching(char *exp);

int main()
{
    char expr[100];
    //cout << "��������ʽ:";
    cin >> expr;
    char *ex = expr;
    if (matching(ex))
    {
        cout << "ƥ��ɹ�";
    }
    else
    {
        cout << "ƥ�䲻�ɹ�";
    };

    return 0;
}

/* ����������д�� */
int matching(char *exp)
{                             //��ʾ������ʹ��string.h�е�"strlen()"�����������ж��û�����ı��ʽ�ĳ���
    SqStack S;                //����һ��˳��ջ
    InitStack(S);             //��ʼ����˳��ջ
    int length = strlen(exp); //��ȡ�ַ�������
    // if (*exp == '(' || *exp == '[' || *exp == '{')
    // {
    //     Push(S, *exp);
    // }
    while (length--)
    {
        if (*exp == '(' || *exp == ')' || *exp == '[' || *exp == ']' || *exp == '{' || *exp == '}')
        {
            char e = GetTop(S, e);
            if (e == '(' && *exp == ')')
            {
                Pop(S, e);
            }
            else if (e == '[' && *exp == ']')
            {
                Pop(S, e);
            }
            else if (e == '{' && *exp == '}')
            {
                Pop(S, e);
            }
            else
            {
                Push(S, *exp);
            }
            exp++;
        }
    }
    if (StackEmpty(S))
    {
        return 1; //ջ��
    }
    else
    {
        return 0; //ջ�ǿ�
    }
}