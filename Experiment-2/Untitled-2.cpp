/* ���ڵ�����ʵ��һԪ����ʽ��ϡ�裩����Ӻ���� */
#include <iostream>
using namespace std;
typedef struct PNode
{
    float coef;         //ϵ��
    int expn;           //ָ��
    struct PNode *next; //ָ����
} PNode, *Polynomial;
void CreatePolyn1(Polynomial &Pa, int n)
{
    Polynomial s, pre, q;
    Pa = new PNode;
    Pa->next = NULL;
    for (int i = 1; i <= n; ++i)
    {
        s = new PNode;
        cin >> s->coef >> s->expn;
        pre = Pa;
        q = Pa->next;
        while (q && q->expn < s->expn)
        {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}
void CreatePolyn2(Polynomial &Pb, int n)
{
    Polynomial s, pre, q;
    Pb = new PNode;
    Pb->next = NULL;
    for (int i = 1; i <= n; ++i)
    {
        s = new PNode;
        cin >> s->coef >> s->expn;
        pre = Pb;
        q = Pb->next;
        while (q && q->expn < s->expn)
        {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}
void AddPolyn(Polynomial &Pa, Polynomial &Pb)
{
    Polynomial p1, p2, p3, r;
    float sum;
    p1 = Pa->next;
    p2 = Pb->next;
    p3 = Pa;
    while (p1 && p2)
    {
        if (p1->expn == p2->expn)
        {
            sum = p1->coef + p2->coef;
            if (sum != 0)
            {
                p1->coef = sum;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                r = p2;
                p2 = p2->next;
                delete r;
            }
            else
            {
                r = p1;
                p1 = p1->next;
                delete r;
                r = p2;
                p2 = p2->next;
                delete r;
            }
        }
        else if (p1->expn < p2->expn)
        {
            p2->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
    delete Pb;
}
void LessPolyn(Polynomial &Pa, Polynomial &Pb)
{
    Polynomial p1, p2, p3, r;
    float defference;
    p1 = Pa->next;
    p2 = Pb->next;
    p3 = Pa;
    while (p1 && p2)
    {
        if (p1->expn == p2->expn)
        {
            defference = p1->coef - p2->coef;
            if (defference != 0)
            {
                p1->coef = defference;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                r = p2;
                p2 = p2->next;
                delete r;
            }
            else
            {
                r = p1;
                p1 = p1->next;
                delete r;
                r = p2;
                p2 = p2->next;
                delete r;
            }
        }
        else if (p1->expn < p2->expn)
        {
            p2->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
    delete Pb;
}
int main(void)
{
    Polynomial Pa, Pb;
    cout << "������n:";
    int n;
    cin >> n;
    cout << "������һ������ʽ��ϵ�� ָ����" << endl;
    CreatePolyn1(Pa, n);
    cout << "�����ڶ�������ʽ��ϵ�� ָ����" << endl;
    CreatePolyn2(Pb, n);
    cout << "1.����ʽ���" << endl;
    cout << "2.����ʽ���" << endl;
    int s;
    cin >> s;
    switch (s)
    {
    case 1:
        AddPolyn(Pa, Pb);
        break;
    case 2:
        LessPolyn(Pa, Pb);
        break;
    default:
        break;
    }
    Polynomial p1 = Pa->next;
    for (int i = 0; i < n;)
    {
        cout << "(" << p1->coef << "x^" << p1->expn << ")";
        p1 = p1->next;
        i++;
        if (i < n)
        {
            cout << "+";
        }
    }
}