//struct2.c
#include <stdio.h>
#include <string.h>


typedef struct EMPLOYEE {
						char name[20];		//멤버(Member)
						int salary;
						float height;
						char comAddr[100];
} EMP;


void funcA(struct EMPLOYEE *emps);
struct EMPLOYEE funcB();


int main()
{
	struct EMPLOYEE emps = { "홍길동", 3500000, 175, "서울시 강남구 100" }, my;
	
	funcA(&emps);	//실인수
	printf("main() emps : %s, %d, %.2f, %s \n", emps.name, emps.salary,
												emps.height, emps.comAddr);

	my = funcB();	//가인수

	printf("my : %s, %d, %.2f, %s \n", my.name, my.salary, my.height, my.comAddr);

	return 0;
}


void funcA(struct EMPLOYEE *emps)	//구조체 포인터 변수
{
	printf("funcA() : %s, %d, %.2f, %s \n", emps->name, emps->salary,
								       emps->height, emps->comAddr);

	emps->salary += 200000;
}


struct EMPLOYEE funcB()
{
	struct EMPLOYEE tmp;
	tmp.salary = 4500000;
	strcpy(tmp.name, "진달래");
	tmp.height = 163;
	strcpy(tmp.comAddr, "부산시 해운대구 200");

	//printf("funcB() : %s, %d, %.2f, %s \n", emps.name, emps.salary, emps.height, emps.comAddr);

	return tmp;
}



