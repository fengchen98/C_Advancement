#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
////strstr的模拟实现
//char *my_strstr(const char* str1, const char* str2)
//{
//	assert(str1);
//	assert(str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* cp = str1;
//	if (*s2 == '\0')
//	{
//		return (char*)str1;
//	}
//	while (*s1 && *s2 && *cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while(*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp ++;  
//	}
//	return NULL;
//}
//
//int main()
//{
//	char arr[] = "abcdedeafa";
//	char* ret = my_strstr(arr, "cded");
//	if (ret != NULL)
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}



////strcat的模拟实现
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//先找到目的地空间的‘\0’
//	while (*dest)
//	{
//		dest++;
//	}
//	//追加
//	while (*dest++ = *src++);
//	return ret;
//}
//int main()
//{
//	char str1[20] = "hello ";
//	printf("%s\n", my_strcat(str1, "world"));
//}








////strlen的模拟实现
//int my_strlen(const char* str)
//{
//	assert(str);
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char str[] = "abcdefg";
//	int ret = my_strlen(str);
//	printf("%d\n", ret);
//	return 0;
//}



////strcmp的模拟实现
//int my_strcmp(const char * str1, const char * str2)
//{
//	int ret = 0;
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1 && *str2)
//	{
//		if (*str1 > *str2)
//		{
//			return 1;
//		}
//		else if (*str1 < *str2)
//		{
//			return -1;
//		}
//		else
//		{
//			++str1;
//			++str2;
//		}
//	}
//
//	if (*str1)
//		return 1;
//	else if (*str2)
//		return -1;
//	else
//		return 0;
//
//}
//int main()
//{
//	char str1[] = "abccde";
//	char str2[] = "abccd";
//	int ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);
//	return 0;
//}



////strcpy的模拟实现
//char* my_strcpy(char* dest, const char*src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*src)
//	{
//		*dest = *src;
//		src++;
//		dest++;
//	}
//	*dest = '\0';
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[20];
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}




//memmove的模拟实现
void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	if (dest < src)
	{
		//从前向后拷贝
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
}
int main(){
	char str[100] = "hello world";
	my_memmove(str + 6, str, 12);
	printf("%s\n", str);
	return 0;
}


////memcpy的模拟实现
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest);
//	assert(src);
//	while (count--)
//	{
//		//拷贝一个字节
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	for (int i = 0; i < 5; ++i){
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}



//int main()
//{
//	int i = 0;
//	char str[] = "Test String.\n";
//	char c;
//	while (str[i])
//	{
//		c = str[i];
//		if (isupper(c))
//		{
//			c = tolower(c);
//		}
//		putchar(c);
//		i++;
//	}
//	return 0;
//}


//int main()
//{
//	char c = 'A';
//	printf("%c\n", tolower(c));
//	return 0;
//}


//int main()
//{
//	char c = 'z';
//	int ret = islower(c);
//	printf("%d\n", ret);
//	return 0;
//}