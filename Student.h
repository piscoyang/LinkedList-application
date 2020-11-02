#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "Menu.h"
#define MaxSize_1 20
#define MaxSize_2 13
#define MaxSize_3 50
#define MaxSize_4 10
#define TRUE 1
#define FALSE 0

typedef struct Student {
	char name[MaxSize_1];
	char num[MaxSize_2];
    char Class[MaxSize_1];
    int age;
	char password[6];
	int sex;
	float grade;
    float jidian;
    struct Subject* HEAD;
	struct Student* next;
}Student;
typedef struct Subject {
    char name[MaxSize_1];
    char sub[30];
    int zhuangtai;
    float jidian;
    float grade;
    char xueqi[MaxSize_1];
    struct Subject* next;
}Subject;
Student* creat_list_Stu(){
    Student* head = (Student*)malloc(sizeof(Student));
    char a[MaxSize_1], b[MaxSize_2], c[7],d[MaxSize_1];
    Subject* creat_list_Stu_Sub(char* );
    int t, n;
    Student* p;
    Student* q;
    Subject* sub;
    p = q = head;
    FILE* r = fopen("data@stu.txt", "r");
    if (r == NULL) {
        printf("���ļ�ʧ��!");
        exit(0);
    }
    while (fscanf(r, "%s %s %s %d %s %d", a, b,d, &t, c, &n) != EOF){
        q = (Student*)malloc(sizeof(Student));
        strcpy(q->name, a);
        strcpy(q->num, b);
        strcpy(q->Class, d); 
        q->age = t;
        strcpy(q->password, c); q->sex = n;
        sub = creat_list_Stu_Sub(q->name);
        q->HEAD= sub;
        p->next = q;
        p = q;
    }
    p->next = NULL;
    return head;
}
Student* Login_Stu(Student* L) {
	char a[MaxSize_2],b[MaxSize_2];
    int i=0;
    void Display(Student * L);
    Student* IsIn_Stu(Student * L, char* a, char* b);
    Student* stu=(Student*)malloc(sizeof(Student));
	system("cls");
    printf("�����������˺�:");
    (void)scanf("%s", a);
	printf("��������������:");
    (void)scanf("%s", b);
	stu=IsIn_Stu(L,a, b);
    while (i < 2&&stu == 0) {
            printf("�˺��������������");i++;stu=Login_Stu(L);
    }
    if (i == 2) {
        printf("�˺��������������࣬�����˳�...");
        exit(0);
    }
    return stu;
}
Student* IsIn_Stu(Student* L,char* a, char* b) {
    Student* p = L->next;
    while (p != NULL) {
        if ((strcmp(p->num,a)==0)&&(strcmp(p->password,b)==0)) break;
        else 
            p = p->next; 
    }
    return p;
}
void Display_Stu(Student* L) {
    if(L->sex==0)
    printf("����:%s\nѧ��:%s\n�༶:%s\n����:%d\n�Ա�:Ů\n����:%s\n", L->name,L->num,L->Class,L->age,L->password);
    else if(L->sex==1)
        printf("����:%s\nѧ��:%s\n�༶:%s\n����:%d\n�Ա�:��\n����:%s\n", L->name, L->num,L->Class,L->age, L->password);
}
void ChangePassWord_Stu(Student* L,Student*R) {
    void Synchronous_Data_Stu(Student*);
    char a[MaxSize_2],b[MaxSize_2],c[MaxSize_2];
    FILE* change=NULL;
    Student* temp = R;
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
    Synchronous_Data_Stu(R);
    Sleep(1000);
    printf("������ĳɹ������������Ϊ:%s\n", L->password);
}
void Synchronous_Data_Stu(Student *L) {
    FILE* fp;
    L = L->next;
    if ((fp = fopen("data@stu.txt", "w")) == NULL) {
        return;
    }
    while (L != NULL) {
        fprintf(fp," %s %s %s %d %s %d", L->name, L->num,L->Class,L->age, L->password, L->sex);
        L = L->next;
    }
    fclose(fp);
}
Subject* creat_list_Stu_Sub(char* string) {
    Subject* head = (Subject*)malloc(sizeof(Subject));
    char a[MaxSize_1],g[MaxSize_1], f[30];
    int b; float c, d;
    Subject* p;
    Subject* q;
    p = q = head;
    FILE* r = fopen("stu@sub.txt", "r");
    if (r == NULL)
    {
        printf("���ļ�ʧ��!");
        exit(0);
    }
    while (fscanf(r, "%s %s %s %d %f %f", a, f,g,&b, &c, &d) != EOF) {
        if (strcmp(string, a) == 0) {
            q = (Subject*)malloc(sizeof(Subject));
            {
                strcpy(q->name, a);
                strcpy(q->xueqi, g);
                strcpy(q->sub, f); 
                q->zhuangtai = b;
                q->jidian = c; 
                q->grade = d;
                p->next = q;
                p = q;
            }
        }
    }
    fclose(r);
   p->next = NULL;
    return head;
}