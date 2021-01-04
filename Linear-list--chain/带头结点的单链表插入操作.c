/* ����Ҫ��ʵ�ִ�ͷ���ĵ�����������������ɹ�����1�����򷵻�0�� */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* ϸ���ڴ˲��� */
void print(LinkList L);
int insert_link(LinkList L, int i, ElemType e);

int main()
{
    int position, insert_data;
    int flag;
    LinkList L = Create();
    scanf("%d", &position);
    scanf("%d", &insert_data);
    flag = insert_link(L, position, insert_data);
    if (flag)
    {
        print(L);
    }
    else
    {
        printf("Wrong Position for Insertion");
    }
    return 0;
}
void print(LinkList L)
{
    LinkList p;
    p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
/* ����������д�� */
int insert_link(LinkList L, int i, ElemType e)
{
    LinkList p, s;
    p = L;
    int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || (j > i - 1))
    {
        return 0;
    }
    s = (LinkList)malloc(sizeof(struct LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}