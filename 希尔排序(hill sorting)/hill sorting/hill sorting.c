# include<stdio.h>
// 目标:希尔排序的迭代与递归的实现
// objective: Iterative and Recursive Implementation of Hill Sorting

//1.希尔排序  Hill sort

// 希尔排序函数的定义(Defintion of  Hill sorting function)  (递归)(recursion)
void Hash_Sort(int arr[], int nums, int num)
{
	int j = 0;
	int trans_num = 0;//过渡变量(Transitional variables)
	if (num == 0)     //递归退出条件(recursive exit condition)
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
	Hash_Sort(arr, nums, num / 2);//递归 recursive
}

//希尔排序函数的定义(Defintion of  Hill sorting function)  (迭代)(iteration)
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


//主函数 main
int main()
{
	int nums = 0;
	printf("请输入需要排序的数字个数(Please enter the number of numbers to be sorted):");
	scanf("%d", &nums);
	int* arr = (int*)malloc(nums * sizeof(int));//动态数组的开辟 Development of dynamic arrays
	printf("请输入要排序的数字,相邻数字使用逗号隔开(Please enter the numbers to be sorted,with adjacent numbers separated by commas):");
	for (int i = 0; i < nums; i++)
	{
		scanf("%d", &arr[i]);
	}
	//slpx(arr, nums);            //希尔排序的函数(function of  Hill sort)(iteration)
	Hash_Sort(arr, nums, nums / 2);   //希尔排序的函数(function of  Hill sort)
	for (int i = 0; i < nums; i++)//打印排序结果(print sorting results)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
