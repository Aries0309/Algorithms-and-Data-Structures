#include <iostream>
#include <queue>
using namespace std;
#define TElemType char

typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild; //���Һ���ָ��
} BiNode, *BiTree;

//1�������ַ�����,������������

//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
void CreateBiTree(BiTree &T)
{
    TElemType ch;
    cin >> ch;
    if (ch == '#')
        T = NULL; //�ݹ������������
    else          //�ݹ鴴��������
    {
        T = new BiNode;          //���ɸ��ڵ�
        T->data = ch;            //���ڵ���������Ϊch
        CreateBiTree(T->lchild); //�ݹ鴴��������
        CreateBiTree(T->rchild); //�ݹ鴴��������
    }                            //else
}

//2�����ȸ����и��ͺ������������(�ݹ��㷨)
//3����ĳ����ʽ������ö�����

//�������������T�ĵݹ��㷨
void PreOrderTraverse(BiTree T)
{
    if (T) //���������ǿ�
    {
        cout << T->data;             //���ʸ��ڵ�
        PreOrderTraverse(T->lchild); //�������������
        PreOrderTraverse(T->rchild); //�������������
    }
}
//�������������T�ĵݹ��㷨
void InOrderTraverse(BiTree T)
{
    if (T) //���������ǿ�
    {
        InOrderTraverse(T->lchild); //�������������
        cout << T->data;            //���ʸ��ڵ�
        InOrderTraverse(T->rchild); //�������������
    }
}
//�������������T�ĵݹ��㷨
void PostOrderTraverse(BiTree T)
{
    if (T) //���������ǿ�
    {
        PostOrderTraverse(T->lchild); //�������������
        PostOrderTraverse(T->rchild); //�������������
        cout << T->data;              //���ʸ��ڵ�
    }
}

//4����������ĸ߶�

//���������T�����
int BiTreeDepth(BiTree T)
{
    int m, n;
    if (T == NULL)
        return 0; //����ǿ��������Ϊ0���ݹ����
    else
    {
        m = BiTreeDepth(T->lchild); //�ݹ��������������ȼ�Ϊm
        n = BiTreeDepth(T->rchild); //�ݹ��������������ȼ�Ϊn
        if (m > n)
            return (m + 1); //�����������Ϊm��n�Ľϴ��߼�1
        else
            return (n + 1);
    }
}

//5�����������Ҷ�ڵ����

//����Ҷ�ӽ��ĸ���
void Count(BiTree T, int &count)
{
    if (T == NULL)
        return; //����ǿ�������Ҷ�ӽ�����Ϊ0���ݹ����
    if (T->lchild)
        Count(T->lchild, count); //��Ҷ�ӽ�㣬�ݹ�
    if (T->rchild)
        Count(T->rchild, count); //��Ҷ�ӽ�㣬�ݹ�
    if (T->lchild == NULL && T->rchild == NULL)
        count++; //Ҷ�ӽ�㣬����
}

//6����������������������

//����������T����������
void ExchangeChild(BiTree &T)
{
    if (T->lchild == NULL && T->rchild == NULL)
        return;            //�������������ݹ����
    if (T->lchild == NULL) //������Ϊ�գ�ֻ��������
    {
        T->lchild = T->rchild;
        T->rchild = NULL;
        ExchangeChild(T->lchild);
    }
    else if (T->rchild == NULL) //������Ϊ�գ�ֻ��������
    {
        T->rchild = T->lchild;
        T->lchild = NULL;
        ExchangeChild(T->rchild);
    }
    else //����������
    {
        BiTree empty;      //�����ս��
        empty = T->lchild; //��ʱ�洢����һ������
        T->lchild = T->rchild;
        T->rchild = empty;
        ExchangeChild(T->lchild);
        ExchangeChild(T->rchild);
    }
}

//7��ʵ�ֶ������Ĳ�α��������Խ��ö���ʵ�֣�

//��α���������T
void LevelOrderTraverse(BiTree &T)
{
    if (T == NULL)
        return; //����
    queue<BiTree> Q;
    Q.push(T);
    while (!Q.empty())
    {
        T = Q.front();
        Q.pop();
        cout << T->data; //�����Ӧ�������
        if (T->lchild)
            Q.push(T->lchild); //�������
        if (T->rchild)
            Q.push(T->rchild); //�Һ������
    }
}

int main(void)
{
    BiTree T, T1;
    cout << "�������ַ�����,�Խ�����������:";
    CreateBiTree(T);
    while (1)
    {
        cout << "1.����������������ö�������" << endl;
        cout << "2.����������������ö�������" << endl;
        cout << "3.����������������ö�������" << endl;
        cout << "4.��������ĸ߶ȡ�" << endl;
        cout << "5.���������Ҷ��������" << endl;
        cout << "6.����������������������" << endl;
        cout << "7.����α���������ö�������" << endl;
        cout << "0.�˳���" << endl;
        cout << "��������Ҫ���еĲ�����ţ�";
        int i;
        cin >> i;
        int count = 0;
        int high = 0;
        T1 = T;
        switch (i)
        {
        case 1:
            PreOrderTraverse(T);
            break;
        case 2:
            InOrderTraverse(T);
            break;
        case 3:
            PostOrderTraverse(T);
            break;
        case 4:
            high = BiTreeDepth(T);
            cout << "�������ĸ߶�Ϊ" << high;
            break;
        case 5:
            Count(T, count);
            cout << "һ��" << count << "��Ҷ�ӽ��";
            break;
        case 6:
            ExchangeChild(T);
            cout << "���";
            break;
        case 7:
            LevelOrderTraverse(T1);
            break;
        default:
            break;
        }
        cout << endl;
        if (i == 0)
            break;
    }
}