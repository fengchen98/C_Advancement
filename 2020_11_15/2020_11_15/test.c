#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//ftell:返回当前位置到起始位置的个数
//rewind:让文件指针的位置回到文件的起始位置
//feof  (不能使用feof函数的返回值直接用来判断文件是否结束)
//文本文件读取是否结束
//如果使用的是fgetc函数，判断返回值是否是EOF
//如果使用的是fgets函数，看返回值是否为NULL
//二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
//fread判断返回值是否小于实际要读的个数

int main()
{
	FILE* pf = fopen("test1.txt", "w");
	if (pf == NULL)
	{
		perror("open file for write");
		return 1;
	}
	fputs("ABCDEF", pf);
	int ret = ftell(pf);
	printf("ret=%d\n", ret);
	fseek(pf, 4, SEEK_SET);
	printf("ret=%d\n", ret);
	//fputc('Q', pf);
	fclose(pf);
	pf = NULL;
	return 0;
}



//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#define MAX_NAME 20
//#define MAX_TELE 12
//#define MAX_ADDR 100
//#define MAX_QQ 12
//#define MAX_SEX 5
//#define DEFAULT_SZ 3
////通讯录
//
////菜单
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
////默认可以存放五个人的信息
//typedef struct Contact
//{
//	PeoInfo *data;//数据
//	int sz;//有效个数
//	int capacity;//通讯录中当前的个数
//
//}Contact;
//
//
////增容
//void check_capacity(Contact* pc)
//{
//	if (pc->sz == pc->capacity)
//	{
//		//增加容量
//		PeoInfo* ptr = realloc(pc->data, (pc->capacity + 2)*sizeof(PeoInfo));
//		if (ptr != NULL)
//		{
//			pc->data = ptr;
//			pc->capacity += 2;
//			printf("增容成功！\n");
//		}
//		else
//		{
//			perror("add_contact realloc");
//			return;
//		}
//	}
//
//}
//
////添加一个人的信息
//void add_contact(Contact * pc)
//{
//	    assert(pc);
//	    check_capacity(pc);
//		printf("请输入名字：》");
//		scanf("%s", pc->data[pc->sz].name);
//		printf("请输入电话：》");
//		scanf("%s", pc->data[pc->sz].tele);
//		printf("请输入地址：》");
//		scanf("%s", pc->data[pc->sz].addr);
//		printf("请输入QQ：》");
//		scanf("%s", pc->data[pc->sz].qq);
//		printf("请输入性别：》");
//		scanf("%s", pc->data[pc->sz].sex);
//		printf("请输入年龄：》");
//		scanf("%d", &(pc->data[pc->sz].age));
//
//		pc->sz++;
//		printf("添加成功\n");
//	
//
//}
//
//
////显示通讯录中的信息
//void show_contact(Contact* pc)
//{
//	int i = 0;
//	printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "qq", "性别");
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
////删除指定的联系人
//void dele_contact(Contact* pc)
//{
//	if (pc->sz == 0)
//	{
//		printf("抱歉，通讯录为空\n");
//	}
//	else
//	{
//		char name[MAX_NAME] = { 0 };
//		printf("请输入名字");
//		scanf("%s", name);
//		//1.先找到指定的联系人的位置
//		int pos = find_peo_by_name(pc, name);
//		if (pos == -1)
//		{
//			printf("删除的人不存在\n");
//		}
//		else
//		{
//			//2.删除
//			int j = 0;
//			for (j = pos; j < pc->sz - 1; j++)
//			{
//				pc->data[j] = pc->data[j + 1];
//			}
//			pc->sz--;
//			printf("删除成功\n");
//		}
//	}
//}
//
////查找指定联系人
//void search_contact(Contact* pc)
//{
//	char name[MAX_NAME] = { 0 };
//	printf("请输入要查找人的名字");
//	scanf("%s", name);
//	int pos = find_peo_by_name(pc, name);
//	if (pos == -1)
//	{
//		printf("查无此人\n");
//	}
//	else
//	{
//		printf("%10s %12s %20s %5s %12s %5s\n", "名字", "电话", "地址", "年龄", "qq", "性别");
//		printf("%10s %12s %20s %5d %12s %5s\n", pc->data[pos].name,
//			pc->data[pos].tele,
//			pc->data[pos].addr,
//			pc->data[pos].age,
//			pc->data[pos].qq,
//			pc->data[pos].sex);
//	}
//}
//
////修改指定联系人的信息
//void modify_contact(Contact * pc)
//{
//	char name[MAX_NAME] = { 0 };
//	printf("请输入要修改人的名字");
//	scanf("%s", name);
//	int pos = find_peo_by_name(pc, name);
//	if (pos == -1)
//	{
//		printf("查无此人\n");
//	}
//	else
//	{
//		printf("请输入新的名字：》");
//		scanf("%s", pc->data[pos].name);
//		printf("请输入新的电话：》");
//		scanf("%s", pc->data[pos].tele);
//		printf("请输入新的地址：》");
//		scanf("%s", pc->data[pos].addr);
//		printf("请输入新的QQ：》");
//		scanf("%s", pc->data[pos].qq);
//		printf("请输入新的性别：》");
//		scanf("%s", pc->data[pos].sex);
//		printf("请输入新的年龄：》");
//		scanf("%s", &(pc->data[pos].age));
//
//	}
//}
//
////排序通讯录的数据
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
//
//////加载通讯录信息
//void load_contact(Contact* pc)
//{
//	PeoInfo tmp = { 0 };
//	FILE* pfRead = fopen("contact.txt", "rb");
//	if (pfRead == NULL)
//	{
//		perror("open file for reading");
//		return;
//	}
//	//加载数据
//	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
//	{
//		check_capacity(pc);
//		pc->data[pc->sz] = tmp;
//		pc->sz++;
//	}
//
//	fclose(pfRead);
//	pfRead = NULL;
//
//}
//
////初始化通讯录
//void InitContact(Contact *pc)
//{
//	
//	pc->sz = 0;
//	pc->capacity = DEFAULT_SZ;
//	pc->data =(PeoInfo*) malloc(DEFAULT_SZ*sizeof(PeoInfo));
//	if (pc->data == NULL)
//	{
//		perror("InitContact malloc");
//		return ;
//	}	
//	load_contact(pc);
//}
//
//
//
//
////销毁通讯录
//void destory_contact(Contact * pc)
//{
//
//	free(pc->data);
//	pc->data = NULL;
//	pc->capacity = 0;
//	pc->sz = 0;
//}
//
////保存通讯录到文件
//void save_contact(Contact* pc)
//{
//	int i = 0;
//	FILE* pfWerite = fopen("contact.txt", "wb");
//	if (pfWerite == NULL)
//	{
//		perror("open file for write");
//		return;
//	}
//	//写数据
//	for (i = 0; i < pc->sz; i++)
//	{
//		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWerite);
//	}
//	//关闭文件
//	fclose(pfWerite);
//	pfWerite = NULL;
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
//		printf("请选择：");
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
//			save_contact(&con);
//			destory_contact(&con);
//			printf("退出通讯录\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//}
//int main()
//{
//	test();
//	return 0;
//}



//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//
//};
//
//int main()
//{
//	struct Stu s = { 0};
//	FILE* pf = fopen("text.dat", "rb");
//	if (pf == NULL)
//	{
//		perror("open file for reading");
//		return 1;
//	}
//
//	//读文件
//	fread(&s, sizeof(struct Stu), 1, pf);
//	printf("%s %d %f", s.name, s.age, s.score);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	struct Stu s = { "张三", 20, 90.5f };
//	FILE* pf = fopen("text.dat", "wb");
//	if (pf == NULL)
//	{
//		perror("open file for writing");
//		return 1;
//	}
//
//	//写文件
//	fwrite(&s, sizeof(struct Stu), 1,pf);
//
//	//关闭文件
//	fclose(pf); 
//	pf = NULL;
//	return 0;
//}