#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <string.h>

void left_rotate(char *stc, int k)
{
	//����K��
	while (k--)
	{
		//����1��
		//�����һ��λ������
		char tmp = *stc;
		char *cur = stc;
		while (*(cur + 1) != '\0')
		{
			//��ǰ�ƶ�һλ
			*cur = *(cur + 1);
			cur++;
		}
		//�ѵ�һ��λ�õ����ݷ���ĩβ
		*cur = tmp;
	}
}
int is_rotate(char *str1,char *str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	int len = strlen(str1);
	while (len--)
	{
		//��תһ��
		left_rotate(str1, 1);
		if (0 == strcmp(str1, str2))
		{
			return 1;
		}
	   //���ݲ�ͬ
		return 0;
	}
}
int main()
{
	char str1[20] = { 0 };
	scanf("%s", str1);
	char str2[20] = { 0 };
	scanf("%s", str2);
	printf("%d\n",is_rotate(str1, str2));
	system("pause");
	return 0;
}