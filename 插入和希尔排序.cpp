void Insert(int *arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= 0 && key<arr[end])//key<arr[end]����ȡ�����Ⱥţ���Ϊ����arr[end]��ʱ����������������û��Ҫ����ǰ��
			//���Ҫ���������arr[end]С�Ϳ����ˣ��ҵ��ȵ�ǰԪ��ֵС�ģ�������������Ϳ�����
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = key;
	}
}
//�Ż���Ĳ�������
void Insert_OP(int *arr, int size)
{
	//���Ƚ��ж��ֲ���
	for (int i = 1; i < size; i++)
	{
		int left = 0;
		int right = i - 1;
		int key = arr[i];
		//ϸ��		while (left <=right)//����Ҫȡ�Ⱥ���Ϊȡ�����ȺŵĻ���left=right�����Ԫ��û�к�key�Ƚ�
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
		//�������������ο�left����right��Ϊ������
		//ֻ���������С�ڵ�ǰ��Ԫ����right�ڵ�ǰԪ�ص����,���ڵ�ǰԪ����left�����ұ�
		int end = i - 1;//������Ҫ��ʼ����Ԫ����
		while (end >= right)//��������ڵ���leftҲ����,��Ϊ����Ӱ��,��������ҲҪ��left��Ϊ�������ֻ���ǵ�ǰλ�û���
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[left] = key;//����ֻ����left��//ϸ��ע��
	}
}
//ϣ��������С��������
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