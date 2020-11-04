#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ 12
#define MAX_SEX 5
#define MAX 1000


//ͨѶ¼

//�˵�
void menu()
{
	printf("********************************************\n");
	printf("**********1.add         2.del    ***********\n");
	printf("**********3.search      4.modify ***********\n");
	printf("**********5.sort        6.show   ***********\n");
	printf("**********         0.exit        ***********\n");
	printf("********************************************\n");
}


enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];//����
	int sz;//��Ч����

}Contact;


//���һ���˵���Ϣ
void add_contact(Contact * pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else{
    printf("���������֣���");
	scanf("%s", pc->data[pc->sz].name);
	printf("������绰����");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ����");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������QQ����");
	scanf("%s", pc->data[pc->sz].qq);
	printf("�������Ա𣺡�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("���������䣺��");
	scanf("%d", &(pc->data[pc->sz].age));

	pc->sz++;
	printf("��ӳɹ�\n");
	}
	
}


//��ʾͨѶ¼�е���Ϣ
void show_contact(Contact* pc)
{
	int i = 0;
	printf("%10s %12s %20s %5s %12s %5s\n", "����", "�绰", "��ַ", "����", "qq", "�Ա�");
	for (i=0; i < pc->sz; i++)
	{
		printf("%10s %12s %20s %5d %12s %5s\n",pc->data[i].name, 
			pc->data[i].tele, 
			pc->data[i].addr, 
			pc->data[i].age, 
			pc->data[i].qq,
			pc->data[i].sex );
	}
}

int find_peo_by_name(Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}


//ɾ��ָ������ϵ��
void dele_contact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("��Ǹ��ͨѶ¼Ϊ��\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("����������");
		scanf("%s", name);
		//1.���ҵ�ָ������ϵ�˵�λ��
		int pos=find_peo_by_name(pc,name);
		if (pos == -1)
		{
			printf("ɾ�����˲�����\n");
		}
		else
		{
		//2.ɾ��
			int j = 0;
			for (j = pos; j < pc->sz-1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("ɾ���ɹ�\n");
		}	
	}
}

//����ָ����ϵ��
void search_contact(Contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("������Ҫ�����˵�����");
	scanf("%s", name);
	int pos=find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n", "����", "�绰", "��ַ", "����", "qq", "�Ա�");
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}

//�޸�ָ����ϵ�˵���Ϣ
void modify_contact(Contact * pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("�������µ����֣���");
		scanf("%s", pc->data[pos].name);
		printf("�������µĵ绰����");
		scanf("%s", pc->data[pos].tele);
		printf("�������µĵ�ַ����");
		scanf("%s", pc->data[pos].addr);
		printf("�������µ�QQ����");
		scanf("%s", pc->data[pos].qq);
		printf("�������µ��Ա𣺡�");
		scanf("%s", pc->data[pos].sex);
		printf("�������µ����䣺��");
		scanf("%s", &(pc->data[pos].age));

	}
}

//����ͨѶ¼������
void sort_contact(Contact* pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name)>0)
			{
				PeoInfo temp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
void test()
{
	Contact con = {0};
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			dele_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
////���Ի����Ǵ�˻���С�ˣ�ʹ�������壩
//int check_sys()
//{
//	union U
//	{
//		int i;
//		char c;
//	}u;
//	u.i = 1;
//	return u.c;
//
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}else
//	{
//		printf("���\n");
//	}
//	return 0;
//}