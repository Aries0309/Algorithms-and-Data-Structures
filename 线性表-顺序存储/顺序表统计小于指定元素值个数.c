/* ����Ҫ��ʵ��һ��������Ҫ�󷵻�˳�����С��ָ��Ԫ��ֵ�ĸ������ձ���0����Ŀ��֤˳���������Ԫ�ض�Ϊ������ */
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
int GetSmaller(SqList L, ElemType e);

int main()
{
    SqList L;
    InitList(L);
    ElemType e;
    scanf("%d", &e);
    printf("The number smaller than %d is %d.\n", e, GetSmaller(L, e));
    return 0;
}

/* ����������д�� */
int GetSmaller(SqList L, ElemType e)
{
    if (L.length == 0)
    {
        return 0;
    }
    int i, j = 0;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] < e)
        {
            j++;
        }
    }
    return j;
}