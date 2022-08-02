//struct2.c
#include <stdio.h>

int main()
{
	typedef struct EMPLOYEE {
							char name[20];		//¸â¹ö(Member)
							int salary;
							float height;
							char comAddr[100];
	} EMP;

	struct EMPLOYEE emps;

	funcA();

	return 0;
}

funcA()
{
	struct EMPLOYEE tmp;


}