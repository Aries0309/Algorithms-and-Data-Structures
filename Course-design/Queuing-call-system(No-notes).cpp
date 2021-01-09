#include <iostream>
using namespace std;
int number = 0;
int state[7] = {-1, -1, -1, -1, -1, -1, -1};
typedef struct QNode
{
    int Number;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void InitQueue(LinkQueue &q)
{
    q.front = q.rear = new QNode;
    q.front->next = NULL;
}

void EnQueue(LinkQueue &q)
{
    QueuePtr p = new QNode;
    p->Number = ++number;
    p->next = NULL;
    q.rear->next = p;
    q.rear = p;
}

void GetHead(LinkQueue q, int vip)
{
    int i;
    if (q.front != q.rear)
    {
        if (vip == 0)
        {
            for (i = 1; i <= 4; i++)
            {
                if (state[i] == -1)
                {
                    break;
                }
            }
            if (i <= 4)
            {
                cout << "��" << q.front->next->Number << "�ŵ�" << i << "�Ŵ��ڰ���ҵ��" << endl;
            }
            else
            {
                cout << "��ͨ�������޿���" << endl;
            }
        }
        else
        {
            for (i = 5; i <= 6; i++)
            {
                if (state[i] == -1)
                {
                    break;
                }
            }
            if (i <= 6)
            {
                cout << "��" << q.front->next->Number << "�ŵ�" << i << "�Ŵ��ڰ���ҵ��" << endl;
            }
            else
            {
                cout << "VIP�������޿���" << endl;
            }
        }
    }
    else
    {
        cout << "�����Ŷ�" << endl;
    }
}

void DeQueue(LinkQueue &q, int window)
{
    if (state[window] != -1)
    {
        cout << "��ǰ�������ڰ���ҵ��" << endl;
        return;
    }
    if (q.front == q.rear)
    {
        state[window] = 0;
        cout << "��ʼ����ҵ��" << endl;
        return;
    }
    QueuePtr p = q.front->next;
    state[window] = p->Number;
    q.front->next = p->next;
    if (q.rear == p)
    {
        q.rear = q.front;
    }
    delete p;
    cout << "��ʼ����ҵ��" << endl;
}
void DeQueue(LinkQueue &q)
{
    if (q.front == q.rear)
    {
        return;
    }
    QueuePtr p = q.front->next;
    cout << "������" << p->Number << "��" << endl;
    q.front->next = p->next;
    if (q.rear == p)
    {
        q.rear = q.front;
    }
    delete p;
}

void Window(int e)
{
    if (e == -1)
    {
        cout << "�ô��ڿ���" << endl;
    }
    else if (e == 0)
    {
        cout << "�ô������ڰ���ҵ�񣬵��˿�û��ȡ��" << endl;
    }
    else
    {
        cout << e << "�����ڰ���ҵ��" << endl;
    }
}
void Window()
{
    for (int i = 1; i < 7; i++)
    {
        if (state[i] == -1)
        {
            cout << i << "�Ŵ��ڿ���" << endl;
        }
        else if (state[i] == 0)
        {
            cout << i << "�Ŵ�����δȡ�Ź˿����ڰ���ҵ��" << endl;
        }
        else
        {
            cout << state[i] << "�Ź˿�����" << i << "�Ŵ��ڰ���ҵ��" << endl;
        }
    }
}

void Queuing(LinkQueue q)
{
    int count = 0;
    QueuePtr p = q.front->next;
    while (p)
    {
        count++;
        p = p->next;
    }
    cout << "��ǰ��" << count << "�˵ȴ�" << endl;
}

void Finish(int e)
{
    state[e] = -1;
    cout << e << "�Ŵ��ڰ������" << endl;
}
int main(void)
{
    LinkQueue q, vipq;
    InitQueue(q);
    InitQueue(vipq);
    while (1)
    {
        int option;
        cout << "1.�Ŷ�ȡ��" << endl;
        cout << "2.�к�" << endl;
        cout << "3.����ҵ��" << endl;
        cout << "4.����״̬" << endl;
        cout << "5.�Ŷ�״̬" << endl;
        cout << "6.�������" << endl;
        // cout << "7.����һ��" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "1.��ͨ�ͻ�" << endl;
            cout << "2.VIP�ͻ�" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                EnQueue(q);
                break;
            case 2:
                EnQueue(vipq);
                break;
            default:
                break;
            }
            cout << "ȡ�ųɹ�" << endl;
            system("pause");
            break;
        case 2:
            cout << "1.��ͨ����" << endl;
            cout << "2.VIP����" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                GetHead(q, 0);
                break;
            case 2:
                GetHead(vipq, 1);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 3:
            cout << "1.��ͨ����1" << endl;
            cout << "2.��ͨ����2" << endl;
            cout << "3.��ͨ����3" << endl;
            cout << "4.��ͨ����4" << endl;
            cout << "5.VIP����1" << endl;
            cout << "6.VIP����2" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
            case 2:
            case 3:
            case 4:
                DeQueue(q, option);
                break;
            case 5:
            case 6:
                DeQueue(vipq, option);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 4:
            cout << "1.��ͨ����1" << endl;
            cout << "2.��ͨ����2" << endl;
            cout << "3.��ͨ����3" << endl;
            cout << "4.��ͨ����4" << endl;
            cout << "5.VIP����1" << endl;
            cout << "6.VIP����2" << endl;
            cin >> option;
            Window(state[option]);
            // Window();
            system("pause");
            break;
        case 5:
            cout << "1.��ͨ�ͻ�����" << endl;
            cout << "2.VIP�ͻ�����" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                Queuing(q);
                break;
            case 2:
                Queuing(vipq);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 6:
            cout << "1.��ͨ����1" << endl;
            cout << "2.��ͨ����2" << endl;
            cout << "3.��ͨ����3" << endl;
            cout << "4.��ͨ����4" << endl;
            cout << "5.VIP����1" << endl;
            cout << "6.VIP����2" << endl;
            cin >> option;
            Finish(option);
            system("pause");
            break;
        // case 7:
        //     cout << "1.��ͨ�ͻ�����" << endl;
        //     cout << "2.VIP�ͻ�����" << endl;
        //     cin >> option;
        //     switch (option)
        //     {
        //     case 1:
        //         DeQueue(q);
        //         break;
        //     case 2:
        //         DeQueue(vipq);
        //         break;
        //     default:
        //         break;
        //     }
        //     system("pause");
        //     break;
        default:
            break;
        }
    }
}