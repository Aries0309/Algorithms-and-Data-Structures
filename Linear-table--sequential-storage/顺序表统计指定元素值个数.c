/* ����Ҫ��ʵ��һ��������Ҫ�󷵻�˳�����ָ��Ԫ��ֵ�ĸ������ձ���0����Ŀ��֤˳���������Ԫ�ض�Ϊ������ */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
void InitList(SqList &L); /*ϸ���ڴ˲���*/
int GetCount(SqList L, ElemType e);

int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d", &e);
    printf("The number of %d is %d.\n", e, GetCount(L, e));
    return 0;
}

/* ����������д�� */
int GetCount(SqList L, ElemType e)
{
    if (L.length == 0)
    {
        return 0;
    }
    int i, j = 0;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            j++;
        }
    }
    return j;
}