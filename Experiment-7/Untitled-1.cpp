#include <iostream>
using namespace std;
typedef struct
{
    int key; //���ؼ���
} ElemType;
typedef struct
{
    ElemType *R; //���ַ
    int length;  //��
} SSTable;
//����һ���յ�˳���ST
void InitList(SSTable &ST, int n)
{
    ST.R = new ElemType[n]; //Ϊ˳������һ����СΪ100������ռ�
    ST.length = n;
}
//����˳���
void CreateList(SSTable &ST)
{
    int key;
    for (int i = 0; i < ST.length; i++)
    {
        cin >> key;
        ST.R[i].key = key;
    }
}
//��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�δ֪������Ϊ0
int Search_Seq(SSTable ST, int key)
{
    int i;
    ST.R[0].key = key; //���ڱ���
    for (i = ST.length; ST.R[i].key != key; --i)
        ; //�Ӻ���ǰ��
    return i;
}
//�������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
int Search_Bin(SSTable ST, int key)
{
    int low = 1, high = ST.length; //�ò��������ֵ
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == ST.R[mid].key)
            return mid; //�ҵ�����Ԫ��
        else if (key < ST.R[mid].key)
            high = mid - 1; //������ǰһ�ӱ���в���
        else
            low = mid + 1; //�����ں�һ�ӱ���в���
    }
    return 0; //���в����ڴ���Ԫ��
}
//�����������Ķ�������洢��ʾ
typedef struct BSTNode
{
    ElemType data;                   //ÿ������������
    struct BSTNode *lchild, *rchild; //���Һ���ָ��
} BSTNode, *BSTree;
//������������T�в����ڹؼ��ֵ���w.key������Ԫ��ʱ��������Ԫ��
void InsertBST(BSTree &T, ElemType e)
{
    BSTree S;
    //�ҵ�����λ�ã��ݹ����
    if (!T)
    {
        S = new BSTNode;              //�����½��*S
        S->data = e;                  //�½��*S����������Ϊe
        S->lchild = S->rchild = NULL; //�½��*S��ΪҶ�ӽ��
        T = S;                        //���½��*S���ӵ����ҵ��Ĳ���λ��
    }
    else if (e.key < T->data.key)
        InsertBST(T->lchild, e); //��*S����������
    else if (e.key > T->data.key)
        InsertBST(T->rchild, e); //��*S����������
}
//���ζ���һ���ؼ���Ϊkey�Ľ�㣬���˽��������������T��
void CreateBST(BSTree &T, SSTable ST)
{
    T = NULL; //������������T��ʼ��Ϊ����
    for (int i = 0; i < ST.length; i++)
        InsertBST(T, ST.R[i]); //���˽��������������T��
}
//�������������T�ĵݹ��㷨
void InOrderTraverse(BSTree T)
{
    //���������ǿ�
    if (T)
    {
        InOrderTraverse(T->lchild); //�������������
        cout << T->data.key << " "; //���ʸ����
        InOrderTraverse(T->rchild); //�������������
    }
}
//�ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ��
//�����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
BSTree SearchBST(BSTree T, int key)
{
    if ((!T) || key == T->data.key)
        return T; //���ҽ���
    else if (key < T->data.key)
        return SearchBST(T->lchild, key); //���������м�������
    else
        return SearchBST(T->rchild, key); //���������м�������
}
int main(void)
{
    SSTable ST;
    BSTree T;
    int n, key;
    cout << "����";
    cin >> n;
    cout << "����Ԫ�أ�";
    InitList(ST, n);
    CreateList(ST);
    cout << "��Ҫ���ҵ�Ԫ�أ�";
    cin >> key;
    cout << "˳����ҽ����" << Search_Seq(ST, key) << endl;
    cout << "�۰���ҽ����" << Search_Bin(ST, key) << endl;
    CreateBST(T, ST);
    cout << "������������";
    InOrderTraverse(T);
    cout << endl;
    cout << "�������������ҽ����" << SearchBST(T, key);
}