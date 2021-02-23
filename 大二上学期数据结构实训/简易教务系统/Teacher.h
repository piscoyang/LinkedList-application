#pragma once
#include <stdio.h>
#include "Student.h"
typedef struct Teacher {
    char name[MaxSize_1];
    char num[MaxSize_2];
    int age;
    char password[6];
    int sex;
    struct Teacher* next;
}Teacher;
Teacher* creat_list_Tea() {
    Teacher* head = (Teacher*)malloc(sizeof(Teacher));
    char a[MaxSize_1], b[MaxSize_2], c[7];
    int t, n;
    Teacher* p;
    Teacher* q;
    p = q = head;
    FILE* r = fopen("data@tea.txt", "r");
    if (r == NULL)
    {
        printf("���ļ�ʧ��!");
        exit(0);
    }

    while (fscanf(r, "%s %s %d %s %d", a, b, &t, c,&n )!= EOF)
    {
        q = (Teacher*)malloc(sizeof(Teacher));
        strcpy(q->name, a); 
        strcpy(q->num, b);
        q->age = t; 
        strcpy(q->password, c); q->sex = n;
        p->next = q;
        p = q;
    }
    fclose(r);
    p->next = NULL;
    return head;
}
Teacher* Login_Tea(Teacher* L) {
    char a[MaxSize_2], b[MaxSize_2];
    void Display_Tea(Teacher * L);
    Teacher* IsIn_Tea(Teacher * L, char* a, char* b);
    Teacher* tea = (Teacher*)malloc(sizeof(Teacher));
    system("cls");
pt:printf("�����������˺�:");
    (void)scanf("%s", a);
    printf("��������������:");
    (void)scanf("%s", b);
    tea = IsIn_Tea(L, a, b);
    if ( tea == 0) {
        printf("�˺��������������");  goto pt;
    }
    return tea;
}
Teacher* IsIn_Tea(Teacher* L, char* a, char* b) {
    Teacher* p = L->next;
    while (p != NULL) {
        if ((strcmp(p->num, a) == 0) && (strcmp(p->password, b) == 0)) break;
        else
            p = p->next;
    }
    return p;
}
void Display_Tea(Teacher* L) {
    if (L->sex == 0)
        printf("����:%s\n����:%s\n����:%d\n�Ա�:Ů\n����:%s\n", L->name, L->num, L->age, L->password);
    else if (L->sex == 1)
        printf("����:%s\n����:%s\n����:%d\n�Ա�:��\n����:%s\n", L->name, L->num, L->age, L->password);
}
void ChangePassWord_Tea(Teacher* L, Teacher* R) {
    void Synchronous_Data_Tea(Teacher*);
    char a[MaxSize_2], b[MaxSize_2], c[MaxSize_2];
pp:printf("��������ľ�����:");
    (void)scanf("%s", a);
    if ((strcmp(a, L->password)) == 0) {
    pt:printf("���������������:");
        (void)scanf("%s", b);
        printf("��ȷ�����������:");
        (void)scanf("%s", c);
        if ((strcmp(b, c)) == 0) {
            strcpy(L->password, c);
        }
        else {
            printf("������������벻һ�£�����������:");
            Sleep(700);
            system("cls");
            goto pt;
        }
    }
    else {
        printf("����������벻��ȷ������������:");
        Sleep(700);
        system("cls");
        goto pp;
    }
    Synchronous_Data_Tea(R);
    Sleep(1000);
    printf("������ĳɹ������������Ϊ:%s\n", L->password);
}
void Synchronous_Data_Tea(Teacher* L) {
    FILE* fp;
    L = L->next;
    if ((fp = fopen("data@tea.txt", "w")) == NULL) {
        return;
    }
    while (L != NULL) {
         fprintf(fp, " %s %s %d %s %d", L->name, L->num, L->age, L->password, L->sex);
         L = L->next;
        }
    fclose(fp);
}
void Subject_Search(Student* L) {
    char ch[20];
    int i = 0;
    Student stu_1[30];
    void ShellSort(Student[], int n);
    void writeFile(Student L[], int n);
    float sum_jidian = 0, sum_chengji = 0;
    p:printf("��������Ҫ��ѯ��ѧ��:");
    (void)scanf("%s", ch);
    Student* T = L->next;
    Subject* R; 
    while(T!=NULL){
        R= T->HEAD->next;
        while (R != NULL ) {
            if (strcmp(ch,R->sub)==0) {
                if (R->zhuangtai == 1) {
                    printf("����:%s\tѧ��:%s\tѧ��:%s\t״̬:����\t����:%.2f\t�ɼ�:%.2f\n", R->name, R->sub, R->xueqi, R->jidian, R->grade);
                    stu_1[i].jidian = R->jidian;
                    stu_1[i].grade = R->grade;
                    strcpy(stu_1[i].name, T->name);
                    strcpy(stu_1[i].num, T->num);
                    strcpy(stu_1[i].Class, T->Class);
                    i++;
                    sum_jidian += R->jidian;
                    sum_chengji += R->grade;
                }
                else if (R->zhuangtai == 0)printf("����:%s\tѧ��:%s\tѧ��:%s\t״̬:δ��\n", R->name, R->sub, R->xueqi);
            }
            R = R->next;
        }
        T = T->next;
    }
    if (!i) {
        printf("��ѯ������ѧ�ƣ�������!"); goto p;
    }
    else {
        ShellSort(stu_1, i);
        printf("��߷�Ϊ:%.2f\t�������Ϊ:%.2f\n��ͷ�Ϊ:%.2f\t�������Ϊ:%.2f\n", stu_1[i - 1].grade, stu_1[i - 1 ].jidian,stu_1[0].grade, stu_1[0].jidian);
        printf("�ɼ�(����)�ӵ͵�������Ϊ:\n");
        for (int j = 1; j <= i; j++) {
            printf("����:%s ѧ��:%s �༶:%s �ɼ�:%.2f ����:%.2f\n",stu_1[j-1].name,stu_1[j-1].num,stu_1[j-1].Class,stu_1[j-1].grade,stu_1[j-1].jidian);
        }
        printf("\n");
        puts("���ڱ��浽save.txt��...");
        writeFile(stu_1, i);
        Sleep(1500);
        puts("д��ɹ�");
    }
}
void writeFile(Student L[], int n){
    Student* pa, *pb;
    FILE* fp;
    Student R[30];
    pa = L, pb = R;
    if ((fp = fopen("save.dat", "wb+")) == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }
    fwrite(pa, sizeof(Student), n, fp);
    rewind(fp);
    fread(pb, sizeof(Student), n, fp);
    printf("\nRead File:\n");
    for (int j = 0; j < n; j++, pb++) {
        printf("\t%s %s %s %.2f %.2f\n", pb->name,pb->num,pb->Class,pb->grade,pb->jidian);
    }
    fclose(fp);
    printf("\nд���ļ� save.txt �ɹ�\n");
}
void ShellSort(Student R[], int n){
    int i, j, d;
    Student temp;
    d = n / 2;
    while (d > 0){
        for (i = d; i < n; i++) {
            j = i - d;
            while (j >= 0 && R[j].grade > R[j + d].grade) {
                temp = R[j];
                R[j] = R[j + d];
                R[j + d] = temp;
                j = j - d;
            }
        }
        d = d / 2;
    }
}
void Student_Search(Student* L) {
    if (L==NULL) {
        printf("ϵͳ�쳣,�����˳�...");
        exit(0);
    }
    char ch[13];
    int i;
    Student* Modify_Stu(Student*);
    void Search_Sub(Student*);
    Student* head = L;
pp:	L = head->next;
    printf("�����������ѯѧ����¼�˺�:");
    (void)scanf("%s", ch);
    while (L != NULL) {
        if (strcmp(L->num, ch) != 0) {
            L = L->next;
        }
        else break;
    }
    if (L==NULL) {
        printf("�����ڸ�ѧ���û�������������");
        Sleep(1500);
        system("cls");
        goto pp;
    }
    printf("��ѧ���û�Ϊ:\n����:%s\n����:%d\n�˺�:%s\n�༶:%s\n�Ա�:%d\n����:%s\n ", L->name, L->age, L->num, L->Class, L->sex, L->password);
pt:printf("ѡ����\n1.��ѯѧ����Ϣ2.�˳���ѯ");
    (void)scanf("%d", &i);
    switch (i) {
    case 1:system("cls"); Search_Sub(L); return; break;
    case 2:system("cls"); return;
    default:printf("���������������������"); goto pt;
    }
}