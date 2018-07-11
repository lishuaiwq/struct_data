//希尔排序
//2, 6, 9, 4, 8, 7, 1, 3, 5

void Mere_sort(int* arr, int left, int right, int mid, int *tmp)
{
	int begin1 = left;
	int begin2 = mid + 1;
	int index = left;
	while (begin1 <= mid&&begin2 <= right)
	{
		if (arr[begin1] > arr[begin2])
			tmp[index++] = arr[begin2++];
		else
			tmp[index++] = arr[begin1++];
	}
	while (begin1 <= mid)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= right)
	{
		tmp[index++] = arr[begin2++];
	}
	/*while (left <=right)
	{
	arr[left] = tmp[left++];
	}*/
	memcpy(arr + left, tmp + left, sizeof(int)*(right - left + 1));
}

//void Merge(int *arr,int left,int right,int *tmp)
//{
//	if (left < right)
//	{
//		int mid = ((right-left) >> 1) + left;
//		Merge(arr, left, mid,tmp);//
//		Merge(arr, mid + 1, right,tmp);
//		Mere_sort(arr, left, right, mid, tmp);
//	}
//}
//非递归
void Merge(int* arr, int left, int right, int *tmp)
{
	int gap = 1;
	while (gap <= right)
	{
		for (int i = 0; i < right; i += 2 * gap)
		{
			//在这里需要mid需要left需要right
			int begin1 = i;
			int mid = i + gap - 1;
			int end = mid + gap;
			if (end>right)
				end = right;
			Mere_sort(arr, begin1, end, mid, tmp);
		}
		gap *= 2;
	}
}

int main()
{
	int arr[] = { 2, 6, 9, 4, 8, 7, 1, 3, 5 };
	int size = sizeof(arr) / sizeof(*arr);
	int *tmp = new int[size];
	//Merge(arr, 0, size - 1, tmp);
	Merge(arr, 0, size - 1, tmp);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] tmp;
	system("pause");
	return 0;
}