#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <string.h>

void reverse_string(char *arr)
{
	if (*arr)
	{
		int len = strlen(arr);
		char tmp = arr[0];		//�����һλ���ַ�
		arr[0] = arr[len - 1];		//��һλ�����һλ��������
		arr[len - 1] = '\0';
		return reverse_string(arr++);
		arr[len - 1] = tmp;
	}
}
int main()
{
	char arr[] = "abcde" ;
	reverse_string(arr);
	printf("%s", arr);
	system("pause");
	return 0;
}


