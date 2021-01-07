#include <iostream>
using namespace std;
int number = 0; //�ŶӺ���
typedef struct QNode
{
    int Number;         //����
    struct QNode *next; //���ָ��
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr front; //��ͷָ��
    QueuePtr rear;  //��βָ��
} LinkQueue;
//��ʼ��
void InitQueue(LinkQueue &q)
{
    q.front = q.rear = new QNode; //�����½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽��
    q.front->next = NULL;         //ͷָ���ָ�����ÿ�
}
//�Ŷ�
void EnQueue(LinkQueue &q)
{
    QueuePtr p = new QNode; //Ϊ���Ԫ�ط�����ռ䣬��ָ��pָ��
    p->Number = ++number;   //ȡ��
    p->next = NULL;
    q.rear->next = p; //�Ŷ�
    q.rear = p;       //�޸Ķ�βָ��
}
//�к�
void GetHead(LinkQueue q)
{
    if (q.front != q.rear)
    {
        cout << q.front->next->Number << endl;
    }
    else
    {
        cout << "�����Ŷ�" << endl;
    }
}
//����
void DeQueue(LinkQueue &q)
{
    if (q.front == q.rear)
    {
        cout << "�����Ŷ�" << endl;
        return;
    }
    QueuePtr p = q.front->next; //pָ���ͷԪ��
    q.front->next = p->next;    //�޸�ͷ����ָ����
    if (q.rear == p)
    {
        q.rear = q.front; //���һ��Ԫ�ر�ɾ����βָ��ָ��ͷ���
    }
    delete p; //�ͷſռ�
}
int main(void)
{
    LinkQueue q, vipq; //��ͨ���У�VIP����
    InitQueue(q);
    InitQueue(vipq);
    while (1)
    {
        int option;
        cout << "1.�Ŷ�ȡ��" << endl;
        cout << "2.�к�" << endl;
        cout << "3.����ҵ��" << endl;
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
            cout << "���ڽк�" << endl;
            switch (option)
            {
            case 1:
                GetHead(q);
                break;
            case 2:
                GetHead(vipq);
                break;
            default:
                break;
            }
            system("pause");
            break;
        case 3:
            cout << "1.��ͨ����" << endl;
            cout << "2.VIP����" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                DeQueue(q);
                break;
            case 2:
                DeQueue(vipq);
                break;
            default:
                break;
            }
            cout << "���ڰ���ҵ��" << endl;
            system("pause");
        default:
            break;
        }
    }
}