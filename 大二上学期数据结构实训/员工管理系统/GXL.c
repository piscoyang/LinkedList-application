#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //��������ͷ�ļ�
#include <string.h>
struct Stuff
{
    char number[10]; //Ա�����
    char name[10]; //Ա������
    char sex[8]; //Ա���Ա�
    char borth[10]; //Ա������
    char degree[20]; //Ա��ѧ��
    char business[20]; //Ա��ְ��
    char phone[15]; //Ա���绰
    char place[50]; //Ա��סַ
    char con[50]; //�жϹؼ���ר��
    struct Stuff* next;
};

char Menu(void); //�˵���ʾ
struct Stuff* App(struct Stuff* head); //���
void Sort(struct Stuff* head); //����
struct Stuff* Ser(struct Stuff* head); //����
void Chn(struct Stuff* head, char n[10]); //����
void Scpy(char* p, char* q); //���������ڽ���Ա����Ϣ
struct Stuff* Del(struct Stuff* head, char n[10]); //ɾ��
int Sel(char ch, struct Stuff* p, struct Stuff* q); //�ж����򼰹ؼ���ר�ú���
void Prf(struct Stuff* head); //���
void Fre(struct Stuff* head); //�ͷ�
void tongbu(struct Stuff* head);
int i = 1; //����ȫ�ֱ�����ʵ��ʵʱԱ������ͳ��

int main(void)
{
    char n[10];
    struct Stuff* head = (Stuff*)malloc(sizeof(Stuff)); //����ͷָ�붨��
    Stuff* q, * p = head;
    char number1[10]; //Ա�����
    char name1[50]; //Ա������
    char sex1[8]; //Ա���Ա�
    char borth1[50]; //Ա������
    char degree1[50]; //Ա��ѧ��
    char business1[50]; //Ա��ְ��
    char phone1[50]; //Ա���绰
    char place1[50]; //Ա��סַ
    char con1[50]; //�жϹؼ���ר��
    FILE* fp=fopen("data.txt","r");
    if (fp == NULL)
    {
        printf("���ļ�ʧ��!");
        exit(0);
    }
    while (fscanf(fp, "%s %s %s %s %s %s %s %s", number1, name1, sex1, borth1, degree1, business1, phone1, place1) != EOF)
    {
        q = (Stuff*)malloc(sizeof(Stuff));
        strcpy(q->number, number1);
        strcpy(q->name, name1);
        strcpy(q->sex, sex1);
        strcpy(q->borth, borth1);
        strcpy(q->degree, degree1);
        strcpy(q->business, business1);
        strcpy(q->phone, phone1);
        strcpy(q->place, place1);
        p->next = q;
        p = q;
    }
    p->next = NULL;
    fclose(fp);
    p = head->next;
    head = head->next;
    while (1)
    {
        switch (Menu())
        {
        case '1':
            printf("������Ա����Ϣ��ֱ������'#'����\n");
            head = App(head); tongbu(head);
            break;
        case '2':
            Sort(head);
            break;
        case '3':
            head = Ser(head);
            break;
        case '4':
            printf("Ա����Ϣ����:\n");
            Prf(head);
            break;
        case '5':
            printf("������Ա�����:");
            scanf("%s", n);
            Chn(head, n);
            break;
        case '6':
            printf("������Ա�����:");
            scanf("%s", n);
            head = Del(head, n); tongbu(head);
            break;
        case '0':
            printf("��ӭ�´ι��٣�88!\n");
            exit(0);
        default:
            printf("�����������������!\n");
        }
        fflush(stdin); //���������
        printf("�����������~");
        getchar();
        system("cls"); //����Ч��
    }
    Fre(head);

    return 0;
}
void tongbu(struct Stuff* head) {
    FILE* fp = fopen("data.txt", "w");
    if (!fp) {
        exit(0);
    }
    while (head)
    {
        fprintf(fp, "%s %s %s %s %s %s %s %s", head->number, head->name, head->sex, head->borth, head->degree, head->business, head->phone, head->place);
        head = head->next;
    }
    fclose(fp);
}
//�˵�����
char Menu(void)
{
    char ch;
    printf("------------��ѡ��-----------\n");
    printf("1.���Ա����Ϣ\n2.Ա����Ϣ����\n3.����Ա����Ϣ\n4.���Ա����Ϣ\n5.����Ա����Ϣ\n6.ɾ��Ա����Ϣ\n0.�˳�\n-----------------------------\n");
    scanf(" %c", &ch);
    return ch;
}
//��ӳ�Ա����
//�������:����ͷָ��
//���ز���:����ͷָ��
struct Stuff* App(struct Stuff* head)
{
    struct Stuff* p = NULL, * q = head;
    while (i)
    {
        p = (struct Stuff*)malloc(sizeof(struct Stuff)); //����ṹ��ռ�
        if (p == NULL)
        {
            printf("�ڴ治��!\n");
            exit(0);
        }
        p->next = NULL; //ָ����Ϊ��
        printf("�������%d��Ա��:\n", i);
        printf(" ��� | ���� | �Ա� | �������� | ѧ�� | ְ�� | �绰 | סַ :\n");
        fflush(stdin);
        scanf("%s", p->number);
        if (!strcmp(p->number, "#"))
        {
            free(p); //�ͷŲ���Ҫ�Ľṹ���ڴ�
            break;
        }
        else
        {
            ++i;
            scanf("%s%s%s%s%s%s%s", p->name, p->sex, p->borth, p->degree, p->business, p->phone, p->place);
            p->con[0] = '\0'; //��ֹ�����жϳ������ֵ
            if (head == NULL)
                head = p;
            else
            {
                while (q->next != NULL) //��ֹ�������ٴ�����ʱ��������
                    q = q->next;
                q->next = p;
            }
            q = p; //ÿ�ζ���������β
        }
    }
    return head;
}

//������
//�������:ͷָ��
void Sort(struct Stuff* head)
{
    char ch;
    struct Stuff* p, * q, * r;
    while (1)
    {
        printf("��ѡ����������:1.���2.����3.�Ա�4.��������5.ѧ��6.ְ��7.�绰8.��ַ0.�˳�\n");
        scanf(" %c", &ch);
        if (ch == '0')
            break;
        if (ch < '1' || ch>'8')
        {
            printf("�����������������!\n");
            continue;
        }
        p = head;
        while (p->next != NULL) //ѡ������
        {
            q = p->next;
            r = p;
            while (q != NULL)
            {
                if (Sel(ch, r, q)) //�����жϺ���
                    r = q;
                q = q->next;
            }
            if (r != p) //��������
            {
                Scpy(r->number, p->number);
                Scpy(r->name, p->name);
                Scpy(r->sex, p->sex);
                Scpy(r->borth, p->borth);
                Scpy(r->degree, p->degree);
                Scpy(r->business, p->business);
                Scpy(r->phone, p->phone);
                Scpy(r->place, p->place);
            }
            p = p->next;
        }
        Prf(head); //���
    }
}

//��������
void Scpy(char* p, char* q)
{
    char c[50];
    strcpy(c, p);
    strcpy(p, q);
    strcpy(q, c);
}

//�жϺ���
//�������:1Ϊ�棬0Ϊ��
int Sel(char ch, struct Stuff* p, struct Stuff* q)
{
    switch (ch) //ʵ�ָ����ؼ��ֲ���
    {
    case '1':
        return strcmp(q->number, p->number) < 0 || strcmp(q->con, p->number) == 0; //������������������
    case '2':
        return strcmp(q->name, p->name) < 0 || strcmp(q->con, p->name) == 0;
    case '3':
        return strcmp(q->sex, p->sex) < 0 || strcmp(q->con, p->sex) == 0;
    case '4':
        return strcmp(q->borth, p->borth) < 0 || strcmp(q->con, p->borth) == 0;
    case '5':
        return strcmp(q->degree, p->degree) < 0 || strcmp(q->con, p->degree) == 0;
    case '6':
        return strcmp(q->business, p->business) < 0 || strcmp(q->con, p->business) == 0;
    case '7':
        return strcmp(q->phone, p->phone) < 0 || strcmp(q->con, p->phone) == 0;
    case '8':
        return strcmp(q->place, p->place) < 0 || strcmp(q->con, p->place) == 0;
    default:
        exit(0);
    }
}

//���Һ���
struct Stuff* Ser(struct Stuff* head)
{
    struct Stuff* p = NULL, * q, a = { "\0","\0","\0","\0","\0","\0","\0","\0" }; //��ֹ�ж�ʱ����
    int flag; //�����ж�
    char ch, sh;
    q = &a;
    while (1)
    {
        printf("������Ҫ���ҵ�����:1.���2.����3.�Ա�4.��������5.ѧ��6.ְ��7.�绰8.סַ0.�˳�\n");
        scanf(" %c", &ch);
        if (ch == '0')
            break;
        if (ch < '1' || ch>'8')
        {
            printf("�����������������!\n");
            continue;
        }
        fflush(stdin);
        printf("������:");
        scanf("%s", q->con);
        p = head; //ָ���ͷ
        flag = 0;
        while (p != NULL)
        {
            if (Sel(ch, p, q))
            {
                printf("Ա����Ϣ����:\n");
                printf(" ��� | ���� | �Ա� | �������� | ѧ�� | ְ�� | �绰 | סַ \n%s %s %s %s %s %s %s %s\n"
                    , p->number, p->name, p->sex, p->borth, p->degree, p->business, p->phone, p->place);
                printf("�Ƿ���Ҫ:1.���� 2.ɾ�� 3.����\n");
                scanf(" %c", &sh);
                if (sh == '1')
                    Chn(head, p->number); //���ø��ĺ���
                else if (sh == '2')
                    head = Del(head, p->number); //����ɾ���������õ���head����return
                flag = 1;
                break;
            }
            p = p->next;
        }
        if (flag == 0)
            printf("û���ҵ���Ա����Ϣ!\n");
    }
    return head;
}

//���ĺ���
//�������:n[10] ΪԱ�����
void Chn(struct Stuff* head, char n[10])
{
    struct Stuff* p = head;
    int flag = 0;
    if (head == NULL)
        printf("δ�ҵ�Ա����Ϣ!\n");
    else
    {
        while (p != NULL)
        {
            if (!strcmp(p->number, n))
            {
                printf("�������µ���Ϣ:\n���|����|�Ա�|��������|ѧ��|ְ��|�绰|סַ\n");
                scanf("%s%s%s%s%s%s%s%s", p->number, p->name, p->sex, p->borth, p->degree, p->business, p->phone, p->place);
                printf("Ա����Ϣ����:\n");
                flag++;
                break;
            }
            p = p->next;
        }
        if (flag == 0)
            printf("δ�ҵ���Ա����Ϣ!\n");
    }
    Prf(head);
}

//ɾ������
//�������:nΪԱ�����
//�������:ͷָ��
struct Stuff* Del(struct Stuff* head, char n[10])
{

    struct Stuff* p, * pr;
    int flag;
    flag = 0;
    p = head, pr = head;
    if (head == NULL)
        printf("δ�ҵ�Ա����Ϣ!\n");
    else
    {
        while (strcmp(p->number, n) && p->next != NULL)
        {
            pr = p;
            p = p->next;
        }
        if (!strcmp(p->number, n))
        {
            if (p == head)
                head = p->next;
            else
                pr->next = p->next;
            free(p);
            printf("ɾ���ɹ�!\n");
            i--;
        }
        else
            printf("δ�ҵ�Ա����Ϣ!\n");
    }
    Prf(head);
    return head;
}

//�������
void Prf(struct Stuff* head)
{
    struct Stuff* p = head;
    int i = 1;
    while (p != NULL)
    {
        printf("%d. %s %s %s %s %s %s %s %s\n"
            , i++, p->number, p->name, p->sex, p->borth, p->degree, p->business, p->phone, p->place);
        p = p->next;
    }
    system("pause");
}

//�ͷź���
void Fre(struct Stuff* head)
{
    struct Stuff* p;
    while (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }
}