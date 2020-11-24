#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//void  bubble_sort(int* arr, int num)
//{
//	int i = 0, j = 0;
//	for (i = 0; i<num - 1; i++)
//	{
//		for (j = 0; j<num - i - 1; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tem = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tem;
//			}
//		}
//	}
//}
//void print(int* arr, int num)
//{
//	int i = 0;
//	for (i = 0; i<num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int num = 0;
//	int arr[1000];
//	scanf("%d", &num);
//	for (i = 0; i<num; i++)
//	{
//		scanf("%d ", arr[i]);
//	}
//	for (i = 0; i<num; i++)
//	{
//		for (j = i + 1; j<num - i; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				arr[j] = arr[j + 1];
//			}
//		}
//	}
//	bubble_sort(arr, num);
//	print(arr, num);
//	return 0;
//}

//
//void  bubble_sort(int* arr, int num)
//{
//	int i = 0, j = 0;
//	for (i = 0; i<num - 1; i++)
//	{
//		for (j = 0; j<num - i - 1; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tem = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tem;
//			}
//		}
//	}
//}
//void print(int* arr, int num)
//{
//	int i = 0;
//	for (i = 0; i<num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 84, 31, 64, 413, 16, 4, 131, 14 };
//	bubble_sort(arr, 10);
//	print(arr, 10);
//}

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int num = 0;
//	int arr[1000];
//	scanf("%d", &num);
//	for (i = 0; i<num; i++)
//	{
//		scanf("%d", arr[i]);
//	}
//	for (i = 0; i<num; i++)
//	{
//		for (j = i + 1; j<num; j++)
//		{
//			if (arr[i]>arr[j])
//			{
//				int tmp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//			}
//			if (arr[i] == arr[j])
//			{
//				arr[j] = -1;
//			}
//		}
//	}
//	for (i = 0; i<num; i++)
//	{
//		if (arr[i] >= 0)
//		{
//			printf("%d ", arr[i]);
//
//		}
//	}
//	return 0;
//}


//给定一个整数序列，KiKi想把其中的重复的整数去掉，并将去重后的序列从小到达排序输出
#include<stdio.h>
int main()
{
	int n, i, j, a[1000], t;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i<n; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (a[i]>a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			if (a[i] == a[j])
			{
				a[j] = -1;
			}
		}
	}
	for (i = 0; i<n; i++)
	{
		if (a[i] >= 0)
			printf("%d ", a[i]);
	}
}