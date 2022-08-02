//struct3.c
#include <stdio.h>
#define EMP_SZ 30


typedef struct EMPLOYEE {
						char name[20];		//���
						int salary;
						float height;
						char comAddr[100];
} EMP;


struct EMPLOYEE emps[EMP_SZ];	//����ü �迭
int Cn = 0;


int main()
{
	int choice, stop = 1;

	emp_load();

	while (stop)
	{
		printf("\n1. ������� �Է� \n");
		printf("2. ������� ��� \n");
		printf("3. ������� �˻� \n");
		printf("4. ������� ���� \n");
		printf("5. ������� ���� \n");
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
		printf("���� ? (�Է����� : end) ");
		gets(emps[i].name);
		if (strcmp(emps[i].name, "end") == 0)
			break;
		printf("���� ? ");
		scanf("%d", &emps[i].salary);
		printf("Ű(����) ? ");
		scanf("%f%*c", &emps[i].height);
		printf("ȸ�� �ּ� ? ");
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
	printf("�������: %.2f \n", (float)sum / Cn);
	printf("===================================");

}


emp_find()
{
	char s_name[20];
	int i, found;

	while (1)	//���ѷ���
	{
		printf("�˻��� ���� ? (�˻�����:end) ");
		gets(s_name);
		if (strcmp(s_name, "end") == 0)
			break;

		found = 1; //��ã�� ���

		for (i = 0; i < Cn; i++)		//�ݸ��� break; �����ų� ������ ��� ����������.
		{
			if (strcmp(emps[i].name, s_name) == 0)
			{
				printf("%s, %d, %.2f, %s \n", emps[i].name, emps[i].salary,
											  emps[i].height, emps[i].comAddr);
				found = 0; //ã�����
				//break;	//�̸��� ���������� ���� �� �ֱ� ������ ���⼭ break�ϸ� �ȵ�. ������ ���� �ٷ� break ����
			}
		}

		if (found)
			printf("%s, Not found. \n", s_name);
	}	//while (1) end
}

emp_save()
{
	FILE *fp;	//���� ������
	
	//1. ��Ʈ�� ����
	fp = fopen("struct3.dat", "wb");
	if (fp == NULL)
	{
		printf("emp_save() Error \n");
		exit(1);
	}


	//2. save
	fwrite(&Cn, sizeof(Cn), 1, fp);
	fwrite(emps, sizeof(struct EMPLOYEE), Cn, fp);


	//3. ��Ʈ�� �ݱ�
	fclose(fp);

	printf("struct43.dat ����. \n");
}

emp_load()
{
	FILE* fp;	//���� ������

	//1. ��Ʈ�� ����
	fp = fopen("struct3.dat", "rb");
	if (fp == NULL)
	{
		printf("emp_load()open Error \n");
		return ;
	}
	//2. load
	fread(&Cn, sizeof(Cn), 1, fp);
	fread(emps, sizeof(struct EMPLOYEE), Cn, fp);


	//3. ��Ʈ�� �ݱ�
	fclose(fp);

	printf("struct43.dat �ε�. \n");
}

