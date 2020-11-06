#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{

	return 0;
}


////realloc的使用
//int main()
//{
//	int *p = (int *)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		p[i] = i + 1;
//	}
//	//调整空间大小
//	int *ptr=(int *)realloc(p, 20 * sizeof(int));
//	if (ptr == NULL)
//	{
//		perror("realloc");
//	}
//	else
//	{
//		p = ptr;
//		ptr = NULL;
//	}
//	for (i = 10; i < 20; i++)
//	{
//		p[i] = i + 1;
//	}
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ",p[i]);
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//calloc函数的使用
//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		perror("calloc");
//		return 0;
//	}
//	int i = 0;
//	for (i = 0; i <10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//malloc函数的使用
//int main()
//{
//	int* p = (int*)malloc(100);
//	if (p == NULL)
//	{
//		perror("malloc");
//	}
//	else
//	{
//		int i = 0;
//		for (i=0; i < 25; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i=0; i < 25; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//		//回收内存（释放内存）
//		free(p);
//		p = NULL;
//	}
//	return 0;
//}