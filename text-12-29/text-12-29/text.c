#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��̬�ڴ����
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



//malloc     ����ռ�     ����Կ��ٵĶ�̬�ռ���г�ʼ����Ч�ʻ��һ��
//free       ���ռ�


//#include <stdlib.h>//malloc����
//#include <string.h>//strerror����
//#include <errno.h>//errno����
//int main()
//{
//	//���ڴ�����10�����οռ�
//	int* p = (int*)malloc(10 * sizeof(int));
//	//��ӡ����
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//����ʹ��
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
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
//	//��Ӧ�û�������ϵͳ
//	free(p);
//	p = NULL;
//	return 0;
//}





//calloc        ��Կ��ٵĶ�̬�ռ���г�ʼ����Ч�ʻ��һ��
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




//realloc   ������̬�ڴ�ռ�Ĵ�С

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
	//���ھ�������ʹ��malloc���ٵ�20���ֽڵĶ�̬�ڴ�
	//����20���ֽڲ�������ʹ�ã�ϣ����40���ֽڵĿռ�
	//ʹ��realloc����������̬�ڴ�ռ�Ŀ���

	//realloc����ʹ��ע������
	//1.���pָ��Ŀռ�����㹻�Ŀռ����׷�ӣ���ֱ��׷�ӣ��󷵻�p
	//2.���pָ��Ŀռ��û���㹻�Ŀռ����׷�ӣ���realloc������������һ���µ��ڴ����򣨶�������
	//  ����һ����������Ŀռ䣬����ԭ�������ݿ����������ͷžɵ��ڴ�ռ䣬��󷵻��¿��ٵ��ڴ�ռ��ַ
	//3.����һ���µı���������realloc�����ķ���ֵ

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

	//�ͷ��ڴ�
	free(p);
	p = NULL;
	return 0;
}