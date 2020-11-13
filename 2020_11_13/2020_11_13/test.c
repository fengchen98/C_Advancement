#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//寻找单身狗
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	//外循环：每次选取一个元素
	for (i = 0; i < size; i++)
	{
		//内循环：将其他元素与选取的那个元素进行比较
		for (j = 0; j < size; j++)
		{
			if (i != j && arr[i] == arr[j])
			{
				break;
			}
		}
		//来到这里有两种情况：（1）有与之相同的元素（break执行）（2）遍历完毕也没有找到相同元素，这时j==size
		if (j == size)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}



//简单计算器
//int main()
//{
//	double a;
//	double b;
//	double ret;
//	char c;
//	scanf("%lf%c%lf", &a, &c, &b);
//	switch (c)
//	{
//	case '+':
//		ret = a + b;
//		printf("%0.4lf+%0.4lf=%0.4lf", a, b, ret);
//		break;
//	case '-':
//		ret = a - b;
//		printf("%0.4lf-%0.4lf=%0.4lf", a, b, ret);
//		break;
//	case '*':
//		ret = a*b;
//		printf("%0.4lf*%0.4lf=%0.4lf", a, b, ret);
//		break;
//	case '/':
//		if (b == 0.0)
//		{
//			printf("Wrong!Division by zero!");
//			break;
//		}
//		else
//		{
//			ret = a / b;
//			printf("%0.4lf/%0.4lf=%0.4lf", a, b, ret);
//			break;
//		}
//
//	default:
//		printf("Invalid operation!");
//		break;
//
//	}
//	return 0;
//}
