//������
/*����һ��������������ŵ����������ݣ���ѭ�Ĺ����ǣ���һ����ֵ��Ϊ��������������С�ڸ��ڵ��ֵ�������ӽڵ㣬���ڸ��ڵ��ֵ�������ӽڵ㡣 �ڴ����ö������Ļ���֮�ϣ����н��ͳ�ƺ�ɾ����ɾ���Ĳ��ԣ����ɾ�������Ҷ�ӽ�㣬ֱ��ɾ���õ㣻���ɾ�����ֻ��һ�������������ĸ����ֱ������ý�㣻���ɾ�����ͬʱ���������������������������е���Сֵ���ƶ���ɾ�����λ���������ɾ����㡣*/
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    int data;                                 //���������
    struct BiTNode *lchild, *rchild, *parent; //���Һ��Ӻ�˫��ָ��
} BiTnode, *BiTree;
//���������
void Create(BiTree &T, int n[])
{
    static int i = 0;
    T = new BiTNode;
    T->data = n[i++];
    Create(T->lchild, n);
    Create(T->rchild, n);
}
int main(void)
{
    BiTree T;
    int N;
    cin >> N;
    int n[30];
    char a;
    cin >> n[0];
    for (int i = 1; i < N; i++)
        cin >> a >> n[i];
    Create(T, n);
}
/*------------------------------------------------*/
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int a[45];
int De = 0, N = 0, f = 0;
int Do[5] = {0};
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
struct node
{
    BiTree T;
    int c;
};
void CreateTree(int x, BiTree &T)
{
    if (T == NULL)
    {
        T = new BiTNode;
        T->data = x;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else
    {
        if (x < T->data)
            CreateTree(x, T->lchild);
        if (x >= T->data)
            CreateTree(x, T->rchild);
    }
}
int LevelOrderTraverse(BiTree T)
{
    queue<node> q;
    node now;
    now.T = T;
    now.c = 1;
    q.push(now);
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        N++;
        De = max(De, now.c);
        if (now.T->lchild && now.T->rchild)
            Do[2]++;
        else if (now.T->lchild || now.T->rchild)
            Do[1]++;
        else
            Do[0]++;
        node next;
        next.c = now.c + 1;
        next.T = now.T->lchild;
        if (now.T->lchild)
            q.push(next);
        next.T = now.T->rchild;
        if (now.T->rchild)
            q.push(next);
    }
}
int LayerOrder(BiTree T)
{
    queue<BiTree> q;
    BiTree now;
    q.push(T);
    int f = 0;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        if (f)
            printf(",");
        printf("%d", now->data);
        f = 1;
        if (now->lchild)
            q.push(now->lchild);
        if (now->rchild)
            q.push(now->rchild);
    }
}
int InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return 0;
    InOrderTraverse(T->lchild);
    if (f)
        printf(",");
    f = 1;
    printf("%d", T->data);
    InOrderTraverse(T->rchild);
}
int DeleteBiTree(BiTree &T, int x)
{
    if (T == NULL)
        return 0;
    if (T->data == x)
    {
        if (T->lchild && T->rchild)
        {
            BiTree L;
            L = T->rchild;
            BiTree S;
            S = T->rchild;
            while (L->lchild)
                L = L->lchild;
            T->data = L->data;

            if (L != T->rchild)
            {
                BiTree R;
                R = L;
                while (R->rchild)
                    R = R->rchild;
                R->rchild = T->rchild;
                T->rchild = L->rchild;
                while (S->lchild && S->lchild != L)
                    S = S->lchild;
                S->lchild = NULL;
            }
            else
            {
                L->lchild = T->lchild;
                T = L;
            }
        }
        else if (T->lchild)
        {
            T = T->lchild;
        }
        else if (T->rchild)
        {
            T = T->rchild;
        }
        else
            T = NULL;
    }
    else
    {
        DeleteBiTree(T->lchild, x);
        DeleteBiTree(T->rchild, x);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        getchar();
    }
    int x;
    cin >> x;
    BiTree T;
    T = new BiTNode;
    T = NULL;
    for (int i = 0; i < n; i++)
    {
        CreateTree(a[i], T);
    }
    LevelOrderTraverse(T);
    printf("NodeNumbers:%d\n", N);
    printf("TreeDepth:%d\n", De);
    printf("numbers_0:%d\n", Do[0]);
    printf("numbers_1:%d\n", Do[1]);
    printf("numbers_2:%d\n", Do[2]);

    printf("InOrder:");
    f = 0;
    InOrderTraverse(T);
    puts("");
    printf("LayerOrder:");
    LayerOrder(T);
    puts("");

    DeleteBiTree(T, x);

    printf("InOrder after:");
    f = 0;
    if (T)
        InOrderTraverse(T);
    else
        printf("null");
    puts("");
    printf("LayerOrder after:");
    if (T)
        LayerOrder(T);
    else
        printf("null");
    puts("");
    return 0;
}