#include <iostream>
using namespace std;
#define MAXSIZE 5
int main(void)
{
    int array[MAXSIZE][MAXSIZE], min[MAXSIZE], max[MAXSIZE], a[MAXSIZE], b[MAXSIZE];
    cout << "������һ��" << MAXSIZE << "��" << MAXSIZE << "�ľ���" << endl;
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++)
            cin >> array[i][j]; //��ȡ����
    for (int i = 0; i < MAXSIZE; i++)
    {
        a[i] = 0;
        max[i] = array[i][0]; //���ֵ��ʼΪ���е�һ��Ԫ��
        for (int j = 0; j < MAXSIZE; j++)
            if (array[i][j] > max[i])
            {
                max[i] = array[i][j];
                a[i] = j;
            }
    }
    for (int j = 0; j < MAXSIZE; j++)
    {
        b[j] = 0;
        min[j] = array[0][j]; //��Сֵ��ʼΪ���е�һ��Ԫ��
        for (int i = 0; i < MAXSIZE; i++)
            if (array[i][j] < min[j])
            {
                min[j] = array[i][j];
                b[j] = i;
            }
    }
    for (int i = 0; i < MAXSIZE; i++)
        for (int j = 0; j < MAXSIZE; j++)
            if (b[j] == i && a[i] == j)
                cout << max[i]; //max[i]��min[j]����
}