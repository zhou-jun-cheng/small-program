# include<stdio.h>
//快速排序算法 Quick sort

//排序过程的函数的定义 Function definition of sorting process
int Sort_Process(int* arr, int low, int high)
{
	arr[0] = arr[low]; //哨兵存储最后会改变的量(Sentinel stores the values taht need to be changed)
	while (low < high)
	{
		while (arr[0] <= arr[high] && low < high) //寻找右边有没有比哨兵小的值(Search for a value on the right that is smaller than the sential)
		{
			high--;
		}
		if (arr[0] > arr[high] && low < high)
		{
			arr[low] = arr[high];
			low++;
		}
		while (arr[0] >= arr[low] && low < high)//寻找左边有没有比哨兵小的值(Search for a value on the left that is smaller than the sential)
		{
			low++;
		}
		if (arr[0] < arr[low] && low < high)
		{
			arr[high] = arr[low];
			high--;
		}
	}
	arr[low] = arr[0];//将哨兵的值放入正确位置(Place the sebtinel's values in the correct position)
	return low;
}




//快速排序的函数的定义  Function definition for quick sorting 
void Quick_Sort(int arr[], int low, int high)
{
	int pos; //存储下标点
	if (low < high) //满足下标进行排序
	{
		pos = Sort_Process(arr, low, high);// 排序过程
		Quick_Sort(arr, low, pos - 1);// 左递归
		Quick_Sort(arr, pos + 1, high);// 右递归
	}
}


//主函数
int main()
{
	int num = 0;//存储数据数量 Quantity of stored data
	printf("输入你的数据数量(Enter your data quantity):");
	scanf("%d", &num);
	int* arr = (int*)malloc((num + 1) * sizeof(int));//开辟动态数组 open up dynamic arrays
	printf("输入需要排序的值(Enter the values to be sorted):\n");
	for (int i = 1; i < num + 1; i++)
	{
		scanf("%d", &arr[i]);//输入数据 input data
	}
	Quick_Sort(arr, 1, num);//快速排序的函数 function of quicksort
	for (int i = 1; i <= num; i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}

