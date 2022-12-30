#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//动态内存分配
// malloc   



//struct S
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	struct S arr[50];
//	return 0;
//}



//malloc     申请空间     不会对开辟的动态空间进行初始化，效率会高一点
//free       还空间


//#include <stdlib.h>//malloc定义
//#include <string.h>//strerror定义
//#include <errno.h>//errno定义
//int main()
//{
//	//向内存申请10个整形空间
//	int* p = (int*)malloc(10 * sizeof(int));
//	//打印错误
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//正常使用
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p+i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候
//	//就应该还给操作系统
//	free(p);
//	p = NULL;
//	return 0;
//}





//calloc        会对开辟的动态空间进行初始化，效率会低一点
//#include <errno.h>
//#include <string.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}




//realloc   调整动态内存空间的大小

#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)malloc(5 * sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
		}
		//for (i = 0; i < 5; i++)
		//{
		//	printf("%d ", *(p + i));
		//}
	}
	//现在就是正在使用malloc开辟的20个字节的动态内存
	//假设20个字节不能满足使用，希望有40个字节的空间
	//使用realloc函数调整动态内存空间的开辟

	//realloc函数使用注意事项
	//1.如果p指向的空间后有足够的空间可以追加，则直接追加，后返回p
	//2.如果p指向的空间后没有足够的空间可以追加，则realloc函数会重新找一个新的内存区域（堆区）来
	//  开辟一块满足需求的空间，并把原来的数据拷贝过来，释放旧的内存空间，最后返回新开辟的内存空间地址
	//3.得用一个新的变量来接受realloc函数的返回值

	int* ptr = realloc(p, 5 * sizeof(int));
	if (ptr != NULL)
	{
		p = ptr;
		int i = 0;
		for (i = 5; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}

	//释放内存
	free(p);
	p = NULL;
	return 0;
}