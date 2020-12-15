#include <iostream>
#include <string>
using namespace std;
typedef struct
{
    char ch;
    int Num;
} ElemType;
typedef struct
{
    ElemType *elem;
    int length;
} SqList;
//����һ���յ�˳���L
void InitList_L(SqList &L)
{
    L.elem = new ElemType[100]; //Ϊ˳������һ����СΪ100������ռ�
    L.length = 0;               //�ձ���Ϊ0
}
//��˳���L�в����µ�Ԫ��
void Insert_L(SqList &L, string s)
{
    for (int i = 0; L.length < 100 && i < s.length(); L.length++, i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            L.elem[L.length].ch = s[i];
        if (s[i] >= 0 && s[i] <= 9)
            L.elem[L.length].Num = s[i];
    }
}
//ͳ�Ʋ�ͬ�ַ����ֵ�Ƶ��
void Count(SqList L)
{
    ElemType s;
    int count;
    for (int i = 0; i < L.length; i++)
    {
        count = 0;
        if (L.elem[i].ch)
        {
            s.ch = L.elem[i].ch;
            for (int j = 0; j < L.length; j++)
            {
                if (s.ch == L.elem[j].ch)
                {
                    count++;
                    L.elem[j].ch = NULL;
                }
            }
            cout << s.ch << ":" << count << endl;
        }
        if (L.elem[i].Num)
        {
            s.Num = L.elem[i].Num;
            for (int j = 0; j < L.length; j++)
            {
                if (s.Num == L.elem[j].Num)
                {
                    count++;
                    L.elem[j].Num = NULL;
                }
            }
            cout << s.Num << ":" << count << endl;
        }
    }
}
int main(void)
{
    SqList L;
    string s;
    cin >> s;
    InitList_L(L);
    Insert_L(L, s);
    Count(L);
}