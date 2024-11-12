# include<stdio.h>
//���������㷨 Quick sort

//������̵ĺ����Ķ��� Function definition of sorting process
int Sort_Process(int* arr, int low, int high)
{
	arr[0] = arr[low]; //�ڱ��洢����ı����(Sentinel stores the values taht need to be changed)
	while (low < high)
	{
		while (arr[0] <= arr[high] && low < high) //Ѱ���ұ���û�б��ڱ�С��ֵ(Search for a value on the right that is smaller than the sential)
		{
			high--;
		}
		if (arr[0] > arr[high] && low < high)
		{
			arr[low] = arr[high];
			low++;
		}
		while (arr[0] >= arr[low] && low < high)//Ѱ�������û�б��ڱ�С��ֵ(Search for a value on the left that is smaller than the sential)
		{
			low++;
		}
		if (arr[0] < arr[low] && low < high)
		{
			arr[high] = arr[low];
			high--;
		}
	}
	arr[low] = arr[0];//���ڱ���ֵ������ȷλ��(Place the sebtinel's values in the correct position)
	return low;
}




//��������ĺ����Ķ���  Function definition for quick sorting 
void Quick_Sort(int arr[], int low, int high)
{
	int pos; //�洢�±��
	if (low < high) //�����±��������
	{
		pos = Sort_Process(arr, low, high);// �������
		Quick_Sort(arr, low, pos - 1);// ��ݹ�
		Quick_Sort(arr, pos + 1, high);// �ҵݹ�
	}
}


//������
int main()
{
	int num = 0;//�洢�������� Quantity of stored data
	printf("���������������(Enter your data quantity):");
	scanf("%d", &num);
	int* arr = (int*)malloc((num + 1) * sizeof(int));//���ٶ�̬���� open up dynamic arrays
	printf("������Ҫ�����ֵ(Enter the values to be sorted):\n");
	for (int i = 1; i < num + 1; i++)
	{
		scanf("%d", &arr[i]);//�������� input data
	}
	Quick_Sort(arr, 1, num);//��������ĺ��� function of quicksort
	for (int i = 1; i <= num; i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}

