#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//Ѱ�ҵ���
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	//��ѭ����ÿ��ѡȡһ��Ԫ��
	for (i = 0; i < size; i++)
	{
		//��ѭ����������Ԫ����ѡȡ���Ǹ�Ԫ�ؽ��бȽ�
		for (j = 0; j < size; j++)
		{
			if (i != j && arr[i] == arr[j])
			{
				break;
			}
		}
		//���������������������1������֮��ͬ��Ԫ�أ�breakִ�У���2���������Ҳû���ҵ���ͬԪ�أ���ʱj==size
		if (j == size)
		{
			printf("%d ", arr[i]);
		}
	}

	return 0;
}



//�򵥼�����
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
