#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
#define activemaxlen 100
#define x 20
string inputfilename, outputfilename; //�ļ���
int count = 0;
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
//������ʼ��
void Inilivearea(Livearealist &l)
{
    l = new Liveareanode;
    l->next = NULL;
}
//���ݳ�ʼ��
void Inicontent(Contentlist &c)
{
    c = new Contentnode;
    c->next = NULL;
}
//���ݲ���
void Insert(Contentlist &c, char text[])
{
    Contentlist c1 = c, node;
    for (c1 = c; c1->next; c1 = c1->next)
        ;
    node = new Contentnode;
    strcpy(node->text, text);
    node->next = c1->next;
    c1->next = node;
}
//��ʼ��
void Initialization(Livearealist &l)
{
    char buffer[320], text1[81];
    string text;
    fstream inputfile, outputfile;
    cout << "�����롰�����ļ����ļ����������ޣ����ÿո��ʾ��";
    cin >> inputfilename;
    cout << "�����롰����ļ����ļ�����";
    cin >> outputfilename;
    if (inputfilename != outputfilename)
    {
        if (inputfilename == " ")
        {
            outputfile.open(outputfilename + ".txt"); //���ļ�
            outputfile.close();                       //�ر��ļ�
        }
        else
        {
            inputfile.open(inputfilename + ".txt", ios::_Nocreate); //���ļ�
            Livearealist l1, node;
            l1 = l;
            for (int i = 0; i < activemaxlen - x; i++)
            {
                node = new Liveareanode;
                node->line = i + 1;
                Inicontent(node->content);
                inputfile.getline(buffer, 320);
                count++;
                text = (string)buffer;
                for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
                {
                    strcpy(text1, text.substr(j, k).c_str()); //�ָ��ַ���
                    Insert(node->content, text1);
                }
                node->next = l1->next;
                l1->next = node;
                l1 = l1->next;
                if (inputfile.eof())
                {
                    break;
                }
            }
            inputfile.close();                        //�ر��ļ�
            outputfile.open(outputfilename + ".txt"); //���ļ�
            outputfile.close();                       //�ر��ļ�
        }
    }
    else
    {
        cout << "���������ļ���������ͬ" << endl;
        system("pause");
        Initialization(l);
    }
}
//����
void Insert(Livearealist &l)
{
    int line;
    string text;
    char text1[81];
    Livearealist l1, node;
    cin >> line >> text;
    //�к��ڻ�����Χ��
    if (line >= 0 && line < activemaxlen)
    {
        l1 = l;
        //���ҵ�i�����
        for (int i = 0; l1->next && i < line; i++, l1 = l1->next)
            ;
        node = new Liveareanode;
        node->line = line + 1;
        Inicontent(node->content);
        for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
        {
            strcpy(text1, text.substr(j, k).c_str()); //�ָ��ַ���
            Insert(node->content, text1);
        }
        node->next = l1->next;
        l1->next = node;
        l1 = l1->next;
        //�޸ĺ����к�
        for (l1 = l1->next; l1->next; l1 = l1->next, l1->line = l1->line + 1)
            ;
    }
    else if (line == 0)
    {
        l1 = l;
    }
}
//ɾ��
void Delete(Livearealist &l)
{
    int line1, line2 = 0;
    char space;
    Livearealist l1, l2, node1, node2;
    cin >> line1 >> space;
    //�жϸ�ʽ
    if (space == ' ')
    {
        cin >> line2;
    }
    if (line2 == 0)
    {
        l1 = l;
        for (int i = 0; l1->next && i < line1 - 1; i++, l1 = l1->next)
            ;
        node1 = l1->next;
        l1->next = node1->next;
        delete node1;
    }
    else
    {
        l1 = l;
        for (int i = 0; l1->next && i < line1 - 1; i++, l1 = l1->next)
            ;
        l2 = l1;
        for (int i = line1; l2->next && i < line2; i++, l2 = l2->next)
            ;
        for (node1 = l1->next; node1 != l2; node1 = node2)
        {
            node2 = node1->next;
            delete node1;
        }
        l1->next = l2->next;
        delete l2;
    }
    //�޸��к�
    for (l1 = l1->next; l1; l1 = l1->next)
    {
        l1->line = ++line1;
    }
}
//�����л�
void Switch(Livearealist &l)
{
    fstream inputfile, outputfile;
    Livearealist l1, node;
    l1 = l;
    outputfile.open(outputfilename + ".txt", ios::app);
    if (outputfile.is_open())
    {
        while (l1)
        {
            while (l1->content)
            {
                outputfile << l1->content->text;
                l1->content = l1->content->next;
            }
            outputfile << endl;
            node = l1;
            l1 = l1->next;
            delete node;
        }
    }
    outputfile.close();
    if (inputfilename != " ")
    {
        char buffer[320], text1[81];
        string text;
        inputfile.open(inputfilename + ".txt", ios::_Nocreate); //���ļ�
        Livearealist l1, node;
        l1 = l;
        for (int i = 0; i < activemaxlen - x; i++)
        {
            node = new Liveareanode;
            node->line = i + 1;
            Inicontent(node->content);
            inputfile.getline(buffer, 320);
            text = (string)buffer;
            for (int i = text.length(), j = 0, k = 80; i; i /= 80, j += 80, k += 80)
            {
                strcpy(text1, text.substr(j, k).c_str()); //�ָ��ַ���
                Insert(node->content, text1);
            }
            node->next = l1->next;
            l1->next = node;
            l1 = l1->next;
        }
        inputfile.close(); //�ر��ļ�
    }
}
int main(void)
{
    char cmd;
    Livearealist l;
    Inilivearea(l);
    Initialization(l);
    while (1)
    {
        cin >> cmd;
        switch (cmd)
        {
        case 'i':
            Insert(l);
            break;
        case 'd':
            Delete(l);
            break;
        case 'n':
            Switch(l);
            break;
        default:
            break;
        }
    }
}
