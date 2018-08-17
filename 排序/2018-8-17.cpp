void Bubblesort(int a[], int n)
{
	if (a == NULL)
		return;
	for (int i = 0; i < n; ++i)
	{
		for (int j = n; j > i; --j)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
		}
	}
}

void Insertsort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
	{
		t = a[i];
		for (j = i; j > 0 && a[j] < t; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = t;
	}
}

void shellSort(int a[], int n)
{
	int i, j, increment;
	int tmp;
	for (increment = n / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < n; ++i)
		{
			tmp = a[i];
			for (j = i; j >= increment&&a[j - increment] > tmp; j -= increment)
			{
				a[j] = a[j - increment];
			}
			a[j] = tmp;
		}
	}
}

void Selectsort(int arr[], int num)
{
	int i, j, Mindex;
	for (i = 0; i < num; i++)
	{
		Mindex = i;
		for (j = i + 1; j < num; j++)
		{
			if (arr[j] < arr[Mindex])
				Mindex = j;
		}
		swap(arr[i], arr[Mindex]);
	}
}

int partition(int arr[], int l, int r)
{
	int k = l, pivot = arr[r];
	for (int i = l; i < r; i++)
	{
		if (arr[i] < pivot)
		{
			swap(arr[i], arr[k++]);
		}
	}
	swap(arr[k], arr[r]);
	return k;
}


void quicksort(int arr[], int l, int r)
{
	if (l < r)
	{
		int pivot = partition(arr, l, r);
		quicksort(arr, l, pivot - 1);
		quicksort(arr, pivot + 1, r);
	}
}

void mergearray(int a[], int first, int mid, int last, int  temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m)
	{
		temp[k++] = a[i++];
	}
	while (j <= n)
	{
		temp[k++] = a[j++];
	}
	for (i = 0; i < k; i++)
	{
		a[first + i] = temp[i];
	}
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
	if (p == NULL)
	{
		return false;
	}
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

void percDown(int *arr, int i, int N)
{
	int tmp, child;
	for (tmp = arr[i]; leftChild(i) < N; i = child)
	{
		child = leftChild(i);
		if (child != N - 1 && arr[child + 1] > arr[child])
			child++;
		if (arr[child] > tmp)
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = tmp;
}

void HeapSort(int *arr, int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		percDown(arr, i, N);
	for (i = N - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		percDown(arr, 0, i);
	}
}


int main(void)
{
	int arr[] = { 9, 2, 5, 8, 3, 4, 7, 1, 6, 10 };
	HeapSort(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}
https://blog.csdn.net/jnu_simba/article/details/9705111