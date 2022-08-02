//struct3.c
#include <stdio.h>
#define EMP_SZ 30


typedef struct EMPLOYEE {
						char name[20];		//멤버
						int salary;
						float height;
						char comAddr[100];
} EMP;


struct EMPLOYEE emps[EMP_SZ];	//구조체 배열
int Cn = 0;


int main()
{
	int choice, stop = 1;

	emp_load();

	while (stop)
	{
		printf("\n1. 사원정보 입력 \n");
		printf("2. 사원정보 출력 \n");
		printf("3. 사원정보 검색 \n");
		printf("4. 사원정보 저장 \n");
		printf("5. 사원정보 종료 \n");
		printf("Select ? (1~5) ");
		scanf("%d%*c", &choice);

		switch (choice)
		{
		case 1: emp_input();
			break;
		case 2: emp_output();
			break;
		case 3: emp_find();
			break;
		case 4: emp_save();
			break;
		case 5: stop = 0;
			break;
		}
	}

	printf("End \n");

	return 0;
}


emp_input()
{
	int i;

	for (i = Cn; i < EMP_SZ; i++)
	{
		printf("성명 ? (입력종료 : end) ");
		gets(emps[i].name);
		if (strcmp(emps[i].name, "end") == 0)
			break;
		printf("월급 ? ");
		scanf("%d", &emps[i].salary);
		printf("키(신장) ? ");
		scanf("%f%*c", &emps[i].height);
		printf("회사 주소 ? ");
		gets(emps[i].comAddr);
	}

	Cn = i;
}


emp_output()
{
	int i, sum = 0;

	printf("\n");
	for (i = 0; i < Cn; i++)
	{
		printf("%s, %d, %.2f, %s \n", emps[i].name, emps[i].salary,
									  emps[i].height, emps[i].comAddr);
		sum += emps[i].salary;
	}
	printf("===================================");
	printf("월급평균: %.2f \n", (float)sum / Cn);
	printf("===================================");

}


emp_find()
{
	char s_name[20];
	int i, found;

	while (1)	//무한루프
	{
		printf("검색할 성명 ? (검색종료:end) ");
		gets(s_name);
		if (strcmp(s_name, "end") == 0)
			break;

		found = 1; //못찾은 경우

		for (i = 0; i < Cn; i++)		//반목문은 break; 만나거나 거짓일 경우 빠져나간다.
		{
			if (strcmp(emps[i].name, s_name) == 0)
			{
				printf("%s, %d, %.2f, %s \n", emps[i].name, emps[i].salary,
											  emps[i].height, emps[i].comAddr);
				found = 0; //찾은경우
				//break;	//이름은 동명이인이 있을 수 있기 때문에 여기서 break하면 안됨. 고유한 명은 바로 break 가능
			}
		}

		if (found)
			printf("%s, Not found. \n", s_name);
	}	//while (1) end
}

emp_save()
{
	FILE *fp;	//파일 포인터
	
	//1. 스트림 연결
	fp = fopen("struct3.dat", "wb");
	if (fp == NULL)
	{
		printf("emp_save() Error \n");
		exit(1);
	}


	//2. save
	fwrite(&Cn, sizeof(Cn), 1, fp);
	fwrite(emps, sizeof(struct EMPLOYEE), Cn, fp);


	//3. 스트림 닫기
	fclose(fp);

	printf("struct43.dat 저장. \n");
}

emp_load()
{
	FILE* fp;	//파일 포인터

	//1. 스트림 연결
	fp = fopen("struct3.dat", "rb");
	if (fp == NULL)
	{
		printf("emp_load()open Error \n");
		return ;
	}
	//2. load
	fread(&Cn, sizeof(Cn), 1, fp);
	fread(emps, sizeof(struct EMPLOYEE), Cn, fp);


	//3. 스트림 닫기
	fclose(fp);

	printf("struct43.dat 로드. \n");
}

