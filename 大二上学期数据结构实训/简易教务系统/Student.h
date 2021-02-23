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
        printf("打开文件失败!");
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
    printf("请输入您的账号:");
    (void)scanf("%s", a);
	printf("请输入您的密码:");
    (void)scanf("%s", b);
	stu=IsIn_Stu(L,a, b);
    while (i < 2&&stu == 0) {
            printf("账号输入错误，请重试");i++;stu=Login_Stu(L);
    }
    if (i == 2) {
        printf("账号输错或密码输错过多，正在退出...");
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
    printf("姓名:%s\n学号:%s\n班级:%s\n年龄:%d\n性别:女\n密码:%s\n", L->name,L->num,L->Class,L->age,L->password);
    else if(L->sex==1)
        printf("姓名:%s\n学号:%s\n班级:%s\n年龄:%d\n性别:男\n密码:%s\n", L->name, L->num,L->Class,L->age, L->password);
}
void ChangePassWord_Stu(Student* L,Student*R) {
    void Synchronous_Data_Stu(Student*);
    char a[MaxSize_2],b[MaxSize_2],c[MaxSize_2];
    FILE* change=NULL;
    Student* temp = R;
    pp:printf("请输入你的旧密码:");
    (void)scanf("%s", a);
    if ((strcmp(a, L->password)) == 0) {
        pt:printf("请输入你的新密码:");
        (void)scanf("%s", b);
        printf("请确认你的新密码:");
        (void)scanf("%s", c);
        if ((strcmp(b, c)) == 0) {
            strcpy(L->password, c);
        }
        else {
            printf("两次输入的密码不一致，请重新输入:");
            Sleep(700);
            system("cls");
            goto pt;
        }
    }
    else {
        printf("你输入的密码不正确，请重新输入:");
        Sleep(700);
        system("cls");
        goto pp;
    }
    Synchronous_Data_Stu(R);
    Sleep(1000);
    printf("密码更改成功，你的新密码为:%s\n", L->password);
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
        printf("打开文件失败!");
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