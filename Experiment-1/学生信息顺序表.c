/*����һ������ѧ����Ϣ��ѧ�ţ��������ɼ�����˳���ʹ��������¹��ܣ�
(1) ����ָ��ѧ���������������ѧ����Ϣ��
(2) �����ʾѧ����������ѧ���������Ϣ��
(3) �����������в��ң����ش�ѧ����ѧ�źͳɼ���
(4) ����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ����� 
(5) ����һ��ѧ����Ϣ�����뵽����ָ����λ�ã� 
(6) ɾ��ָ��λ�õ�ѧ����¼��
(7) ͳ�Ʊ���ѧ��������
*/
#include <stdio.h>
#include <string.h>
typedef struct
{
    char no[8];    //8λѧ��
    char name[20]; //����
    int price;     //�ɼ�
} Student;
int main(void)
{
    int n, i;
    puts("������ѧ��������");
    scanf("%d", &n);
    puts("������ѧ����Ϣ��");
    Student stu[10000];
    for (i = 0; i < n; i++)
        scanf("%s %s %d", stu[i].no, stu[i].name, &stu[i].price);
    while (1)
    {
        puts("1.�����ʾѧ����������ѧ���������Ϣ");
        puts("2.������������ѧ����ѧ�źͳɼ�");
        puts("3.����ָ��λ�õ�ѧ����Ϣ");
        puts("4.����һ��ѧ����Ϣ�����뵽ָ��λ��");
        puts("5.ɾ��ָ��λ�õ�ѧ����¼");
        puts("6.ͳ�Ʊ���ѧ������");
        puts("7.�˳�");
        int s;
        scanf("%d", &s);
        char newno[8];
        char newname[20];
        int newprice;
        char name[20];
        int a;
        if (s == 7)
            break;
        switch (s)
        {
        case 1:
            for (i = 0; i < n; i++)
                printf("%s %s %d\n", stu[i].no, stu[i].name, stu[i].price); //�����ʾѧ����������ѧ���������Ϣ
            puts("���س�������");
            getchar();
            getchar();
            break;
        case 2:
            for (i = 0; i < n; i++)
                if (stu[i].name == name)
                    printf("%s %d\n", stu[i].no, stu[i].price); //������������ѧ����ѧ�źͳɼ�
            puts("���س�������");
            getchar();
            getchar();
            break;
        case 3:
            puts("������Ҫ���ҵ�������");
            scanf("%s", &newname);
            for (i = 0; i < n; i++)
                if (!(strcmp(newname, stu[i].name)))
                    printf("%s %s %d\n", stu[i].no, stu[i].name, stu[i].price); //����ָ��λ�õ�ѧ����Ϣ
            puts("���س�������");
            getchar();
            getchar();
            break;
        case 4:
            puts("������ѧ����Ϣ��");
            scanf("%s %s %d", newno, newname, &newprice);
            puts("��ָ������λ�ã�");
            scanf("%d", &a);
            if (!(a < n && a >= 0))
            {
                puts("�������ִ���");
                break;
            }
            for (i = n; i > a; i--)
                stu[i] = stu[i - 1];
            for (int j = 0; j < 8; j++)
                stu[a].no[j] = newno[j];
            for (int j = 0; j < 20; j++)
                stu[a].name[j] = newname[j];
            stu[a].price = newprice;
            n++;
            puts("OK!\n"); //����һ��ѧ����Ϣ�����뵽ָ��λ��
            puts("���س�������");
            getchar();
            getchar();
            break;
        case 5:
            puts("��������Ҫɾ����ѧ����Ϣ��");
            scanf("%d", &a);
            if (!(a < n && a >= 0))
            {
                puts("�������ִ���");
                break;
            }
            for (i = a; i < n - 1; i++)
                stu[i] = stu[i + 1];
            n--;
            puts("OK!\n"); //ɾ��ָ��λ�õ�ѧ����¼
            puts("���س�������");
            getchar();
            getchar();
            break;
        case 6:
            printf("����%d��ѧ��\n", n); //ͳ�Ʊ���ѧ������
            puts("���س�������");
            getchar();
            getchar();
            break;
        default:
            puts("������Ч������������\n");
            puts("���س�������");
            getchar();
            getchar();
            break;
        }
    }
}