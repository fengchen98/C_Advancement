#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
int main()
{
	struct S
	{
		char c1;
		char c2;
		int i;
	};
	printf("%d\n", sizeof(struct S));
	return 0;
}
//int main()
//{
//	char* info="17140216;80.845,90.55,100.00";
//	char id[128];
//	char score[128];
//	//gets(info);
//	//printf("%s", info);
//	char* end = strstr(info, ";");
//	strncpy(id, info, end - info);
//	id[end - info] = '\0';
//	char* end2 = info + strlen(info);
//	strncpy(score, end + 1, end2 - end - 1);
//	score[end2 - end - 1] = '\0';
//	printf("The each subject score of  No.%s is%s", id, score);
//	return 0;
//}




////十六进制转十进制
//long trans(char *s)
//{
//	int i, t;            
//	long sum = 0;
//	for (i = 0; s[i]; i++)
//	{
//		if (s[i] >= '0'&&s[i] <= '9')
//			t = s[i] - '0';       
//		if (s[i] >= 'a'&&s[i] <= 'z')
//			t = s[i] - 'a' + 10;
//		if (s[i] >= 'A'&&s[i] <= 'Z')
//			t = s[i] - 'A' + 10;
//		sum = sum * 16 + t;
//	}
//	return sum;
//}
//int main()
//{
//	int m;
//	char s[20];      
//	printf("Enter 16进制数：");
//	scanf("%s", s);      
//	m = trans(s);
//	printf("%15d", m);
//}