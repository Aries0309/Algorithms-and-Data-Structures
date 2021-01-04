/* ����Ҫ��ʵ��һ�����������ش�ͷ���ĵ����������Ԫ�صĵ�ַ�� */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* ϸ���ڴ˲��� */

LinkList MaxP(LinkList L);

int main()
{
    LinkList L, p;
    ElemType e;
    L = Create();
    p = MaxP(L);
    if (p)
        printf("%d\n", p->data);
    else
        printf("NULL");
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
LinkList MaxP(LinkList L)
{
    if (L == NULL || L->next == NULL)
    {
        return NULL;
    }
    LinkList p, q;
    p = L->next;
    q = p;
    while (p != NULL)
    {
        if (p->data > q->data)
        {
            q = p;
        }
        p = p->next;
    }
    return q;
}