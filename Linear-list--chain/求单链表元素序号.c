/* ����Ҫ��ʵ��һ�����������ͷ���ĵ�������Ԫ����š� */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* ϸ���ڴ˲��� */

int Locate(LinkList L, ElemType e);

int main()
{
    ElemType e;
    LinkList L = Create();
    scanf("%d", &e);
    printf("%d\n", Locate(L, e));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int Locate(LinkList L, ElemType e)
{
    LinkList p;
    int locate = 0;
    p = L->next;
    while (p)
    {
        locate++;
        if (p->data == e)
        {
            return locate;
        }
        p = p->next;
    }
    return 0;
}