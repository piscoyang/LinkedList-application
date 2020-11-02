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
	printf(" \t\t\t\t\t\t ����ϵͳ");
	printf(" \n\n\t\t\t\t\t\t1.ѧ����¼\n");
	printf("\t\t\t\t\t\t2.��ʦ��¼\n");
	printf(" \t\t\t\t\t\t3.����Ա��¼\n");
	printf("\t\t\t\t\t\t4.�˳�����\n");
pt:printf("����������ѡ��Ĺ���:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:Stu_Menu(L, R); break;
	case 2:Tea_Menu(L, R); break;
	case 3:Admin_Menu(L, R); break;
	case 4: {
		printf("�����˳�����...");
		Sleep(1000);
		exit(1);
		break;
	}
	default: {
		printf("���������������������");
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
		printf("��¼ʧ�ܣ�ϵͳ�쳣"); exit(0);
	}
	(void)fscanf(fp, "%s", b);
	fclose(fp);
	pp:printf("���������Ա����:");
	(void)scanf("%s", a);
	if (strcmp(b, a) == 0) {
	pt: system("cls");
		printf("\t\t\t\t\t1.ѧ����Ϣ��ѯ�޸�\n");
		printf("\t\t\t\t\t2.��ʦ��Ϣ��ѯ�޸�\n");
		printf("\t\t\t\t\t3.�޸Ĺ���Ա����\n");
		printf("\t\t\t\t\t4.ע��\n");//��ʦע���ѧ��ע��
		printf("\t\t\t\t\t5.ע��\n");
		printf("\t\t\t\t\t6.�˳���¼\n");
		printf("\t\t\t\t\t7.�˳�����\n");
		printf("����������ѡ��Ĺ��ܵ���ţ�");
		(void)scanf("%d", &i);
		switch (i) {
		case 1:Stu_Search_Modify(L); IsQuit(L, R); goto pt; break;
		case 2:Tea_Search_Modify(R); IsQuit(L, R); goto pt; break;
		case 3:Change_Admin_PassWord(a); IsQuit(L, R); printf("�����µ�¼"); Sleep(1000); goto pf; break;
		case 4:Register_Stu_Tea_Menu(L, R); IsQuit(L, R); goto pt; break;
		case 5:Unsubscribe_Menu(L, R); IsQuit(L, R); goto pt; break;
		case 6:system("cls"); Menu(L, R); break;
		case 7:printf("�����˳�����..."); Sleep(1000); exit(1); break;
		default: {
			printf("���������������������");
			Sleep(1000);
			system("cls");
			goto pt;
		}
		}
	}
	else {
		printf("���������������������");
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
	printf("\t\t\t1.��Ϣ��ѯ\n");
	printf("\t\t\t2.ѧ����Ϣ��ѯ\n");//ָ���γ̵�ƽ���ɼ�����߷֣���ͷ֣��������������������ļ��������ϣ������
	printf("\t\t\t3.�޸�����\n");
	printf("\t\t\t4.ѧ����Ϣ��ѯ\n");
	printf("\t\t\t5.�˳���¼\n");
	printf("\t\t\t6.�˳�����\n");
pt:printf("����������ѡ��Ĺ���:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); Display_Tea(tea); IsQuit(L, R); system("cls"); goto pp; break;
	case 2:Subject_Search(L); IsQuit(L, R); system("cls"); goto pp; break;
	case 3:ChangePassWord_Tea(tea, R); IsQuit(L, R); system("cls"); goto pp; break;
	case 4:Student_Search(L); IsQuit(L, R); system("cls"); goto pp; break;
	case 5:system("cls"); Menu(L, R); break;
	case 6:printf("�����˳�����..."); Sleep(1000); exit(1); break;
	default: {
		printf("���������������������");
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
	printf("\t\t\t\t1.������Ϣ��ѯ\n");
	printf("\t\t\t\t2.ѧ����Ϣ��ѯ\n");
	printf("\t\t\t\t3.�޸�����\n");
	printf("\t\t\t\t4.�˳���¼\n");
	printf("\t\t\t\t5.�˳�����\n");
pt:printf("����������ѡ��Ĺ���:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); Display_Stu(stu); IsQuit(L, R); goto pp; break;
	case 2:system("cls"); Search_Sub(stu); IsQuit(L, R); goto pp; break;
	case 3: system("cls"); ChangePassWord_Stu(stu, L);
		IsQuit(L, R);
		printf("�����Ѹ��£������µ�¼��");
		Sleep(700);
		system("cls"); Stu_Menu(L, R); break;
	case 4:system("cls"); Menu(L, R);  break;
	case 5:printf("�����˳�����..."); Sleep(1000); exit(1); break;
	default: {
		printf("���������������������");
		Sleep(1000);
		goto pt;
	}
	}
}
void Register_Stu_Tea_Menu(Student* L, Teacher* R) {
	int i;
	void IsQuit(Student * L, Teacher * R);
pt:	system("cls");
	printf("\t\t\t\t1.ѧ����Ϣע��\n");
	printf("\t\t\t\t2.��ʦ��Ϣע��\n");
	printf("\t\t\t\t3.�˳�\n");
	printf("����������ѡ������:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); L = Register_Stu(L); Synchronous_Data_Stu(L); IsQuit(L, R); goto pt; break;
	case 2:system("cls"); R = Register_Tea(R); Synchronous_Data_Tea(R); IsQuit(L, R); goto pt; break;
	case 3:Admin_Menu(L, R); IsQuit(L, R); goto pt; break;
	default: {
		printf("ѡ��������������������");
		Sleep(1000);
		goto pt;
	}
	}
}
void IsQuit(Student* L, Teacher* R) {
	int i;
 pp:printf("��ѡ���Ӧ����:(1�˳���ǰ����,2�˳���¼,3�˳�ϵͳ).");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:return; break;
	case 2:printf("������ת���˵�...\n"); Sleep(1500); system("cls"); Menu(L, R); break;
	case 3:printf("�����˳�ϵͳ�����Ժ�...\n"); Sleep(1500); system("cls"); exit(0); break;
	default:goto pp;
	}
	return;
}
void Unsubscribe_Menu(Student* L, Teacher* R) {
	int i;
	void IsQuit(Student * L, Teacher * R);
pt:	system("cls");
	printf("\t\t\t\t1.ѧ����Ϣע��\n");
	printf("\t\t\t\t2.��ʦ��Ϣע��\n");
	printf("\t\t\t\t3.�˳�\n");
	printf("����������ѡ������:");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:L = Unsubscribe_Stu(L); Synchronous_Data_Stu(L); Synchronous_Data(L); IsQuit(L, R); goto pt; break;
	case 2:R = Unsubscribe_Tea(R); Synchronous_Data_Tea(R); IsQuit(L, R); goto pt; break;
	case 3:Admin_Menu(L, R); IsQuit(L, R); goto pt; break;
	default: {
		printf("ѡ��������������������");
		Sleep(1000);
		goto pt;
	}
	}
}