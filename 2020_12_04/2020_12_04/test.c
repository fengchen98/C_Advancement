#define _CRT_SECURE_NO_WARNINGS 1
//残缺棋盘问题
#include<stdio.h>
#include<stdlib.h>
#define length 16

int maze[length][length] = { 0 };
int x0 = 4, y0 = 8;
int n = 1;

int search(int LUX, int LUY, int RDX, int RDY)//搜索残缺棋在哪个区域
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

void breach(int LUX, int LUY, int RDX, int RDY, int len)//递归填充函数
{
	if (len == 1)//出口
		return;
	n++;
	if (search(LUX, LUY, RDX, RDY) == 1)//左上
	{
		maze[LUX + len][LUY + len] = n;
		maze[LUX + len][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len] = n;
	}
	else if (search(LUX, LUY, RDX, RDY) == 2)//右上
	{
		maze[LUX + len][LUY + len] = n;
		maze[LUX + len][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len - 1] = n;
	}
	else if (search(LUX, LUY, RDX, RDY) == 3)//左下
	{
		maze[LUX + len][LUY + len] = n;
		maze[LUX + len - 1][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len] = n;
	}
	else if (search(LUX, LUY, RDX, RDY) == 4)//右下
	{
		maze[LUX + len - 1][LUY + len - 1] = n;
		maze[LUX + len][LUY + len - 1] = n;
		maze[LUX + len - 1][LUY + len] = n;
	}
	breach(LUX, LUY, LUX + len - 1, LUY + len - 1, len / 2);//左上区域
	breach(LUX, LUY + len, LUX + len - 1, RDY, len / 2);//右上区域
	breach(LUX + len, LUY, RDX, LUY + len - 1, len / 2);//左下区域
	breach(LUX + len, LUY + len, RDX, RDY, len / 2);//右下区域
}
void out()//最后一步填充函数
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
	maze[x0][y0] = 1;//初始残缺棋子位置
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
////2的次幂表示
//void fun(int n)
//{
//	int s = 1;//2的次方的值
//	int t = 0;//指数
//	if (n == 1)//若是1则直接输出
//	{
//		printf("2(0)");
//		return;
//	}
//	if (n == 2)//若是2则直接输出
//	{
//		printf("2");
//		return;
//	}
//
//	while (s <= n)//通过不断s*2找出大于n时的指数
//	{
//		s = s * 2;
//		t++;
//	}
//	t = t - 1;
//	if (n == s / 2)			//n刚好为2的某次方的值
//	{
//		printf("2(");
//		fun(t);			//进一步计算指数
//		printf(")");
//	}
//	else				//计算剩下的值
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
//		printf("请输入整数：");
//		scanf("%d", &n);
//		fun(n);
//	return 0;
//}
//
