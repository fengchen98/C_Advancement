#define _CRT_SECURE_NO_WARNINGS 1
//��ȱ��������
#include<stdio.h>
#include<stdlib.h>
#define length 16

int maze[length][length] = { 0 };
int x0 = 4, y0 = 8;
int n = 1;

int search(int LUX, int LUY, int RDX, int RDY)//������ȱ�����ĸ�����
{
	int i, j;
	for (i = LUX; i <= RDX; i++)
	{
		for (j = LUY; j <= RDY; j++)
		{
			if (maze[i][j] != 0)
				goto LOOP;
		}
	}
LOOP:
	if (i <LUX + (RDX - LUX + 1) / 2)
	{
		if (j < LUY + (RDX - LUX + 1) / 2)
			return 1;
		else
			return 2;
	}
	else
	{
		if (j < LUY + (RDX - LUX + 1) / 2)
			return 3;
		else
			return 4;
	}
}

void breach(int LUX, int LUY, int RDX, int RDY, int len)//�ݹ���亯��
{
	if (len == 1)//����
		return;
	n++;
	if (search(LUX, LUY, RDX, RDY) == 1)//����
	{
		maze[LUX + len][LUY + len] = n;
		maze[LUX + len][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len] = n;
	}
	else if (search(LUX, LUY, RDX, RDY) == 2)//����
	{
		maze[LUX + len][LUY + len] = n;
		maze[LUX + len][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len - 1] = n;
	}
	else if (search(LUX, LUY, RDX, RDY) == 3)//����
	{
		maze[LUX + len][LUY + len] = n;
		maze[LUX + len - 1][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len] = n;
	}
	else if (search(LUX, LUY, RDX, RDY) == 4)//����
	{
		maze[LUX + len - 1][LUY + len - 1] = n;
		maze[LUX + len][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len] = n;
	}
	breach(LUX, LUY, LUX + len - 1, LUY + len - 1, len / 2);//��������
	breach(LUX, LUY + len, LUX + len - 1, RDY, len / 2);//��������
	breach(LUX + len, LUY, RDX, LUY + len - 1, len / 2);//��������
	breach(LUX + len, LUY + len, RDX, RDY, len / 2);//��������
}
void out()//���һ����亯��
{
	for (int i = 0; i < length - 1; i = i + 2)
	{
		for (int j = 0; j < length - 1; j = j + 2)
		{
			n++;
			if (maze[i][j] == 0)
				maze[i][j] = n;
			if (maze[i + 1][j] == 0)
				maze[i + 1][j] = n;
			if (maze[i][j + 1] == 0)
				maze[i][j + 1] = n;
			if (maze[i + 1][j + 1] == 0)
				maze[i + 1][j + 1] = n;
		}
	}
}
int main()
{
	maze[x0][y0] = 1;//��ʼ��ȱ����λ��
	breach(0, 0, 15, 15, 8);
	//out();
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			printf("%2d ", maze[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
////2�Ĵ��ݱ�ʾ
//void fun(int n)
//{
//	int s = 1;//2�Ĵη���ֵ
//	int t = 0;//ָ��
//	if (n == 1)//����1��ֱ�����
//	{
//		printf("2(0)");
//		return;
//	}
//	if (n == 2)//����2��ֱ�����
//	{
//		printf("2");
//		return;
//	}
//
//	while (s <= n)//ͨ������s*2�ҳ�����nʱ��ָ��
//	{
//		s = s * 2;
//		t++;
//	}
//	t = t - 1;
//	if (n == s / 2)			//n�պ�Ϊ2��ĳ�η���ֵ
//	{
//		printf("2(");
//		fun(t);			//��һ������ָ��
//		printf(")");
//	}
//	else				//����ʣ�µ�ֵ
//	{
//		if (s / 2 == 2)
//		{
//			printf("2");
//			printf("+");
//			fun(n - s / 2);
//		}
//		else
//		{
//			printf("2(");
//			fun(t);
//			printf(")+");
//			fun(n - s / 2);
//		}
//	}
//}
//
//int main()
//{
//	int n, x = 0;
//	
//		printf("������������");
//		scanf("%d", &n);
//		fun(n);
//	return 0;
//}
//
