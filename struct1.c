//struct1.c
#include <stdio.h>

//����ü(struct): ������ �ִ� �����͵��� �ϳ��� �ڷ������� ����� ����ϰ� �Ѵ�.
//				  (��, ����� ���� �ڷ����̴�.)
//				  �̶� �����͵��� �ڷ����� ��� �ڷ����� �͵� �ȴ�.

int main()
{
	//��������� �ڷ��� ����
	  //EMPLOYEE�� tag_name�̴�.
	typedef struct EMPLOYEE {
							char name[20];		//���(Member)
							int salary;
							float height;
							char comAddr[100];
	} EMP;

	//�ڷ���      ����ü����
	struct EMPLOYEE emps = { "ȫ�浿", 3500000, 175, "����� ������ 100" };			//�ʱ�ȭ
	EMP tmp;

	printf("%d, %d \n", sizeof(emps), sizeof(struct EMPLOYEE));
	printf("emps: %p, %p \n", &emps, emps.name);	//&�� �־�� �����ּҰ� �ȴ�.


	//printf("���� ? ");		//jenong ??\0
	//gets(emps.name);
	//printf("���� ? ");		//1000[enter]
	//scanf("%d", &emps.salary);
	//printf("Ű(����) ? ");
	//scanf("%f%*c", &emps.height);	//155[enter]
	//printf("ȸ�� �ּ� ? ");
	//gets(emps.comAddr);


	// . : ����ü ��� ������
	printf("%s, %d, %.2f, %s \n", emps.name, emps.salary, 
								  emps.height, emps.comAddr);

	tmp = emps;
	printf("%s, %d, %.2f, %s \n", emps.name, emps.salary,
								  emps.height, emps.comAddr);



	return 0;
}