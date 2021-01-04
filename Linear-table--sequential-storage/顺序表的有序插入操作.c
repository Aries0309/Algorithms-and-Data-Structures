/* ����Ҫ��ʵ��һ��������Ҫ��ָ��Ԫ�ز��뵽�����ĺ���λ�ã�ʹ�ò������Ȼ��������������ʧ�ܷ���0������ɹ��򷵻�1������˳���ĳ��ȼ�1. */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
void InitList(SqList &L); /*������ʵ�ִ˴�������ʾ*/
int SqInsert(SqList &L, ElemType e);
int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d", &e);
    int result = SqInsert(L, e);
    if (result == 0)
    {
        printf("Insertion Error.The storage space is full!");
    }
    else if (result == 1)
    {
        printf("Insertion Success.The elements of the SequenceList L are:");
        for (int j = 0; j < L.length; j++)
        {
            printf(" %d", L.elem[j]);
        }
    }
    return 0;
}

/* ����������д�� */
int SqInsert(SqList &L, ElemType e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] > e)
        {
            break;
        }
    }
    if (L.length == MAXSIZE)
    {
        return 0;
    }
    if (i == L.length)
    {
        L.elem[i] = e;
    }
    else
    {
        for (int j = L.length - 1; j >= i - 1; j--)
        {
            L.elem[j + 1] = L.elem[j];
        }
        L.elem[i - 1] = e;
    }
    ++L.length;
    return 1;
}