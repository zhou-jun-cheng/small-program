# include<stdio.h>
// Ŀ��:ϣ������ĵ�����ݹ��ʵ��
// objective: Iterative and Recursive Implementation of Hill Sorting

//1.ϣ������  Hill sort

// ϣ���������Ķ���(Defintion of  Hill sorting function)  (�ݹ�)(recursion)
void Hash_Sort(int arr[], int nums, int num)
{
	int j = 0;
	int trans_num = 0;//���ɱ���(Transitional variables)
	if (num == 0)     //�ݹ��˳�����(recursive exit condition)
	{
		return;
	}
	for (int i = 0; i + num < nums; i++)
	{
		trans_num = arr[i + num];
		j = i;
		while (j >= 0 && arr[j] > trans_num)
		{
			arr[j + num] = arr[j];
			j = j - num;
		}
		arr[j + num] = trans_num;
	}
	Hash_Sort(arr, nums, num / 2);//�ݹ� recursive
}

//ϣ���������Ķ���(Defintion of  Hill sorting function)  (����)(iteration)
void slpx(int arr[], int n)
{
	int j;
	int k;
	int t;
	int d = n / 2;
	while (d >= 1)
	{
		for (k = d; k < n; k++)
		{
			t = arr[k];
			j = k - d;
			while (j >= 0 && t < arr[j])
			{
				arr[j + d] = arr[j];
				j -= d;
			}
			arr[j + d] = t;
		}
		d /= 2;
	}

}


//������ main
int main()
{
	int nums = 0;
	printf("��������Ҫ��������ָ���(Please enter the number of numbers to be sorted):");
	scanf("%d", &nums);
	int* arr = (int*)malloc(nums * sizeof(int));//��̬����Ŀ��� Development of dynamic arrays
	printf("������Ҫ���������,��������ʹ�ö��Ÿ���(Please enter the numbers to be sorted,with adjacent numbers separated by commas):");
	for (int i = 0; i < nums; i++)
	{
		scanf("%d", &arr[i]);
	}
	//slpx(arr, nums);            //ϣ������ĺ���(function of  Hill sort)(iteration)
	Hash_Sort(arr, nums, nums / 2);   //ϣ������ĺ���(function of  Hill sort)
	for (int i = 0; i < nums; i++)//��ӡ������(print sorting results)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
