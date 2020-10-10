/* ����Ҫ��ʵ��һ��������Ҫ��˳���ĵ�i��Ԫ��ɾ�����ɹ�ɾ������1�����򷵻�0�� */
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
int ListDelete(SqList &L, int i);
int main()
{
    SqList L;
    InitList(L);
    int i;
    scanf("%d", &i);
    int result = ListDelete(L, i);
    if (result == 0)
    {
        printf("Delete Error.The value of i is illegal!");
    }
    else if (result == 1)
    {
        printf("Delete Success.The elements of the SequenceList L are:");
        for (int j = 0; j < L.length; j++)
        {
            printf(" %d", L.elem[j]);
        }
    }
    return 0;
}
/* ����������д�� */
int ListDelete(SqList &L, int i)
{
    if ((i < 1) || (i > L.length))
    {
        return 0;
    }
    for (int j = i; j <= L.length - 1; j++)
    {
        L.elem[j - 1] = L.elem[j];
    }
    --L.length;
    return 1;
}