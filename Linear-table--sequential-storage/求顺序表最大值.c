/* ����Ҫ��ʵ��һ��������Ҫ�󷵻�˳�������ֵ���ձ���0����Ŀ��֤˳���������Ԫ�ض�Ϊ�������� */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
void InitList(SqList &L); /*ϸ���ڴ˲���*/
int GetMax(SqList L);

int main()
{
    SqList L;
    InitList(L);
    int p;
    p = GetMax(L);
    if (p)
        printf("The max of SequenceList L is %d.\n", p);
    else
        printf("The SequenceList is null.\n");
    return 0;
}

/* ����������д�� */
int GetMax(SqList L)
{
    if (L.length == 0)
    {
        return 0;
    }
    int i, max = L.elem[0];
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] > max)
        {
            max = L.elem[i];
        }
    }
    return max;
}