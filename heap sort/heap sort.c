# include<stdio.h>
// 筛选算法的实现(Implementation of screening algorithm)
void Filter_Alg(int* arr, int i, int num)
{
	int p = 2 * i;
	int t = 0;
	if (p <= num)
	{
		t = p;
		if (t < num)
		{
			if (arr[t] < arr[t + 1])
			{
				t = t + 1;
			}
		}
		// 进行交换 Exchange
		if (arr[i] < arr[t])
		{
			arr[0] = arr[i];
			arr[i] = arr[t];
			arr[t] = arr[0];
			i = t; //互换后可能产生影响，需要进行递归 The exchange may have an impact and requires recursion
			Filter_Alg(arr, i, num);
		}
	}
}

//堆排序算法  Heap sorting algorithm
// 主函数 main
int main()
{
	int num = 0;
	printf("输入你的数据的量(Enter the amount of your data):");
	scanf("%d", &num);
	int* arr = (int*)malloc((num + 1) * sizeof(int)); //下标为零充当哨兵 (Use zero as a sentinel)
	printf("输入排序的数字,空格隔开(Enter sorted numbers separated by spaces):\n");
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &arr[i]);
	}
	//初建堆 (Initial construction pile)
	for (int i = num / 2; i >= 1; i--)
	{
		Filter_Alg(arr, i, num);//筛选算法(filtering algorithm)
	}
	//过程排序(build another pile)
	for (int i = num; i > 1; i--)
	{
		arr[0] = arr[i];
		arr[i] = arr[1];
		arr[1] = arr[0];
		Filter_Alg(arr, 1, i - 1);

	}
	printf("排序结果为(The sorting result if):\n");
	for (int i = 1; i <= num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}