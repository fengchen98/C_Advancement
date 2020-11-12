#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	FILE* pfRead = fopen("test1.txt", "r");
	if (pfRead == NULL)
		{
			perror("open file for reading");
			return 1;
		}

	FILE* pfWrite = fopen("test2.txt", "w");
	if (pfWrite == NULL)
	{
		perror("open file for writing");
		fclose(pfRead);
		return 1;
	}

	//����
	int ch = 0;
	while ((ch = fgetc(pfRead)) != EOF)
	{
		fputc(ch, pfWrite);
	}


	fclose(pfRead);
	pfRead = NULL;
	fclose(pfWrite);
	pfWrite = NULL;
	return 0;
}


//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fputs("Hello World", pf);
//	fputs("Hello FC", pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//	fputc('d', pf);
//	fputc('e', pf);
//	fputc('f', pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}




//#include <stdio.h>
//#include <ctype.h>
//#include <limits.h>
////���ַ�������ת��Ϊ���͵�����
//enum State
//{
//	VALID,
//	INVALID
//}state = VALID;
//long long  my_atoi(const char * p)
//{
//	int flag = 1;
//	state = INVALID;
//
//	//��ָ�봦��
//	if (p == NULL)
//		return 0;
//
//	if (*p == '\0')
//		return 0;
//
//	//�հ��ַ��Ĵ���
//	while (isspace(*p))
//	{
//		p++;
//	}
//
//	if (*p == '+')
//	{
//		flag = 1;
//		p++;
//	}
//	else if (*p == '-')
//	{
//		flag = -1;
//		p++;
//	}
//
//	long long ret = 0;
//	while (isdigit(*p))
//	{
//		
//		ret = ret * 10 + flag * (*p - '0');
//		p++;
//		if (ret > INT_MAX || ret < INT_MIN)
//		{
//			ret = 0;
//			return ret;
//		}
//
//	}
//	if (*p == '\0')
//	{
//		state = VALID;
//		return ret;
//	}
//	return ret;
//}
//
//int main()
//{
//	char* p = "-123456";
//	long long ret = my_atoi(p);
//	if (state == VALID)
//	{
//		printf("%lld\n", ret);
//	}
//	return 0;
//}