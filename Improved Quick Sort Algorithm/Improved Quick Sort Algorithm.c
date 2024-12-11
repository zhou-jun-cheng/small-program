# include<stdio.h>

//��������ĸĽ��㷨(Improved algorithm for quick sorting)

//ʵ��������ĺ����Ķ���(Definition of Sorting Function)
void Sort(int arr[], int* lefts, int* rights)
{
	int k = *lefts + 1;//���ɱ���(Transitional variables)
	while (k <= *rights)
	{
		if (arr[*lefts] > arr[k])//�������ͽ���������ǰ��(if satisfied ,exchange and move forward)
		{
			arr[k] = arr[*lefts] + arr[k];
			arr[*lefts] = arr[k] - arr[*lefts];
			arr[k] = arr[k] - arr[*lefts];
			(*lefts) += 1;
			k += 1;
		}
		else if (arr[*rights] < arr[*lefts])//�����ֵС������k��Ӧ��Ԫ�ؽ���(if the right-hand value id small,swap with the element corresponding to k)
		{
			arr[k] = arr[*rights] + arr[k];
			arr[*rights] = arr[k] - arr[*rights];
			arr[k] = arr[k] - arr[*rights];
			(*rights) -= 1;
		}
		else if (arr[*rights] == arr[*lefts])//�������ֵ��Ⱦ���k����(if the left and right values are equal,they are exchangeed with k)
		{
			int sum = arr[*rights];
			arr[*rights] = arr[k];
			arr[k] = sum;
			(*rights) -= 1;
			k++;
		}
		else
		{
			(*rights) -= 1;
		}
	}
}


//׼������ĺ����Ķ���(Definition of the function for sorting preparation)
void Ready(int arr[], int left, int right)
{
	if (left < right)
	{
		int lefts = left, rights = right;
		Sort(arr, &lefts, &rights);//����ĺ���(Sorting function)
		Ready(arr, left, lefts - 1);//��ݹ�(left recursive)
		Ready(arr, rights + 1, right);//�ҵݹ�(right recursive)
	}
}
// ������(main)
int main()
{
	//int arr[20] = {23,30,42,23,76,87,45,23,65,3,3,2,32,43,23,12,43,54,23,43};//�����������
	int nums = 0;
	printf("�������Ԫ������(Enter your number of elements):");
	scanf("%d", &nums);
	int* arr = (int*)malloc(nums * sizeof(int));
	printf("�������Ԫ��(Enter your element):");
	for (int i = 0; i < nums; i++)
	{
		scanf("%d", &arr[i]);
	}
	Ready(arr, 0, 19);//׼������ĺ���(Prepare sorting function)
	printf("��������(The sorting result is):");
	for (int i = 0; i < 20; i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}