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
    char text[80]; //�ı�
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
        file.open(filename + ".txt");
        file.close();
    }
    else
    {
        cout << "���������ļ���������ͬ" << endl;
        system("pause");
        Initialization();
    }
}
void Initialization(Livearealist &l)
{
    l = new Liveareanode;
    l->next = NULL;
}
void Initialization(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}
//����
void Insert(Livearealist &l)
{
    int line, count, i = 0;
    string text;
    char text1[80], text2[80], text3[80], text4[80];
    Livearealist l2, node;
    cin >> line >> text;
    if (line > 0 && line < activemaxlen)
    {
        l2 = l;
        for (int i = 0; l2->next && i < line; i++)
        {
            l2 = l2->next;
        }
        node = new Liveareanode;
        node->line = line + 1;
        Initialization(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str());
            Insert(node->content, text1);
        }
        node->next = l2->next;
        l2->next = node;
    }
}
void Insert(Contentlist &c, char text[])
{
    Contentlist c2 = c, node;
    while (c2->next)
    {
        c2 = c2->next;
    }
    node = new Contentnode;
    strcpy(node->text, text);
    node->next = c2->next;
    c2->next = node;
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
