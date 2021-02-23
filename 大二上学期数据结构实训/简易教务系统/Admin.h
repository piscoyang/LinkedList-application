#pragma once
#include <stdio.h>
#include "Teacher.h"
#include "Student.h"
#include "Menu.h"
void Tea_Search_Modify(Teacher* R) {
	if (!R) {
		printf("系统异常,正在退出...");
		exit(0);
	}
	char ch[13];
	int i;
	Teacher* Modify_Tea(Teacher *);
	Teacher* head=R;
pp:	R = head->next;
	printf("请输入你想查询或修改的教师登录账号:");
	(void)scanf("%s", ch);
	while (R != NULL) {
		if (strcmp(R->num, ch) != 0) {
			R = R->next;
		}
		else break;
	}
	if (!R) {
		printf("不存在该教师用户，请重新输入");
		system("cls");
		goto pp;
	}
	Display_Tea(R);
 pt:printf("是否需要修改信息\n0修改1退出查询");
	(void)scanf("%d", &i);
	switch (i) {
	case 0:R = Modify_Tea(R); Sleep(1000); system("cls"); return; break;
	case 1:system("cls"); return;
	default:printf("输入序号有误，请重新输入"); goto pt;
	}
}
void Stu_Search_Modify(Student* L) {
	if (L==NULL) {
		printf("系统异常,正在退出...");
		exit(0);
	}
	char ch[13];
	int i;
	Student* Modify_Stu(Student*);
	void Search_Sub(Student*);
	Student* head = L;
pp:	L = head->next;
	printf("请输入你想查询或修改的学生登录账号:");
	(void)scanf("%s", ch);
	while (L != NULL) {
		if (strcmp(L->num, ch) != 0) {
			L = L->next;
		}
		else break;
	}
	if (!L) {
		printf("不存在该学生用户，请重新输入");
		system("cls");
		goto pp;
	}
	Display_Stu(L);
pt:printf("选择功能\n1修改2.查询学科信息3.退出查询");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); L = Modify_Stu(L); Sleep(1000); system("cls"); return; break;
	case 2:system("cls"); Search_Sub(L); return; break;
	case 3:system("cls"); return;
	default:printf("输入序号有误，请重新输入"); goto pt;
	}
}
Teacher* Modify_Tea(Teacher* R) {
	printf("请输入更新的教师信息(按姓名 年龄 账号 性别 密码的格式输入)");
	(void)scanf("%s %d %s %d %s", R->name, &R->age, R->num, &R->sex, R->password);
	Synchronous_Data_Tea(R);
	printf("修改成功\n");
	return R;
}
Student* Modify_Stu(Student* R) {
	int i;
	void Modify_Sub(Student*);
	pp:printf("\t\t\t\t1.修改学科成绩信息\n");
	printf("\t\t\t\t2.修改学生其他信息\n");
	printf("\t\t\t\t3.\n");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:Modify_Sub(R); break;
	case 2:printf("请输入更新的学生信息(按姓名 年龄 性别 班级 密码的格式输入)");
		(void)scanf("%s %d %d %s %s", R->name, &R->age, &R->sex, R->Class,R->password);
		Synchronous_Data_Stu(R);
		printf("修改成功\n"); break;
	case 3:
	default:printf("序号输入错误，请重新输入"); Sleep(1000); goto pp;
	}
	return R;
}
void Change_Admin_PassWord(char* a){
	FILE* change = NULL;
	char b[7], c[7],d[7];
	if ((change = fopen("admin.txt", "w")) == NULL) {
		printf("系统异常，修改密码失败");
		return;
	}
pp:printf("请输入你的旧密码:");
	(void)scanf("%s", b);
	if (strcmp(a, b) == 0) {
	pt:printf("请输入你的新密码:");
		(void)scanf("%s", c);
		printf("请确认你的新密码:");
		(void)scanf("%s", d);
		if ((strcmp(c, d)) == 0) {
			fprintf(change, "%s", d);
			fclose(change);
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
	Sleep(1000);
	printf("密码更改成功，你的新密码为:%s\n", c);
	return;
}
Student* Register_Stu(Student* L) {
	if (L==NULL) {
		printf("系统异常,正在退出...");
		exit(0);
	}
	system("cls");
	Student* head=L;
	L = head->next;
	while (L->next != NULL) {
		L = L->next;
	}
	Student* stu_1 = L;
	stu_1->next = NULL;
	printf("请按姓名 学号 班级 年龄 密码 性别依次输入:\n");
	printf("姓名:");
	(void)scanf("%s", stu_1->name);
	printf("学号:");
	(void)scanf("%s", stu_1->num);
	printf("班级:");
	(void)scanf("%s", stu_1->Class);
	printf("年龄:");
	(void)scanf("%d", &stu_1->age);
	printf("密码:");
	(void)scanf("%s", stu_1->password);
	printf("性别:");
	(void)scanf("%d", &stu_1->sex);
	return head;
}
Student* Unsubscribe_Stu(Student* L) {
	if (L==NULL) {
		printf("系统异常,正在退出...");
		exit(0);
	}
	char a[13];
	Student* pre, * r, * head;
	Subject* pre2, * r2;
	pre = L;
	head = L; 
pp:printf("请输入你想删除的学生的学号");
	(void)scanf("%s", a);
	while (pre->next != NULL && strcmp(a, pre->next->num) != 0) {
		pre = pre->next;
	}
	if (pre->next == NULL) { printf("没有该名学生，请重新操作"); goto pp; }
	else {
		r = pre->next;
		pre->next = r->next;
		pre2 = r->HEAD;
		r2 = r->HEAD;
		while (!pre2->next) {
			r2 = pre2->next;
			pre2->next = r2->next;
			free(r2);
		}
		free(r);
	}
	printf("删除成功");
	return head;
}
Teacher* Register_Tea(Teacher* L) {
	if (!L) {
		printf("系统异常...\n"); exit(1);
	}
	system("cls");
	Teacher* head=L;
	L = head->next;
	while (L->next!=NULL) {
		L = L->next;
	}
	Teacher* tea_1 = L;
	tea_1->next = NULL;
	printf("请按姓名 工号 年龄 密码 性别依次输入:\n");
	printf("姓名:");
	(void)scanf("%s", tea_1->name);
	printf("工号:");
	(void)scanf("%s", tea_1->num);
	printf("年龄:");
	(void)scanf("%d", &tea_1->age);
	printf("密码:");
	(void)scanf("%s", tea_1->password);
	printf("性别:");
	(void)scanf("%d", &tea_1->sex);
	return head;
}
Teacher* Unsubscribe_Tea(Teacher* L) {
	char a[13];
	Teacher* pre, *r,*head;
	pre = L;
	head = L; 
pp:printf("请输入你想删除的教师的工号");
	(void)scanf("%s", a);
	while (pre->next != NULL&&strcmp(a, pre->next->num) != 0) {
		pre=pre->next;
	}
	if (pre->next == NULL) { printf("没有该名教师，请重新操作"); goto pp; }
	else {
		r = pre->next;
		pre->next = r->next;
		free(r);
	}
	printf("删除成功");
	return head;
}
void Modify_Sub(Student* L) {
	if (!L) {
		printf("系统异常,正在退出...");
		exit(0);
	}
	char a[30];
	void Synchronous_Data(Student*);
	Subject* R = L->HEAD->next;
	Subject* Q;
	Q = R;
	printf("修改前信息为:");
	printf("姓名:%s\n", L->name);
	printf("班级:%s\n", L->Class);
	while (R != NULL) {
		printf("学科:%s\n", R->sub);
		if (R->zhuangtai == 1) {
			printf("状态:已修\n");
			printf("学期:%s\n", R->xueqi);
			printf("绩点:%.2f\n", R->jidian);
			printf("成绩:%.2f\n", R->grade);
		}
		else {
			printf("状态:未修\n");
			printf("学期:%s\n", R->xueqi);
		}
		R = R->next;
	}
	printf("请输入你要修改的学科\n");
	pp:(void)scanf("%s", a);
	while (Q != NULL) {
		if (strcmp(Q->sub, a) == 0)break; 
		else Q = Q->next;
	} 
	if (Q ==NULL) { printf("该学生没有该学科信息\n"); system("cls"); goto pp; }
	printf("请输入改变后的信息:");
	printf("状态:");
	(void)scanf("%d", &Q->zhuangtai);
	if (Q->zhuangtai == 1) {
		printf("学期:");
		(void)scanf("%s", Q->xueqi);
		printf("绩点:");
		(void)scanf("%f", &Q->jidian);
		printf("成绩:");
		(void)scanf("%f", &Q->grade);
	}
	printf("现状态:\n");
	if (Q->zhuangtai == 1) {
		printf("状态:已修\n");
		printf("学期:%s\n", R->xueqi);
		printf("绩点:%.2f\n", Q->jidian);
		printf("成绩:%.2f\n", Q->grade);
	}
	else {
		printf("状态:未修\n");
		printf("学期:%s\n", R->xueqi);
	}
	Synchronous_Data(L);
	printf("修改成功.按任意键退出修改\n");
	system("pause");
}
void Search_Sub(Student* L) {
	Subject* R = L->HEAD->next;
	printf("姓名:%s\n", L->name);
	while (R != NULL) {
		printf("学科:%s\n", R->sub);
		if (R->zhuangtai == 1) {
			printf("状态:已修\n");
			printf("学期:%s\n", R->xueqi);
			printf("绩点:%.2f\n", R->jidian);
			printf("成绩:%.2f\n", R->grade);
		}
		else if (R->zhuangtai == 0) {
			printf("状态:未修\n");
			printf("学期:%s\n", R->xueqi);
		}
		R = R->next;
	}
}
void Synchronous_Data(Student* L) {
	FILE* fp;
	Student* head1 = L;
	Subject* head2 = head1->next->HEAD;
	if ((fp = fopen("stu@sub.txt", "w")) == NULL) {
		return;
	}
	head1 = head1->next;
	head2 = head2->next;
	while (head1) {
		head2 = head1->HEAD->next;
		while (head2) {
        fprintf(fp, " %s %s %s %d %.2f %.2f", head2->name,head2->sub,head2->xueqi,head2->zhuangtai,head2->jidian,head2->grade);
		head2 = head2->next;
		}
		head1 = head1->next;
	}
	fclose(fp);
}