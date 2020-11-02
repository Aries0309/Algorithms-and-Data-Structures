/* �����ɸ�С��Χ��һȦ���ִ�ָ���ĵ�1����ʼ������������ w��ʱ����С�����У�Ȼ�����һ��С����ʼ���������Ǳ���w�����У�����ظ���ȥ��ֱ�����е�С�������У�����������w��ʱ��ѭ������������С�����е�˳�� �㷨Ҫ��ʹ��˳��ѭ���������洢����С��������ʱС�����ӣ�δ����wʱ��������ӣ�����wʱ�����С�������֣���С��������ӣ����ֱ������С�����ӣ�����Ϊ��ʱֹͣ������ ��д��˳��ѭ�����е����л��������� ˵�� �����뱨����Ϸ��С���������ܳ���10�ˡ� */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 11
#define N 10

int main()
{
    ElemType *e;
    int n, i;
    SqQueue *q;
    InitQueue(q);
    scanf("%d", &n);
    while (1)
    {
        char *name = (char *)malloc(sizeof(char) * N);
        scanf("%s", name);
        if ((strcmp("-1", name) == 0) || !enQueue(q, name))
            break;
    }
    i = n - 1;
    while (!QueueEmpty(q))
    {
        deQueue(q, e);
        if (i-- > 0)
            enQueue(q, e);
        else
        {
            printf("%s\n", e);
            i = n - 1;
            free(e);
        }
    }
    DestroyQueue(q);
}

/* ����������д�� */
typedef char ElemType;
typedef struct // ˳��ѭ�����н�㶨��
{
    ElemType *name[MaxSize]; //С������
    int front, rear;         //���׺Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue *&q) //��ʼ�����У�
{
    q = (SqQueue *)malloc(sizeof(SqQueue)); //Ϊ���з���һ���������ΪMaxSize������ռ�
    q->front = q->rear = 0;                 //ͷָ���βָ����Ϊ�㣬����Ϊ��
}
void DestroyQueue(SqQueue *&q) //���ٶ��У�
{
    free(q);
}
bool QueueEmpty(SqQueue *q) //�ж�����Ϊ��ʱ����true; ���򷵻�false;
{
    if (q->front == q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool enQueue(SqQueue *&q, ElemType *e) // e ��ӣ��ɹ���ӷ���true; ���򷵻�false;
{
    if ((q->rear + 1) % MaxSize == q->front)
    {
        return false; //����
    }
    q->name[q->rear] = e; //���
    q->rear = (q->rear + 1) % MaxSize;
    return true;
}
bool deQueue(SqQueue *&q, ElemType *&e) //���ӣ����س���Ԫ��e���ҳɹ����ӷ���true,���򷵻�false;
{
    if (q->rear == q->front)
    {
        return false; //�ӿ�
    }
    e = q->name[q->front]; //����
    q->front = (q->front + 1) % MaxSize;
    return true;
}