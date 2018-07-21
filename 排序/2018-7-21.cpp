#include "stdafx.h"
#include<iostream>

using namespace std;

//1.插入排序
//时间复杂度：平均O(n2)，最好O(n)，最坏O(n2)
//空间复杂度：O(1)
//稳定性：稳定

void insertSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; ++i)
	{
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
	}
}

//2.希尔排序
//时间复杂度：平均O(n1.3),最好O(n),最坏O(n2)
//空间复杂度：O(1)
//稳定性：不稳定
void shellSort(int a[], int n)
{
	int d, i, j, x;
	d = n / 2;
	while (d >= 1)
	{
		for (i = d;i<n;++i)
		{
			x = a[i];
			j = i - d;
			while (j>=0 && a[j]>x)
			{
				a[j + d] = a[j];
				j = j - d;
			}
			a[j + d] = x;
		}
		d = d / 2;
	}
}

//3.选择排序
//时间复杂度：平均O(n2)，最好O(n2)，最坏O(n2)
//空间复杂度：O(1)
//稳定性：不稳定
void selectSort(int a[], int n)
{
	int t, k;
	for (int i = 0;i < n-1;i++)
	{
		k = i;
		for (int j = i+1;j<n;++j)
		{
			if (a[k] > a[j])
				k = j;
		}
		t = a[i];
		a[i] = a[k];
		a[k] = t;
	}
}

//4.堆排序
//时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(nlogn)
//空间复杂度：O(1)
//稳定性：不稳定

void shift(int k[], int i, int n) //这个函数就是求三个节点中最大的。
{
	int j;
	int temp = k[i];//i个节点对应的数组值
	j = 2 * i;//左孩的下标
	while (j <= n)
	{
		if (j < n&&k[j] < k[j + 1])
			j++;              //右孩大
		if (temp > k[j])        //父节点大
			break;            //实际上发现只做一次循环，才能用break，否则应该用continue
		k[j / 2] = k[j];      //大的赋给节点
		j = j * 2;
	}
	k[j / 2] = temp;
}

void  heapSortInt(int k[], int n)//这个函数实现建堆和排序交换后的调整
{
	for (int i = n / 2; i > 0; i--)  //建堆
		shift(k, i, n);
	for (int j = n; j > 0; j--)
	{
		int temp = k[j];
		k[j] = k[1];
		k[1] = temp;
		shift(k, 1, j - 1); //对发生变化的第一个节点调整
	}
}


//5.冒泡排序
//时间复杂度：平均O(n2)，最好O(n)，最坏O(n2)
//空间复杂度：O(1)
//稳定性：稳定
void BubbleSort1(int arr[], int len)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}//没有优化的方法，比较常规；

//改进版冒泡排序
void BubbleSort2(int arr[], int len)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < len - 1; i++)
	{
		int flag = 1;//假定每次进入都是有序的 flag为1；
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 0;//如果发生交换，则flag 置为0；
			}
		}
		if (flag == 1)//如果这趟走完，没有发生交换，则原数组有序；
			break;
	}
}//加入标志位优化；



//6.快速排序
//时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(n2)
//空间复杂度：O(nlogn)
//稳定性：不稳定
void quicksort(int arr[], int l, int r)
{
	if (l<r)
	{
		int pivot = partition(arr, l, r);
		quicksort(arr, l, pivot-1);
		quicksort(arr, r, pivot + 1);
	}
}
int partition(int arr[], int l, int r)
{
	int k = l, pivot = arr[r];
	for (int i = l;i<r;++i)
	{
		if (arr[i]<pivot)
		{
			swap(arr[i], arr[k++]);
		}
	}
	swap(arr[k], arr[r]);
	return k;
}

//7.归并排序
//时间复杂度：平均O(nlogn)，最好O(nlogn)，最坏O(nlogn)
//空间复杂度：O(1)
//稳定性：稳定
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i<=m && j<=n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}

void mergesort(int a[], int first, int last, int temp[])
{
	if (first<last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);
		mergesort(a, mid + 1, last, temp);
		mergearray(a, first, mid, last, temp);
	}
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p==NULL)
	{
		return false;
	}
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

