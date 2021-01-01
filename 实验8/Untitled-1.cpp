#include <iostream>
using namespace std;
int count1 = 0; //�Ƚϴ���
int count2 = 0; //�ƶ�����
typedef struct
{
    int key; //���ؼ���
} ElemType;
typedef struct
{
    ElemType *R; //���ַ
    int length;  //��
} SSTable;

//����һ���յ�˳���L
void InitList(SSTable &L)
{
    L.R = new ElemType[100]; //Ϊ˳������һ����СΪ100������ռ�
    L.length = 0;            //�ձ���Ϊ0
}
void ListInsert(SSTable &L, int n)
{
    if (L.length == 100)
        return;
    for (int i = 1; i < n + 1; i++, L.length++)
        cin >> L.R[i].key;
}
void ListInsert(SSTable &L1, SSTable L)
{
    for (int i = 1; i < L.length + 1; i++, L1.length++)
        L1.R[i].key = L.R[i].key;
}

//���˳���L
void Print(SSTable L)
{
    for (int i = 1; i < L.length + 1; i++)
        cout << L.R[i].key << " ";
}

//��˳���L��ð������
void BubbleSort(SSTable &L)
{
    int m = L.length - 1, flag = 1; //flag�������ĳһ�������Ƿ�������
    count1 = 0, count2 = 0;
    while ((m > 0) && (flag == 1))
    {
        flag = 0; //flag��Ϊ0�������������û�з����������򲻻�ִ����һ������
        for (int j = 1; j <= m; j++)
        {
            if (L.R[j].key > L.R[j + 1].key)
            {
                flag = 1; //flag��Ϊ1����ʾ�����������˽���
                //����ǰ��������¼
                ElemType t = L.R[j];
                L.R[j] = L.R[j + 1];
                L.R[j + 1] = t;
                count2++;
            }
            count1++;
        }
        m--;
        Print(L);
        cout << endl;
    }
    cout << "�Ƚ���" << count1 << "�� �ƶ���" << count2 << "��" << endl;
    cout << "����һ���ȶ�������" << endl;
}

//��˳���L��һ��������dk��ϣ����������
void ShellInsert(SSTable &L, int dk)
{
    for (int i = dk + 1; i <= L.length; i++)
    { //�轫L.r[i]�������������ӱ�
        if (L.R[i].key < L.R[i - dk].key)
        {
            int j;
            L.R[0] = L.R[i]; //�ݴ���L.r[0]
            for (j = i - dk; j >= 0 && L.R[0].key < L.R[j].key; j -= dk)
                L.R[j + dk] = L.R[j]; //��¼���ƣ�ֱ���ҵ�����λ��
            L.R[j + dk] = L.R[0];     //��r[0]��ԭr[i]�����뵽��ȷλ��
            count2++;
        }
        count1++;
    }
}
//����������dt[0..t-1]��˳���L��t��ϣ������
void ShellSort(SSTable &L, int dt[], int t)
{
    count1 = 0, count2 = 0;
    for (int k = 0; k < t; k++)
    {
        ShellInsert(L, dt[k]); //һ������Ϊdt[t]��ϣ����������
        Print(L);
        cout << endl;
    }
    cout << "�Ƚ���" << count1 << "�� �ƶ���" << count2 << "��" << endl;
    cout << "����һ�����ȶ�������" << endl;
}

//����r[s+1..m]�Ѿ��Ƕѣ���r[s..m]����Ϊ��r[s]Ϊ���Ĵ����
void HeapAdjust(SSTable &L, int s, int m)
{
    ElemType rc = L.R[s];
    //��key�ϴ�ĺ��ӽ������ɸѡ
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && L.R[j].key < L.R[j + 1].key)
            j++; //jΪkey�ϴ�ļ�¼���±�
        if (rc.key >= L.R[j].key)
        {
            count2++;
            break; //rcӦ������λ��s��
        }
        L.R[s] = L.R[j];
        s = j;
        count1++;
    }
    L.R[s] = rc; //����
}
//����������L.r[i..n]���ɴ����
void CreateHeap(SSTable &L)
{
    int n = L.length;
    //��������HeapAdjust
    for (int i = n / 2; i > 0; i--)
        HeapAdjust(L, i, n);
}
//��˳���L���ж�����
void HeapSort(SSTable &L)
{
    count1 = 0, count2 = 0;
    CreateHeap(L); //����������L.r[1..L.lenth]���ɴ����
    for (int i = L.length; i > 1; i--)
    {
        ElemType x = L.R[1];
        L.R[1] = L.R[i];
        L.R[i] = x;
        HeapAdjust(L, 1, i - 1); //��L.r[i..i-1]���µ���Ϊ�����
        Print(L);
        cout << endl;
    }
    cout << "�Ƚ���" << count1 << "�� �ƶ���" << count2 << "��" << endl;
    cout << "����һ�����ȶ�������" << endl;
}

//��˳���L�е��ӱ�r[low..high]����һ�����򣬷�����Ŧλ��
int Partition(SSTable &L, int low, int high)
{
    L.R[0] = L.R[low];           //���ӱ�ĵ�һ����¼����Ŧ��¼
    int pivotkey = L.R[low].key; //��Ŧ��¼�ؼ��ֱ�����pivotkey��
    //�ӱ�����˽�������м�ɨ��
    while (low < high)
    {
        while (low < high && L.R[high].key >= pivotkey)
        {
            high--;
            count1++;
        }
        L.R[low] = L.R[high]; //������Ŧ��¼С�ļ�¼�Ƶ��Ͷ�
        count2++;
        while (low < high && L.R[low].key <= pivotkey)
        {
            low++;
            count1++;
        }
        L.R[high] = L.R[low]; //������Ŧ��¼��ļ�¼�Ƶ��߶�
        count2++;
    }
    L.R[low] = L.R[0]; //��Ŧ��¼��λ
    return low;        //������Ŧλ��
}
//����ǰ�ó�ֵ��low=1;high=L.length;
//��˳���L�е�������L.r[low..high]����������
void QSort(SSTable &L, int low, int high)
{
    //���ȴ���1
    if (low < high)
    {
        int pivotloc = Partition(L, low, high); //��L.r[low..high]һ��Ϊ����pivotloc����Ŧλ��
        Print(L);
        cout << endl;
        QSort(L, low, pivotloc - 1);  //�����ӱ�ݹ�����
        QSort(L, pivotloc + 1, high); //�����ӱ�ݹ�����
    }
}
//��˳���L����������
void QuickSort(SSTable &L)
{
    count1 = 0, count2 = 0;
    QSort(L, 1, L.length);
    cout << "�Ƚ���" << count1 << "�� �ƶ���" << count2 << "��" << endl;
    cout << "����һ�����ȶ�������" << endl;
}

int main(void)
{
    SSTable L, L1;
    int n, i;
    cout << "���ݸ�����";
    cin >> n;
    InitList(L);
    ListInsert(L, n);
    while (1)
    {
        InitList(L1);
        ListInsert(L1, L);
        int dt[] = {5, 3, 1}, t = 3;
        cout << "1.ð������" << endl;
        cout << "2.ϣ������" << endl;
        cout << "3.������" << endl;
        cout << "4.��������" << endl;
        cin >> i;
        switch (i)
        {
        case 1:
            BubbleSort(L1);
            break;
        case 2:
            ShellSort(L1, dt, t);
            break;
        case 3:
            HeapSort(L1);
            break;
        case 4:
            QuickSort(L1);
            break;
        default:
            i = 0;
            break;
        }
        if (i == 0)
            break;
    }
}