#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
enum State
{
	VALID,
	INVALID
}stata=VALID;
long long  my_atoi(const char * p)
{
	int flag = 1;
	stata = INVALID;

	//��ָ�봦��
	if (p == NULL)
		return 0;
	

	//�հ��ַ��Ĵ���
	while (isspace(*p))
	{
		p++;
	}

	if (*p == '+')
	{
		flag = 1;
		p++;
	}	
	else if (*p == '-')
	{
		flag = -1;
		p++;
	}
	
	long long ret = 0;
	while (*p!='\0')
	{
		if (isdigit(*p) == 0)
		{
			break;
		}
		else
		{
			ret = ret * 10 + flag * (*p - '0');
			p++;
		}
		
	}
	return ret;
}

int main()
{
	char* p = "123456";
	long long ret=my_atoi(p);
	printf("%lld\n", ret);

	return 0;
}



////��������
//struct S
//{
//	int num;
//	char arr[];//���������Ա
//};
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S) + 6);
//	p->num = 100;
//	int i = 0;
//	for (i = 0; i < 6; i++)
//	{
//		p->arr[i] = 'a' + i;
//
//	}
//	for (i = 0; i < 6; i++)
//	{
//		printf("%c ", p->arr[i]);
//
//	}
//	struct S* ptr = realloc(p, 14);
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		p->arr[i] = 'x';
//
//	}
//	for (i = 0; i < 6; i++)
//	{
//		printf("%c ", p->arr[i]);
//
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}




//#include <string.h>
//#include <stdlib.h>
//#define MAX_NAME 20
//#define MAX_TELE 12
//#define MAX_ADDR 100
//#define MAX_QQ 12
//#define MAX_SEX 5
//#define DEFAULT_SZ 3
//
//
////ͨѶ¼
//
////�˵�
//void menu()
//{
//	printf("********************************************\n");
//	printf("**********1.add         2.del    ***********\n");
//	printf("**********3.search      4.modify ***********\n");
//	printf("**********5.sort        6.show   ***********\n");
//	printf("**********         0.exit        ***********\n");
//	printf("********************************************\n");
//}
//
//
//enum Option
//{
//	EXIT,
//	ADD,
//	DEL,
//	SEARCH,
//	MODIFY,
//	SORT,
//	SHOW
//};
//
//typedef struct PeoInfo
//{
//	char name[MAX_NAME];
//	char tele[MAX_TELE];
//	char addr[MAX_ADDR];
//	char qq[MAX_QQ];
//	char sex[MAX_SEX];
//	short age;
//}PeoInfo;
//
////Ĭ�Ͽ��Դ������˵���Ϣ
//typedef struct Contact
//{
//	PeoInfo *data;//����
//	int sz;//��Ч����
//	int capacity;//ͨѶ¼�е�ǰ�ĸ���
//
//}Contact;
//
//
////���һ���˵���Ϣ
//void add_contact(Contact * pc)
//{
//	if (pc->sz == pc->capacity)
//	{
//		//��������
//		PeoInfo* ptr = realloc(pc->data, (pc->capacity + 2)*sizeof(PeoInfo));
//		if (ptr != NULL)
//		{
//			pc->data = ptr;
//			pc->capacity += 2;
//			printf("���ݳɹ���\n");
//		}
//		else
//		{
//			perror("add_contact realloc");
//			return;
//		}
//	}
//	
//		printf("���������֣���");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("������绰����");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("�������ַ����");
//		scanf("%s", pc->data[pc->sz].addr);
//		printf("������QQ����");
//		scanf("%s", pc->data[pc->sz].qq);
//		printf("�������Ա𣺡�");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("���������䣺��");
//		scanf("%d", &(pc->data[pc->sz].age));
//
//		pc->sz++;
//		printf("��ӳɹ�\n");
//	
//
//}
//
//
////��ʾͨѶ¼�е���Ϣ
//void show_contact(Contact* pc)
//{
//	int i = 0;
//	printf("%10s %12s %20s %5s %12s %5s\n", "����", "�绰", "��ַ", "����", "qq", "�Ա�");
//	for (i = 0; i < pc->sz; i++)
//	{
//		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[i].name,
//			pc->data[i].tele,
//			pc->data[i].addr,
//			pc->data[i].age,
//			pc->data[i].qq,
//			pc->data[i].sex);
//	}
//}
//
//int find_peo_by_name(Contact* pc, char name[])
//{
//	int i = 0;
//	for (i = 0; i < pc->sz; i++)
//	{
//		if (strcmp(name, pc->data[i].name) == 0)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//
////ɾ��ָ������ϵ��
//void dele_contact(Contact* pc)
//{
//	if (pc->sz == 0)
//	{
//		printf("��Ǹ��ͨѶ¼Ϊ��\n");
//	}
//	else
//	{
//		char name[MAX_NAME] = { 0 };
//		printf("����������");
//		scanf("%s", name);
//		//1.���ҵ�ָ������ϵ�˵�λ��
//		int pos = find_peo_by_name(pc, name);
//		if (pos == -1)
//		{
//			printf("ɾ�����˲�����\n");
//		}
//		else
//		{
//			//2.ɾ��
//			int j = 0;
//			for (j = pos; j < pc->sz - 1; j++)
//			{
//				pc->data[j] = pc->data[j + 1];
//			}
//			pc->sz--;
//			printf("ɾ���ɹ�\n");
//		}
//	}
//}
//
////����ָ����ϵ��
//void search_contact(Contact* pc)
//{
//	char name[MAX_NAME] = { 0 };
//	printf("������Ҫ�����˵�����");
//	scanf("%s", name);
//	int pos = find_peo_by_name(pc, name);
//	if (pos == -1)
//	{
//		printf("���޴���\n");
//	}
//	else
//	{
//		printf("%10s %12s %20s %5s %12s %5s\n", "����", "�绰", "��ַ", "����", "qq", "�Ա�");
//		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
//			pc->data[pos].tele,
//			pc->data[pos].addr,
//			pc->data[pos].age,
//			pc->data[pos].qq,
//			pc->data[pos].sex);
//	}
//}
//
////�޸�ָ����ϵ�˵���Ϣ
//void modify_contact(Contact * pc)
//{
//	char name[MAX_NAME] = { 0 };
//	printf("������Ҫ�޸��˵�����");
//	scanf("%s", name);
//	int pos = find_peo_by_name(pc, name);
//	if (pos == -1)
//	{
//		printf("���޴���\n");
//	}
//	else
//	{
//		printf("�������µ����֣���");
//		scanf("%s", pc->data[pos].name);
//		printf("�������µĵ绰����");
//		scanf("%s", pc->data[pos].tele);
//		printf("�������µĵ�ַ����");
//		scanf("%s", pc->data[pos].addr);
//		printf("�������µ�QQ����");
//		scanf("%s", pc->data[pos].qq);
//		printf("�������µ��Ա𣺡�");
//		scanf("%s", pc->data[pos].sex);
//		printf("�������µ����䣺��");
//		scanf("%s", &(pc->data[pos].age));
//
//	}
//}
//
////����ͨѶ¼������
//void sort_contact(Contact* pc)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < pc->sz - 1; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < pc->sz - 1 - i; j++)
//		{
//			if (strcmp(pc->data[j].name, pc->data[j + 1].name)>0)
//			{
//				PeoInfo temp = pc->data[j];
//				pc->data[j] = pc->data[j + 1];
//				pc->data[j + 1] = temp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
////��ʼ��ͨѶ¼
//void InitContact(Contact *pc)
//{
//	pc->sz = 0;
//	pc->capacity = DEFAULT_SZ;
//	pc->data =(PeoInfo*) malloc(DEFAULT_SZ*sizeof(PeoInfo));
//	if (pc->data == NULL)
//	{
//		perror("InitContact malloc");
//		return ;
//	}
//}
//
//
////����ͨѶ¼
//void destory_contact(Contact * pc)
//{
//
//	free(pc->data);
//	pc->data = NULL;
//	pc->capacity = 0;
//	pc->sz = 0;
//}
//
//
//void test()
//{
//	Contact con = { 0 };
//	InitContact(&con);
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case ADD:
//			add_contact(&con);
//			break;
//		case DEL:
//			dele_contact(&con);
//			break;
//		case SEARCH:
//			search_contact(&con);
//			break;
//		case MODIFY:
//			modify_contact(&con);
//			break;
//		case SORT:
//			sort_contact(&con);
//			break;
//		case SHOW:
//			show_contact(&con);
//			break;
//		case EXIT:
//			destory_contact(&con);
//			printf("�˳�ͨѶ¼\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//}
//int main()
//{
//	test();
//	return 0;
//}