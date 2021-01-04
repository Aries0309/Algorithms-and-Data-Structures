#include <iostream>
using namespace std;
#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN + 1];
    int length;
} SString;
void get_S(SString &S, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        S.ch[S.length++] = s[i];
    }
}
void get_T(SString &T, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        T.ch[T.length++] = s[i];
    }
}
//��ģʽ��T��next����ֵ����������next
void get_next(SString T, int next[])
{
    int i, j;
    i = 1;
    next[1] = 0;
    j = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
//����ģʽ��T��next������T������S�е�λ��
int Index_KMP(SString S, SString T, int next[])
{ //���У�T�ǿ�
    int i, j;
    i = 0;
    j = 1;
    while (i <= S.length && j <= T.length) //��������δ�Ƚϵ���β
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        } //�����ȽϺ���ַ�
        else
            j = next[j]; //ģʽ�������ƶ�
    }
    if (j > T.length)
        return i - T.length; //ƥ��ɹ�
    else
        return 0; //ƥ��ʧ��
}
int main(void)
{
    string s;
    SString S, T;
    S.length = 0;
    T.length = 0;
    int next[9];
    cin >> s;
    get_S(S, s);
    cin >> s;
    get_T(T, s);
    get_next(T, next);
    cout << Index_KMP(S, T, next);
}