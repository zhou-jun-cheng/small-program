# include<stdio.h>
// 归并排序 Merge sort

//进行排序的函数 sorting function
void sort(int arr[], int boun, int low, int high)
{
	int m = boun + 1;//过渡变量 transitional variables
	int i = 0;//过渡变量 transitional variables
	int n = low;//过渡变量 transitional variables
	int* num = (int*)malloc((high - low + 1) * sizeof(int));//开辟数组进行暂时存储 open an array for temporary storage
	while (low <= boun && m <= high)
	{
		num[i++] = arr[low] <= arr[m] ? arr[low++] : arr[m++];//三目操作符进行赋值 assign values using the trinocular operator
	}
	//检查是否全部赋值完毕 check if all assignments have been completed
	while (low <= boun)
	{
		num[i++] = arr[low++];
	}
	while (m <= high)
	{
		num[i++] = arr[m++];
	}
	//将过渡数组还回去 return the transition array
	i = 0;
	for (n; n <= high; n++, i++)
	{
		arr[n] = num[i];
	}
}

//进入排序的函数的定义  definition of the function for entering sorting
void mergepass(int arr[], int nums, int lenght)
{
	int low = 0;
	for (low = 0; low + 2 * lenght - 1 < nums; low += 2 * lenght)
	{
		//开始排序 实参分别是(数组，分界位，最低位，最高位)The starting sorting parameters are (array, boundary bit, lowest bit, highest bit)
		sort(arr, low + lenght - 1, low, low + 2 * lenght - 1);
	}
	//多余情况  excess situation
	if (low + lenght - 1 < nums - 1)
	{
		sort(arr, low + lenght - 1, low, nums - 1);
	}
}


//主函数 main function
int main()
{
	int nums = 0;//元素个数变量 variable of number of elements
	printf("输入元素个数(enter the number of elements):");
	scanf("%d", &nums);
	int* arr = (int*)malloc(nums * sizeof(int));
	printf("请输入元素(input element):");
	for (int i = 0; i < nums; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < nums; i = i * 2) //准备排序
	{
		mergepass(arr, nums, i);//进入排序
	}
	printf("结果为(the result is):");
	for (int i = 0; i < nums; i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}