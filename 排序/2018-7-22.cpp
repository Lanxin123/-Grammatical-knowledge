#include "stdafx.h"
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

void insertSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; ++i)
	{
		t = a[i];
		for (j = i - 1; j >= 0 && t < a[j]; --j)//j=0进入 --j j为负值
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
	}
}

void shellSort(int a[], int n)
{
	int d, i, j, x;
	d = n / 2;
	while (d >= 1)
	{
		for (i = d; i < n; ++i)
		{
			x = a[i];
			j = i - d;
			while (j >= 0 && a[j] > x)
			{
				a[j + d] = a[j];
				j = j - d;
			}
			a[j + d] = x;
		}
		d = d / 2;
	}
}

void selectSort(int a[], int n)
{
	int t, k;
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[k] > a[j])
				k = j;
		}
		swap(a[i], a[k]);
	}
}

void shift(int k[], int i, int n)
{
	int j;
	int temp = k[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n&&k[j] < k[j + 1])
			j++;
		if (temp > k[j])
			break;
		k[j / 2] = k[j];
		j = j * 2;
	}
	k[j / 2] = temp;
}

void heapSortInt(int k[], int n)
{
	for (int i = n / 2; i > 0; i--)
		shift(k, i, n);
	for (int j = n;j>0;j--)
	{
		swap(k[j], k[1]);
		shift(k, 1, j - 1);
	}
}

void BubbleSort1(int arr[], int len)
{
	int i = 0;
	int j = 0;
	
	for (i = 0;i<len-1;i++)
	{
		for (j = 0;j<len-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void BubbleSort2(int arr[], int len)
{
	int i = 0;
	int j = 0;

	for (i = 0;i<len-1;i++)
	{
		int flag = 1;
		for (j = 0;j<len-i-1;j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}


void quicksort(int arr[], int l, int r)
{
	if (l<r)
	{
		int pivot = partition(arr, l, r);
		quicksort(arr, l, pivot - 1);
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
	if (first < last)
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
	mergesort(a, , n - 1, p);
	delete[] p;
	return true;
}


