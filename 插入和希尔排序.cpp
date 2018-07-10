void Insert(int *arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= 0 && key<arr[end])//key<arr[end]这里取不到等号，因为等于arr[end]的时候放在他后面就行了没必要放在前面
			//如果要拍升序则比arr[end]小就可以了，找到比当前元素值小的，即放在他后面就可以了
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = key;
	}
}
//优化后的插入排序
void Insert_OP(int *arr, int size)
{
	//首先进行二分查找
	for (int i = 1; i < size; i++)
	{
		int left = 0;
		int right = i - 1;
		int key = arr[i];
		//细节		while (left <=right)//这里要取等号因为取不到等号的话则left=right的这个元素没有和key比较
		{
			int mid = ((right - left) >> 1) + left;
			if (arr[mid]>key)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		//到这里无需纠结参考left还是right因为都可以
		//只有两种情况小于当前的元素则right在当前元素的左边,大于当前元素则left在其右边
		int end = i - 1;//下面需要开始搬移元素了
		while (end >= right)//在这里大于等于left也可以,因为都不影响,但是下面也要用left因为它插入的只能是当前位置或者
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[left] = key;//这里只能用left；//细节注意
	}
}
//希尔排序，缩小增量排序
void Shell(int *arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && arr[end]>key)
			{
				arr[end + gap] = arr[end];
				end = end - gap;
			}
			arr[end + gap] = key;
		}
	}
}
int main()
{
	int arr[] = { 9, 5, 5, 6, 8, 2, 3, 1, 7 };
	int size = sizeof(arr) / sizeof(*arr);
	//	Insert_OP(arr, size);
	Shell(arr, size);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	system("pause");
	return 0;
}