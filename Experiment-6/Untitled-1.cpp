#include <iostream>
#include <queue>
using namespace std;
//����������ֱ�洢�������ڽӾ���
#define MaxInt 32767     //��ʾ����ֵ������
#define MVNum 100        //��󶥵���
typedef char VerTexType; //���趥�����������Ϊ�ַ���
typedef int ArcType;     //����ߵ�Ȩֵ����Ϊ����
typedef struct
{
    VerTexType vexs[MVNum];     //�����
    ArcType arcs[MVNum][MVNum]; //�ڽӾ���
    int vexnum, arcnum;         //ͼ�ĵ�ǰ�����ͱ���
} AMGraph;
//ȷ��v��G�е�λ�ã�������������±�
int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vexs[i] == v)
            return i; //�ҵ�����λ��
    return -1;
}
//�����ڽӾ����ʾ��������������G
void CreateUDN(AMGraph &G)
{
    int i, j, k;
    ArcType w;                   //�ߵ�Ȩֵ
    VerTexType v1, v2;           //����
    cin >> G.vexnum >> G.arcnum; //�����ܶ��������ܱ���
    //������������Ϣ
    for (i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i];
    //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt
    for (i = 0; i < G.vexnum; ++i)
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = MaxInt;
    //�����ڽӾ���
    for (k = 0; k < G.arcnum; ++k)
    {
        cin >> v1 >> v2 >> w;        //����һ���������Ķ��㼰Ȩֵ
        i = LocateVex(G, v1);        //ȷ��v1��G�е�λ�ã�������������±�
        j = LocateVex(G, v2);        //ȷ��v2��G�е�λ�ã�������������±�
        G.arcs[i][j] = w;            //��<v1,v2>��Ȩֵ��Ϊw
        G.arcs[j][i] = G.arcs[i][j]; //��<v1,v2>�ĶԳƱ�<v2,v1>��ȨֵΪw
    }
}
bool visited[MVNum]; //���ʱ�־����
//ͼGΪ�ڽӾ������ͣ��ӵ�v������������������������ͼG
void BFS_AM(AMGraph G, int v)
{
    int w, u;
    cout << G.vexs[v]; //���ʵ�v������
    visited[v] = true; //�÷��ʱ�־������Ӧ����ֵΪtrue
    queue<int> q;      //���帨������q
    q.push(v);         //v����
    //���зǿ�
    while (!q.empty())
    {
        u = q.front(); //��ȡ��ͷԪ��
        q.pop();       //��ͷԪ�س���
        //�����ڽӾ���u���ڵ���
        for (w = 0; w < G.vexnum; w++)
            //G.arcs[u][w] != MaxInt��ʾw��u���ڽӵ㣬���wδ���ʣ������
            if ((G.arcs[u][w] != MaxInt) && (!visited[w]))
            {
                cout << G.vexs[w]; //����w
                visited[w] = true; //�÷��ʱ�־������Ӧ����ֵΪtrue
                q.push(w);         //w����
            }
    }
}
int main(void)
{
    AMGraph G;
    int v;
    CreateUDN(G);
    cout << "��ѡ����ʼ���㣺";
    cin >> v;
    BFS_AM(G, v);
}