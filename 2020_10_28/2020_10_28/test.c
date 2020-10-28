#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
//strlen的模拟实现
int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char str[] = "abcdefg";
	int ret = my_strlen(str);
	printf("%d\n", ret);
	return 0;
}



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




////memmove的模拟实现
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest);
//	assert(src);
//	if (dest < src)
//	{
//		//从前向后拷贝
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//}


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