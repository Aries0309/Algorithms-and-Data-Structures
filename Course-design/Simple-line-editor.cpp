#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define activemaxlen 100
string filename; //�ļ���
//���ݵ�����
typedef struct Content
{
    char text[81]; //�ı�
    struct Content *next;
} Contentnode, *Contentlist;
//����������
typedef struct Livearea
{
    int line;            //�к�
    Contentlist content; //����
    struct Livearea *next;
} Liveareanode, *Livearealist;
//��ʼ��
void Initialization()
{
    ofstream file, outputfile;
    cout << "�������ļ�����";
    cin >> filename;
    if (filename != "")
    {
        file.open(filename + ".txt"); //���ļ�
        file.close();                 //�ر��ļ�
    }
    else
    {
        cout << "�ļ�������Ϊ��" << endl;
        system("pause");
        Initialization();
    }
}
//������ʼ��
void Initialization(Livearealist &l)
{
    l = new Liveareanode;
    l->next = NULL;
}
//���ݳ�ʼ��
void Initialization(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}
//����
void Insert(Contentlist &c,char text[])
{
    Contentlist c1 = c, node;
    while (c1->next)
    {
        c1 = c1->next;
    }
    node = new Contentnode;
    strcpy(node->text, text);
    node->next = c1->next;
    c1->next = node;
}
void Insert(Livearealist &l)
{
    int line, count, i = 0;
    string text;
    char text1[81];
    Livearealist l1, node;
    cin >> line >> text;
    //�к��ڻ�����Χ��
    if (line > 0 && line < activemaxlen)
    {
        l1 = l;
        //���ҵ�i�����
        for (int i = 0; l1->next && i < line; i++)
        {
            l1 = l1->next;
        }
        node = new Liveareanode;
        node->line = line + 1;
        Initialization(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str()); //�ָ��ַ���
            Insert(node->content,text1);
        }
        node->next = l1->next;
        l1->next = node;
    }
}
int main(void)
{
    char cmd;
    Initialization();
    Livearealist l;
    Initialization(l);
    cin >> cmd;
    switch (cmd)
    {
    case 'i':
        Insert(l);
        break;

    default:
        break;
    }
}
