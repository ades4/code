#define _CRT_SECURE_NO_WARNINGS 1 

#include<stdio.h>
//从左下角开始找 递归
//起始为row-1，0
//出口为x>=0, y<=col-1
int Search_L(int arr[3][3], int row, int col, int k,
	int x,int y,int* px, int* py)
{
	//出口
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
	//当前元素小于K，向右走
		Search_L(arr, 3, 3, k, x, y + 1, px, py);
	}
	if (arr[x][y] > k)
	{
		//当前元素大于K，向上走
		Search_L(arr, 3, 3, k, x - 1, y, px, py);
	}
}
//从右上角开始找，递归
//起始为0，col-1
//出口x>row，y<0
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
	//当前元素大于K，向左走
	else if (arr[x][y] > k)
	{
		Search_R(arr, 3, 3, k, x - 1, y, px, py);
	}
	else
	{
		//当前元素小于K，向下走
		Search_R(arr, 3, 3, k, x, y + 1, px, py);
	}
}
//从右上角开始找
int SearchR(int arr[3][3],int row,int col,int k,int* px,int* py)
{
	int i = 0;
	int j = col-1;
	//在有效的范围里寻找
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
			//当前元素小于K，向下走
			i++;
		}
		else
		{
			//当前元素大于K，向左走
			j--;
		}	
	}
	*px = -1;
	*py = -1;
	return 0;
}
//从左下角开始找
int SearchL(int arr[3][3], int row, int col, int k, int* px, int* py)
{
	int i = row-1;
	int j = 0;
	//在有效的范围里寻找
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
			//当前元素小于K，向右走
			j++;
		}
		else
		{
			//当前元素大于K，向上走
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