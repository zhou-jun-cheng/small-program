# include<stdio.h>
// �鲢���� Merge sort

//��������ĺ��� sorting function
void sort(int arr[], int boun, int low, int high)
{
	int m = boun + 1;//���ɱ��� transitional variables
	int i = 0;//���ɱ��� transitional variables
	int n = low;//���ɱ��� transitional variables
	int* num = (int*)malloc((high - low + 1) * sizeof(int));//�������������ʱ�洢 open an array for temporary storage
	while (low <= boun && m <= high)
	{
		num[i++] = arr[low] <= arr[m] ? arr[low++] : arr[m++];//��Ŀ���������и�ֵ assign values using the trinocular operator
	}
	//����Ƿ�ȫ����ֵ��� check if all assignments have been completed
	while (low <= boun)
	{
		num[i++] = arr[low++];
	}
	while (m <= high)
	{
		num[i++] = arr[m++];
	}
	//���������黹��ȥ return the transition array
	i = 0;
	for (n; n <= high; n++, i++)
	{
		arr[n] = num[i];
	}
}

//��������ĺ����Ķ���  definition of the function for entering sorting
void mergepass(int arr[], int nums, int lenght)
{
	int low = 0;
	for (low = 0; low + 2 * lenght - 1 < nums; low += 2 * lenght)
	{
		//��ʼ���� ʵ�ηֱ���(���飬�ֽ�λ�����λ�����λ)The starting sorting parameters are (array, boundary bit, lowest bit, highest bit)
		sort(arr, low + lenght - 1, low, low + 2 * lenght - 1);
	}
	//�������  excess situation
	if (low + lenght - 1 < nums - 1)
	{
		sort(arr, low + lenght - 1, low, nums - 1);
	}
}


//������ main function
int main()
{
	int nums = 0;//Ԫ�ظ������� variable of number of elements
	printf("����Ԫ�ظ���(enter the number of elements):");
	scanf("%d", &nums);
	int* arr = (int*)malloc(nums * sizeof(int));
	printf("������Ԫ��(input element):");
	for (int i = 0; i < nums; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < nums; i = i * 2) //׼������
	{
		mergepass(arr, nums, i);//��������
	}
	printf("���Ϊ(the result is):");
	for (int i = 0; i < nums; i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}