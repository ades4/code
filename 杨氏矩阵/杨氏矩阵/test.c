#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
//�����½ǿ�ʼ�� �ݹ�
//��ʼΪrow-1��0
//����Ϊx>=0, y<=col-1
int Search_L(int arr[3][3], int row, int col, int k,
	int x,int y,int* px, int* py)
{
	//����
	if (x < 0 || y >= col)
	{
		*px = -1;
		*py = -1;
		return 0;
	}
	if (arr[x][y] == k)
	{
		*px = x;
		*py = y;
		return 1;
	}
	else if(arr[x][y] < k)
	{
	//��ǰԪ��С��K��������
		Search_L(arr, 3, 3, k, x, y + 1, px, py);
	}
	if (arr[x][y] > k)
	{
		//��ǰԪ�ش���K��������
		Search_L(arr, 3, 3, k, x - 1, y, px, py);
	}
}
//�����Ͻǿ�ʼ�ң��ݹ�
//��ʼΪ0��col-1
//����x>row��y<0
int Search_R(int arr[3][3],int row,int col,int k,int x,int y,int* px,int* py)
{
	if (x > row || y < 0) 
	{
		*px = -1;
		*py = -1;
		return 0;
	}
	if (arr[x][y] == k)
	{
		*px = x;
		*py = y;
		return 1;
	}
	//��ǰԪ�ش���K��������
	else if (arr[x][y] > k)
	{
		Search_R(arr, 3, 3, k, x - 1, y, px, py);
	}
	else
	{
		//��ǰԪ��С��K��������
		Search_R(arr, 3, 3, k, x, y + 1, px, py);
	}
}
//�����Ͻǿ�ʼ��
int SearchR(int arr[3][3],int row,int col,int k,int* px,int* py)
{
	int i = 0;
	int j = col-1;
	//����Ч�ķ�Χ��Ѱ��
	while (i < row && j >= 0)
	{
		if (arr[i][j] == k)
		{
			*px = i;
			*py = j;
			return 1;
		}
		else if (arr[i][j] < k)
		{
			//��ǰԪ��С��K��������
			i++;
		}
		else
		{
			//��ǰԪ�ش���K��������
			j--;
		}	
	}
	*px = -1;
	*py = -1;
	return 0;
}
//�����½ǿ�ʼ��
int SearchL(int arr[3][3], int row, int col, int k, int* px, int* py)
{
	int i = row-1;
	int j = 0;
	//����Ч�ķ�Χ��Ѱ��
	while (i > 0 && j < col)
	{
		if (arr[i][j] == k)
		{
			*px = i;
			*py = j;
			return 1;
		}
		else if (arr[i][j] < k)
		{
			//��ǰԪ��С��K��������
			j++;
		}
		else
		{
			//��ǰԪ�ش���K��������
			i--;
		}
	}
	*px = -1;
	*py = -1;
	return 0;
}
int main()
{
	int arr[3][3] = { 1 , 2 , 3 ,4, 5, 6 ,7, 8, 9 };
	int pxL, pyL;
	int pxR, pyR;
	int px_L, py_L;
	int px_R, py_R;
	SearchR(arr, 3, 3, 9, &pxL , &pyL);
	printf("%d %d\n", pxL, pyL);
	SearchR(arr, 3, 3, 7, &pxR, &pyR);
	printf("%d %d\n", pxR, pyR);
	Search_L(arr, 3, 3, 5, 2, 0, &px_L, &py_L);
	printf("%d %d\n", px_L, py_L);
	Search_R(arr, 3, 3, 3, 0, 2, &px_R, &py_R);
	printf("%d %d\n", px_R, py_R);
	system("pause");
	return 0;
}