/* ����Ҫ��ʵ��һ�����������ͷ���ĵ�����ı��� */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* ϸ���ڴ˲��� */

int Length(LinkList L);

int main()
{
    LinkList L = Create();
    printf("%d\n", Length(L));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int Length(LinkList L)
{
    LinkList p;
    p = L->next;
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}