#include <iostream>
using namespace std;
#define MAXSIZE 100
//��Ԫ��Ķ���
typedef struct
{
    int row, col; //��ʾ����
    int e;        //��ʾֵ
} Triple;
//��Ԫ�������Ķ���
typedef struct
{
    Triple data[MAXSIZE];
    int m, n, len;
} TSMatrix;
//ʵ��ת��
void TransposeTSMatrix(TSMatrix A, TSMatrix *B)
{
    int i, j, k;
    B->m = A.n;
    B->n = A.m;
    B->len = A.len;
    j = 0;
    for (k = 0; k < A.len; ++k)
        for (i = 0; i < A.len; ++i)
            if (A.data[i].col == k)
            {
                B->data[j].row = A.data[i].col;
                B->data[j].col = A.data[i].row;
                B->data[j].e = A.data[i].e;
                ++j;
            }
}
int main()
{
    TSMatrix A, B;
    int i, j, e;
    int k = 0;
    cout << "��������Ԫ�飺";
    while (scanf("%d%d%d", &i, &j, &e) != EOF)
    {
        A.data[k].row = i - 1;
        A.data[k].col = j - 1;
        A.data[k].e = e;
        A.len = ++k;
    }
    cout << endl
         << "ת�ú�:" << endl;
    TransposeTSMatrix(A, &B);
    for (i = 0; i < B.len; ++i)
        cout << B.data[i].row + 1 << B.data[i].col + 1 << B.data[i].e << endl;
}