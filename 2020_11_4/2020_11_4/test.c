#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ 12
#define MAX_SEX 5
#define MAX 1000


//通讯录

//菜单
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
	PeoInfo data[MAX];//数据
	int sz;//有效个数

}Contact;


//添加一个人的信息
void add_contact(Contact * pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满\n");
	}
	else{
    printf("请输入名字：》");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入电话：》");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址：》");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入QQ：》");
	scanf("%s", pc->data[pc->sz].qq);
	printf("请输入性别：》");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄：》");
	scanf("%d", &(pc->data[pc->sz].age));

	pc->sz++;
	printf("添加成功\n");
	}
	
}


//显示通讯录中的信息
void show_contact(Contact* pc)
{
	int i = 0;
	printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "qq", "性别");
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


//删除指定的联系人
void dele_contact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("抱歉，通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入名字");
		scanf("%s", name);
		//1.先找到指定的联系人的位置
		int pos=find_peo_by_name(pc,name);
		if (pos == -1)
		{
			printf("删除的人不存在\n");
		}
		else
		{
		//2.删除
			int j = 0;
			for (j = pos; j < pc->sz-1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("删除成功\n");
		}	
	}
}

//查找指定联系人
void search_contact(Contact* pc)
{
	char name[MAX_NAME] = {0};
	printf("请输入要查找人的名字");
	scanf("%s", name);
	int pos=find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "qq", "性别");
		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].qq,
			pc->data[pos].sex);
	}
}

//修改指定联系人的信息
void modify_contact(Contact * pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入新的名字：》");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的电话：》");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的地址：》");
		scanf("%s", pc->data[pos].addr);
		printf("请输入新的QQ：》");
		scanf("%s", pc->data[pos].qq);
		printf("请输入新的性别：》");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的年龄：》");
		scanf("%s", &(pc->data[pos].age));

	}
}

//排序通讯录的数据
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
		printf("请选择：");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
////测试机器是大端还是小端（使用联合体）
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
//		printf("小端\n");
//	}else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}