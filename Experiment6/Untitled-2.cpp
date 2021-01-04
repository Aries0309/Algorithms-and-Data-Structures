#include <iostream>
using namespace std;
#define MVNum 100 //��󶥵���
typedef char VerTexType;
typedef int OtherInfo;
typedef struct ArcNode
{                            //�߽��
    int adjvex;              //�ñ���ָ��Ķ����λ��
    OtherInfo info;          //�ͱ���ص���Ϣ
    struct ArcNode *nextarc; //ָ����һ���ߵ�ָ��
} ArcNode;
typedef struct VNode
{
    VerTexType data;     //������Ϣ
    ArcNode *firstarc;   //ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MVNum]; //AdjList��ʾ�ڽӱ�����
typedef struct
{
    AdjList vertices;   //�ڽӱ�
    int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͱ���
} ALGraph;
//ȷ��v��G��λ�ã���������G.vertices�е����
int LocateVex(ALGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == v)
            return i; //�ҵ�����λ��
    return -1;
}
//�����ڽӱ��ʾ������������ͼG
void CreateUDG(ALGraph &G)
{
    int i, j, k;
    VerTexType v1, v2;
    ArcNode *p1, *p2;
    cin >> G.vexnum >> G.arcnum; //�����ܶ��������ܱ���
    //������㣬�����ͷ����
    for (i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vertices[i].data;     //���붥��ֵ
        G.vertices[i].firstarc = NULL; //��ʼ����ͷ����ָ����ΪNULL
    }
    //������ߣ������ڽӱ�
    for (k = 0; k < G.arcnum; ++k)
    {
        cin >> v1 >> v2;      //����һ������������������
        i = LocateVex(G, v1); //ȷ��v1��G��λ�ã���������G.vertices�е����
        j = LocateVex(G, v2); //ȷ��v2��G��λ�ã���������G.vertices�е����
        p1 = new ArcNode;     //����һ���µı߽��*p1
        p1->adjvex = j;       //�ڽӵ����Ϊj
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1; //���½��*p1���붥��v[i]�ı߱�ͷ��
        p2 = new ArcNode;            //������һ���ԳƵ��µı߽��*p2
        p2->adjvex = i;              //�ڽӵ����Ϊi
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2; //���½��*p2���붥��v[j]�ı߱�ͷ��
    }
}
bool visited[MVNum]; //���ʱ�־����
//ͼGΪ�ڽӱ����ͣ��ӵ�V������������������������ͼG
void DFS_AL(ALGraph G, int v)
{
    ArcNode *p;
    int w;
    cout << G.vertices[v].data; //���ʵ�v������
    visited[v] = true;          //�÷��ʱ�־������Ӧ����ֵΪtrue
    p = G.vertices[v].firstarc; //pָ��v�ı�����ĵ�һ���߽��
    while (p != NULL)
    {
        w = p->adjvex; //��ʾw��v���ڽӵ�
        if (!visited[w])
            DFS_AL(G, w); //���wδ���ʣ���ݹ����DFS_AL
        p = p->nextarc;   //pָ����һ���߽��
    }
}
int main(void)
{
    ALGraph G;
    int v;
    CreateUDG(G);
    cout << "��ѡ����ʼ���㣺";
    cin >> v;
    DFS_AL(G, v);
}