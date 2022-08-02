//struct1.c
#include <stdio.h>

//구조체(struct): 관련이 있는 데이터들을 하나의 자료형으로 만들어 사용하게 한다.
//				  (즉, 사용자 정의 자료형이다.)
//				  이때 데이터들의 자료형은 어떠한 자료형이 와도 된다.

int main()
{
	//사용자정의 자료형 선언
	  //EMPLOYEE는 tag_name이다.
	typedef struct EMPLOYEE {
							char name[20];		//멤버(Member)
							int salary;
							float height;
							char comAddr[100];
	} EMP;

	//자료형      구조체변수
	struct EMPLOYEE emps = { "홍길동", 3500000, 175, "서울시 강남구 100" };			//초기화
	EMP tmp;

	printf("%d, %d \n", sizeof(emps), sizeof(struct EMPLOYEE));
	printf("emps: %p, %p \n", &emps, emps.name);	//&가 있어야 시작주소가 된다.


	//printf("성명 ? ");		//jenong ??\0
	//gets(emps.name);
	//printf("월급 ? ");		//1000[enter]
	//scanf("%d", &emps.salary);
	//printf("키(신장) ? ");
	//scanf("%f%*c", &emps.height);	//155[enter]
	//printf("회사 주소 ? ");
	//gets(emps.comAddr);


	// . : 구조체 멤버 연산자
	printf("%s, %d, %.2f, %s \n", emps.name, emps.salary, 
								  emps.height, emps.comAddr);

	tmp = emps;
	printf("%s, %d, %.2f, %s \n", emps.name, emps.salary,
								  emps.height, emps.comAddr);



	return 0;
}