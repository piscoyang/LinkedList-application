#include<stdio.h>
#include "Menu.h"
#include "Student.h"
#include "Teacher.h"
int main(void) {
	Student *student;
	Teacher* teacher;
	teacher = creat_list_Tea();
	student=creat_list_Stu();
	Menu(student,teacher);
	return 0;
}

