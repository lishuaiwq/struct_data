//快排复习
//int Quick_fast(int *arr,int left,int right)
//{
//	//4,2,6,4,9,5,3,2,1,0
//	int index = left;
//	while (left < right)
//	{
//		
//		while (left < right&&arr[right]>=arr[index])//首先从后往前走，从后面找比标志元素小的，前面找比标志元素大的
//		{
//			//从右向左走,因为如果从左向右走的话,
//这个时候right指向大于目标值,所以left走到right的位置就停下来了,然后和left交换
//相当于将比目标值大的交换在了第一个
//			//比较的时候取等号，因为如果等于目标元素则它在目标元素的前后都是一样的所以没必要去移动它
//			--right;
//		}
//		while (left < right&&arr[left]<=arr[index])
//		{
//			++left;
//		}
//		if (left < right)
//		{
//			swap(arr[left], arr[right]);
//		}
//	}
//	swap(arr[left], arr[index]);
//	return left;
//}
//挖坑法,假设第一个为坑
//int	Quick_fast(int *arr, int left, int right)
//{
//	int key = arr[left];//第一个元素是key
//	while (left < right)
//	{
//		while (left < right&&arr[right] >= key)
//			--right;
//		if (left < right)
//			arr[left] = arr[right];
//		while (left < right&&arr[left] <= key)
//			++left;
//		if (left < right)
//			arr[right] = arr[left];
//	}
//	arr[left] = key;
//	return left;
//}
//快慢指针法
int Quick_fast(int *arr, int left, int right)
{
	int fast = left;
	int slow = left - 1;
	while (fast < right)
	{
		if (arr[fast] < arr[right])
		{
			++slow;
			if (slow != fast)
				swap(arr[slow], arr[fast]);
		}
		++fast;
	}
	++slow;
	swap(arr[slow], arr[right]);
	return slow;
}
//
//void quick_sort(int *arr, int left, int right)
//{
//	if (left < right)
//	{
//		int mid = Quick_fast(arr, left, right);
//		quick_sort(arr, left, mid - 1);
//		quick_sort(arr, mid + 1, right);
//	}
//}
//快排的非递归版本

void Quick_sort(int *arr, int left, int right)
{
	stack<int> s;
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		int mid = Quick_fast(arr, begin, end);
		if (begin< mid - 1)
		{
			s.push(mid - 1);
			s.push(begin);
		}
		if (end>mid + 1)
		{
			s.push(end);
			s.push(mid + 1);
		}
	}
}

int main()
{
	//快排1.标志法
	int arr[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	int size = sizeof(arr) / sizeof(*arr);
	Quick_sort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}