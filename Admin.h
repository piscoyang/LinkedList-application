#pragma once
#include <stdio.h>
#include "Teacher.h"
#include "Student.h"
#include "Menu.h"
void Tea_Search_Modify(Teacher* R) {
	if (!R) {
		printf("ϵͳ�쳣,�����˳�...");
		exit(0);
	}
	char ch[13];
	int i;
	Teacher* Modify_Tea(Teacher *);
	Teacher* head=R;
pp:	R = head->next;
	printf("�����������ѯ���޸ĵĽ�ʦ��¼�˺�:");
	(void)scanf("%s", ch);
	while (R != NULL) {
		if (strcmp(R->num, ch) != 0) {
			R = R->next;
		}
		else break;
	}
	if (!R) {
		printf("�����ڸý�ʦ�û�������������");
		system("cls");
		goto pp;
	}
	Display_Tea(R);
 pt:printf("�Ƿ���Ҫ�޸���Ϣ\n0�޸�1�˳���ѯ");
	(void)scanf("%d", &i);
	switch (i) {
	case 0:R = Modify_Tea(R); Sleep(1000); system("cls"); return; break;
	case 1:system("cls"); return;
	default:printf("���������������������"); goto pt;
	}
}
void Stu_Search_Modify(Student* L) {
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
	printf("�����������ѯ���޸ĵ�ѧ����¼�˺�:");
	(void)scanf("%s", ch);
	while (L != NULL) {
		if (strcmp(L->num, ch) != 0) {
			L = L->next;
		}
		else break;
	}
	if (!L) {
		printf("�����ڸ�ѧ���û�������������");
		system("cls");
		goto pp;
	}
	Display_Stu(L);
pt:printf("ѡ����\n1�޸�2.��ѯѧ����Ϣ3.�˳���ѯ");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:system("cls"); L = Modify_Stu(L); Sleep(1000); system("cls"); return; break;
	case 2:system("cls"); Search_Sub(L); return; break;
	case 3:system("cls"); return;
	default:printf("���������������������"); goto pt;
	}
}
Teacher* Modify_Tea(Teacher* R) {
	printf("��������µĽ�ʦ��Ϣ(������ ���� �˺� �Ա� ����ĸ�ʽ����)");
	(void)scanf("%s %d %s %d %s", R->name, &R->age, R->num, &R->sex, R->password);
	Synchronous_Data_Tea(R);
	printf("�޸ĳɹ�\n");
	return R;
}
Student* Modify_Stu(Student* R) {
	int i;
	void Modify_Sub(Student*);
	pp:printf("\t\t\t\t1.�޸�ѧ�Ƴɼ���Ϣ\n");
	printf("\t\t\t\t2.�޸�ѧ��������Ϣ\n");
	printf("\t\t\t\t3.\n");
	(void)scanf("%d", &i);
	switch (i) {
	case 1:Modify_Sub(R); break;
	case 2:printf("��������µ�ѧ����Ϣ(������ ���� �Ա� �༶ ����ĸ�ʽ����)");
		(void)scanf("%s %d %d %s %s", R->name, &R->age, &R->sex, R->Class,R->password);
		Synchronous_Data_Stu(R);
		printf("�޸ĳɹ�\n"); break;
	case 3:
	default:printf("��������������������"); Sleep(1000); goto pp;
	}
	return R;
}
void Change_Admin_PassWord(char* a){
	FILE* change = NULL;
	char b[7], c[7],d[7];
	if ((change = fopen("admin.txt", "w")) == NULL) {
		printf("ϵͳ�쳣���޸�����ʧ��");
		return;
	}
pp:printf("��������ľ�����:");
	(void)scanf("%s", b);
	if (strcmp(a, b) == 0) {
	pt:printf("���������������:");
		(void)scanf("%s", c);
		printf("��ȷ�����������:");
		(void)scanf("%s", d);
		if ((strcmp(c, d)) == 0) {
			fprintf(change, "%s", d);
			fclose(change);
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
	Sleep(1000);
	printf("������ĳɹ������������Ϊ:%s\n", c);
	return;
}
Student* Register_Stu(Student* L) {
	if (L==NULL) {
		printf("ϵͳ�쳣,�����˳�...");
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
	printf("�밴���� ѧ�� �༶ ���� ���� �Ա���������:\n");
	printf("����:");
	(void)scanf("%s", stu_1->name);
	printf("ѧ��:");
	(void)scanf("%s", stu_1->num);
	printf("�༶:");
	(void)scanf("%s", stu_1->Class);
	printf("����:");
	(void)scanf("%d", &stu_1->age);
	printf("����:");
	(void)scanf("%s", stu_1->password);
	printf("�Ա�:");
	(void)scanf("%d", &stu_1->sex);
	return head;
}
Student* Unsubscribe_Stu(Student* L) {
	if (L==NULL) {
		printf("ϵͳ�쳣,�����˳�...");
		exit(0);
	}
	char a[13];
	Student* pre, * r, * head;
	Subject* pre2, * r2;
	pre = L;
	head = L; 
pp:printf("����������ɾ����ѧ����ѧ��");
	(void)scanf("%s", a);
	while (pre->next != NULL && strcmp(a, pre->next->num) != 0) {
		pre = pre->next;
	}
	if (pre->next == NULL) { printf("û�и���ѧ���������²���"); goto pp; }
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
	printf("ɾ���ɹ�");
	return head;
}
Teacher* Register_Tea(Teacher* L) {
	if (!L) {
		printf("ϵͳ�쳣...\n"); exit(1);
	}
	system("cls");
	Teacher* head=L;
	L = head->next;
	while (L->next!=NULL) {
		L = L->next;
	}
	Teacher* tea_1 = L;
	tea_1->next = NULL;
	printf("�밴���� ���� ���� ���� �Ա���������:\n");
	printf("����:");
	(void)scanf("%s", tea_1->name);
	printf("����:");
	(void)scanf("%s", tea_1->num);
	printf("����:");
	(void)scanf("%d", &tea_1->age);
	printf("����:");
	(void)scanf("%s", tea_1->password);
	printf("�Ա�:");
	(void)scanf("%d", &tea_1->sex);
	return head;
}
Teacher* Unsubscribe_Tea(Teacher* L) {
	char a[13];
	Teacher* pre, *r,*head;
	pre = L;
	head = L; 
pp:printf("����������ɾ���Ľ�ʦ�Ĺ���");
	(void)scanf("%s", a);
	while (pre->next != NULL&&strcmp(a, pre->next->num) != 0) {
		pre=pre->next;
	}
	if (pre->next == NULL) { printf("û�и�����ʦ�������²���"); goto pp; }
	else {
		r = pre->next;
		pre->next = r->next;
		free(r);
	}
	printf("ɾ���ɹ�");
	return head;
}
void Modify_Sub(Student* L) {
	if (!L) {
		printf("ϵͳ�쳣,�����˳�...");
		exit(0);
	}
	char a[30];
	void Synchronous_Data(Student*);
	Subject* R = L->HEAD->next;
	Subject* Q;
	Q = R;
	printf("�޸�ǰ��ϢΪ:");
	printf("����:%s\n", L->name);
	printf("�༶:%s\n", L->Class);
	while (R != NULL) {
		printf("ѧ��:%s\n", R->sub);
		if (R->zhuangtai == 1) {
			printf("״̬:����\n");
			printf("ѧ��:%s\n", R->xueqi);
			printf("����:%.2f\n", R->jidian);
			printf("�ɼ�:%.2f\n", R->grade);
		}
		else {
			printf("״̬:δ��\n");
			printf("ѧ��:%s\n", R->xueqi);
		}
		R = R->next;
	}
	printf("��������Ҫ�޸ĵ�ѧ��\n");
	pp:(void)scanf("%s", a);
	while (Q != NULL) {
		if (strcmp(Q->sub, a) == 0)break; 
		else Q = Q->next;
	} 
	if (Q ==NULL) { printf("��ѧ��û�и�ѧ����Ϣ\n"); system("cls"); goto pp; }
	printf("������ı�����Ϣ:");
	printf("״̬:");
	(void)scanf("%d", &Q->zhuangtai);
	if (Q->zhuangtai == 1) {
		printf("ѧ��:");
		(void)scanf("%s", Q->xueqi);
		printf("����:");
		(void)scanf("%f", &Q->jidian);
		printf("�ɼ�:");
		(void)scanf("%f", &Q->grade);
	}
	printf("��״̬:\n");
	if (Q->zhuangtai == 1) {
		printf("״̬:����\n");
		printf("ѧ��:%s\n", R->xueqi);
		printf("����:%.2f\n", Q->jidian);
		printf("�ɼ�:%.2f\n", Q->grade);
	}
	else {
		printf("״̬:δ��\n");
		printf("ѧ��:%s\n", R->xueqi);
	}
	Synchronous_Data(L);
	printf("�޸ĳɹ�.��������˳��޸�\n");
	system("pause");
}
void Search_Sub(Student* L) {
	Subject* R = L->HEAD->next;
	printf("����:%s\n", L->name);
	while (R != NULL) {
		printf("ѧ��:%s\n", R->sub);
		if (R->zhuangtai == 1) {
			printf("״̬:����\n");
			printf("ѧ��:%s\n", R->xueqi);
			printf("����:%.2f\n", R->jidian);
			printf("�ɼ�:%.2f\n", R->grade);
		}
		else if (R->zhuangtai == 0) {
			printf("״̬:δ��\n");
			printf("ѧ��:%s\n", R->xueqi);
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