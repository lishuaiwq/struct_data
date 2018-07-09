//���Ÿ�ϰ
//int Quick_fast(int *arr,int left,int right)
//{
//	//4,2,6,4,9,5,3,2,1,0
//	int index = left;
//	while (left < right)
//	{
//		
//		while (left < right&&arr[right]>=arr[index])//���ȴӺ���ǰ�ߣ��Ӻ����ұȱ�־Ԫ��С�ģ�ǰ���ұȱ�־Ԫ�ش��
//		{
//			//����������,��Ϊ������������ߵĻ�,
//���ʱ��rightָ�����Ŀ��ֵ,����left�ߵ�right��λ�þ�ͣ������,Ȼ���left����
//�൱�ڽ���Ŀ��ֵ��Ľ������˵�һ��
//			//�Ƚϵ�ʱ��ȡ�Ⱥţ���Ϊ�������Ŀ��Ԫ��������Ŀ��Ԫ�ص�ǰ����һ��������û��Ҫȥ�ƶ���
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
//�ڿӷ�,�����һ��Ϊ��
//int	Quick_fast(int *arr, int left, int right)
//{
//	int key = arr[left];//��һ��Ԫ����key
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
//����ָ�뷨
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
//���ŵķǵݹ�汾

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
	//����1.��־��
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