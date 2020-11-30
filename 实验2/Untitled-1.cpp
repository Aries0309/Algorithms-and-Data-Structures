/* ����һ������ѧ����Ϣ��ѧ�ţ��������ɼ����ĵ�����ʹ��������¹��ܣ�
(1)����ָ��ѧ���������������ѧ����Ϣ��
(2) �����ʾѧ����������ѧ���������Ϣ��
(3) �����������в��ң����ش�ѧ����ѧ�źͳɼ���
(4) ����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ�����
(5) ����һ��ѧ����Ϣ�����뵽����ָ����λ�ã�
(6) ɾ��ָ��λ�õ�ѧ����¼��
(7) ͳ�Ʊ���ѧ��������
 */
#include <iostream>
#include <string.h>
using namespace std;
typedef struct
{
    long no;       //ѧ��
    char name[20]; //����
    int price;     //�ɼ�
} Student;
typedef struct LNode
{
    Student data;
    struct LNode *next;
} LNode, *LinkList;
void CreateList_L(LinkList &L, int n) //C++�������õ�һ�ַ�ʽ������ʹ��C++
{
    L = new LNode;  //ͷ���
    L->next = NULL; //ͷָ��
    LinkList p;
    for (int i = n; i > 0; --i)
    {
        p = new LNode;
        p->next = L->next;
        L->next = p;
    }
}
void InputList_L(LinkList L, Student e, int i)
{
    LinkList p;
    int j;
    p = L->next;
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }
    p->data = e;
    p = p->next;
}
void PrintList_L(LinkList &L)
{
    LinkList p = L->next;
    while (p)
    {
        cout << p->data.no << " " << p->data.name << " " << p->data.price << endl;
        p = p->next;
    }
}
Student NameSearchList_L(LinkList L, char name[20])
{
    LinkList p;
    p = L->next;
    while (p)
    {
        if (strcmp(p->data.name, name) == 0)
        {
            return p->data;
        }
        else
            p = p->next;
    }
}
Student PositionSearchList_L(LinkList L, int position)
{
    LinkList p;
    p = L->next;
    for (int i = 1; i != position; i++)
    {
        p = p->next;
    }
    return p->data;
}
int InsertList_L(LinkList &L, int i, Student e)
{
    LinkList s, p;
    int j;
    p = L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p && j > i)
    {
        return 0;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}
int DeleteList_L(LinkList &L, int i)
{
    LinkList p, q;
    int j;
    p = L;
    for (j = 1; p && j < i; j++)
    {
        p = p->next;
    }
    if (!(p) || j > i)
    {
        return 0;
    }
    q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}
int main(void)
{
    LinkList L;
    int n;
    cout << "������ѧ������" << endl;
    cin >> n;
    CreateList_L(L, n);
    cout << "������ѧ����Ϣ��ѧ�� ���� �ɼ���" << endl;
    Student stu;
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> stu.no >> stu.name >> stu.price;
        InputList_L(L, stu, i);
    }
    while (1)
    {
        int flag = 0;
        cout << "1.�����ʾѧ����������ѧ���������Ϣ" << endl;
        cout << "2.������������ѧ����ѧ�źͳɼ�" << endl;
        cout << "3.����ָ����λ����ʾ��Ӧ��ѧ����Ϣ" << endl;
        cout << "4.����һ��ѧ����Ϣ�����뵽����ָ����λ��" << endl;
        cout << "5.ɾ��ָ��λ�õ�ѧ����Ϣ" << endl;
        cout << "6.ͳ�Ʊ���ѧ������" << endl;
        cout << "0.�˳�" << endl;
        cin >> flag;
        switch (flag)
        {
        case 1:
            PrintList_L(L);
            cout << "���¿ո������";
            getchar();
            getchar();
            break;
        case 2:
            char name[20];
            cin >> name;
            stu = NameSearchList_L(L, name);
            if (stu.no)
            {
                cout << stu.no << " " << stu.price << endl;
            }
            else
            {
                cout << "δ�ҵ�" << endl;
            }
            cout << "���¿ո������";
            getchar();
            getchar();
            break;
        case 3:
            cin >> i;
            stu = PositionSearchList_L(L, i);
            if (stu.no)
            {
                cout << stu.no << " " << stu.name << " " << stu.price << endl;
            }
            else
            {
                cout << "δ�ҵ�" << endl;
            }
            cout << "���¿ո������";
            getchar();
            getchar();
            break;
        case 4:
            cin >> i;
            cin >> stu.no >> stu.name >> stu.price;
            if (InsertList_L(L, i, stu))
            {
                n++;
                cout << "����ɹ�" << endl;
            }
            else
            {
                cout << "����ʧ��" << endl;
            }
            cout << "���¿ո������";
            getchar();
            getchar();
            break;
        case 5:
            cin >> i;
            if (DeleteList_L(L, i))
            {
                n--;
                cout << "ɾ���ɹ�" << endl;
            }
            else
            {
                cout << "ɾ��ʧ��" << endl;
            }
            cout << "���¿ո������";
            getchar();
            getchar();
            break;
        case 6:
            cout << "����" << n << "��ѧ��" << endl;
            cout << "���¿ո������";
            getchar();
            getchar();
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }
}