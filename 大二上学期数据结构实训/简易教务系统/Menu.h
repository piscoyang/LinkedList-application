#pragma once
#include <stdio.h>
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
void Menu(Student* L,Teacher* R) {
	int i;
	void Stu_Menu(Student * , Teacher * );
	void Admin_Menu(Student * , Teacher*);
	void Tea_Menu(Student*, Teacher*);
	printf(" \t\t\t\t\t\t 教务系统");
	printf(" \n\n\t\t\t\t\t\t1.学生登录\n");
	printf("\t\t\t\t\t\t2.教师登录\n");
	printf(" \t\t\t\t\t\t3.管理员登录\n");
	printf("\t\t\t\t\t\t4.退出程序\n");
pt:printf("请输入你想选择的功能:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:Stu_Menu(L, R); break;
	case 2:Tea_Menu(L, R); break;
	case 3:Admin_Menu(L, R); break;
	case 4: {
		printf("正在退出程序...");
		Sleep(1000);
		exit(1);
		break;
	}
	default: {
		printf("输入序号有误，请重新输入");
		Sleep(1000); 
		goto pt;
	}
	}
}
void Admin_Menu(Student* L,Teacher* R) {
	char a[7] = { 0 };
	char b[7] = { 0 };
	void Register_Stu_Tea_Menu(Student * L, Teacher * R);
	void Unsubscribe_Menu(Student * L, Teacher * R);
	void IsQuit(Student * L, Teacher * R);
	int i;
	FILE* fp=NULL;
	pf:system("cls");
	if ((fp = fopen("admin.txt", "r")) == NULL) {
		printf("登录失败，系统异常"); exit(0);
	}
	(void)fscanf(fp, "%s", b);
	fclose(fp);
	pp:printf("请输入管理员密码:");
	(void)scanf("%s", a);
	if (strcmp(b, a) == 0) {
	pt: system("cls");
		printf("\t\t\t\t\t1.学生信息查询修改\n");
		printf("\t\t\t\t\t2.教师信息查询修改\n");
		printf("\t\t\t\t\t3.修改管理员密码\n");
		printf("\t\t\t\t\t4.注册\n");//教师注册和学生注册
		printf("\t\t\t\t\t5.注销\n");
		printf("\t\t\t\t\t6.退出登录\n");
		printf("\t\t\t\t\t7.退出程序\n");
		printf("请输入你想选择的功能的序号：");
		(void)scanf("%d", &i);
		switch (i) {
		case 1:Stu_Search_Modify(L); IsQuit(L, R); goto pt; break;
		case 2:Tea_Search_Modify(R); IsQuit(L, R); goto pt; break;
		case 3:Change_Admin_PassWord(a); IsQuit(L, R); printf("请重新登录"); Sleep(1000); goto pf; break;
		case 4:Register_Stu_Tea_Menu(L, R); IsQuit(L, R); goto pt; break;
		case 5:Unsubscribe_Menu(L, R); IsQuit(L, R); goto pt; break;
		case 6:system("cls"); Menu(L, R); break;
		case 7:printf("正在退出程序..."); Sleep(1000); exit(1); break;
		default: {
			printf("输入序号有误，请重新输入");
			Sleep(1000);
			system("cls");
			goto pt;
		}
		}
	}
	else {
		printf("密码输入错误，请重新输入");
		Sleep(1000);
		system("cls");
		goto pp;
	}
}
void Tea_Menu(Student* L,Teacher* R) {
	int i;
	void IsQuit(Student * L, Teacher * R);
	Teacher* tea;
    system("cls");
    tea = Login_Tea(R);
pp: system("cls");
	printf("\t\t\t1.信息查询\n");
	printf("\t\t\t2.学科信息查询\n");//指定课程的平均成绩，最高分，最低分，不及格人数，并生成文件输出。（希尔排序）
	printf("\t\t\t3.修改密码\n");
	printf("\t\t\t4.学生信息查询\n");
	printf("\t\t\t5.退出登录\n");
	printf("\t\t\t6.退出程序\n");
pt:printf("请输入你想选择的功能:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); Display_Tea(tea); IsQuit(L, R); system("cls"); goto pp; break;
	case 2:Subject_Search(L); IsQuit(L, R); system("cls"); goto pp; break;
	case 3:ChangePassWord_Tea(tea, R); IsQuit(L, R); system("cls"); goto pp; break;
	case 4:Student_Search(L); IsQuit(L, R); system("cls"); goto pp; break;
	case 5:system("cls"); Menu(L, R); break;
	case 6:printf("正在退出程序..."); Sleep(1000); exit(1); break;
	default: {
		printf("输入序号有误，请重新输入");
		Sleep(1000);
		goto pt;
	}
	}
}
void Stu_Menu(Student* L, Teacher* R) {
	int i;
	void IsQuit(Student * L, Teacher * R);
	Student* stu;
    stu=Login_Stu(L);
pp:	system("cls");
	printf("\t\t\t\t1.基本信息查询\n");
	printf("\t\t\t\t2.学科信息查询\n");
	printf("\t\t\t\t3.修改密码\n");
	printf("\t\t\t\t4.退出登录\n");
	printf("\t\t\t\t5.退出程序\n");
pt:printf("请输入你想选择的功能:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); Display_Stu(stu); IsQuit(L, R); goto pp; break;
	case 2:system("cls"); Search_Sub(stu); IsQuit(L, R); goto pp; break;
	case 3: system("cls"); ChangePassWord_Stu(stu, L);
		IsQuit(L, R);
		printf("数据已更新，请重新登录。");
		Sleep(700);
		system("cls"); Stu_Menu(L, R); break;
	case 4:system("cls"); Menu(L, R);  break;
	case 5:printf("正在退出程序..."); Sleep(1000); exit(1); break;
	default: {
		printf("输入序号有误，请重新输入");
		Sleep(1000);
		goto pt;
	}
	}
}
void Register_Stu_Tea_Menu(Student* L, Teacher* R) {
	int i;
	void IsQuit(Student * L, Teacher * R);
pt:	system("cls");
	printf("\t\t\t\t1.学生信息注册\n");
	printf("\t\t\t\t2.教师信息注册\n");
	printf("\t\t\t\t3.退出\n");
	printf("请输入你想选择的序号:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); L = Register_Stu(L); Synchronous_Data_Stu(L); IsQuit(L, R); goto pt; break;
	case 2:system("cls"); R = Register_Tea(R); Synchronous_Data_Tea(R); IsQuit(L, R); goto pt; break;
	case 3:Admin_Menu(L, R); IsQuit(L, R); goto pt; break;
	default: {
		printf("选择的序号有误，请重新输入");
		Sleep(1000);
		goto pt;
	}
	}
}
void IsQuit(Student* L, Teacher* R) {
	int i;
 pp:printf("请选择对应功能:(1退出当前操作,2退出登录,3退出系统).");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:return; break;
	case 2:printf("正在跳转主菜单...\n"); Sleep(1500); system("cls"); Menu(L, R); break;
	case 3:printf("正在退出系统，请稍后...\n"); Sleep(1500); system("cls"); exit(0); break;
	default:goto pp;
	}
	return;
}
void Unsubscribe_Menu(Student* L, Teacher* R) {
	int i;
	void IsQuit(Student * L, Teacher * R);
pt:	system("cls");
	printf("\t\t\t\t1.学生信息注销\n");
	printf("\t\t\t\t2.教师信息注销\n");
	printf("\t\t\t\t3.退出\n");
	printf("请输入你想选择的序号:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:L = Unsubscribe_Stu(L); Synchronous_Data_Stu(L); Synchronous_Data(L); IsQuit(L, R); goto pt; break;
	case 2:R = Unsubscribe_Tea(R); Synchronous_Data_Tea(R); IsQuit(L, R); goto pt; break;
	case 3:Admin_Menu(L, R); IsQuit(L, R); goto pt; break;
	default: {
		printf("选择的序号有误，请重新输入");
		Sleep(1000);
		goto pt;
	}
	}
}