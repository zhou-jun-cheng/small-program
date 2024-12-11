# include<stdio.h>

//快速排序的改进算法(Improved algorithm for quick sorting)

//实际上排序的函数的定义(Definition of Sorting Function)
void Sort(int arr[], int* lefts, int* rights)
{
	int k = *lefts + 1;//过渡变量(Transitional variables)
	while (k <= *rights)
	{
		if (arr[*lefts] > arr[k])//如果满足就交换，并且前移(if satisfied ,exchange and move forward)
		{
			arr[k] = arr[*lefts] + arr[k];
			arr[*lefts] = arr[k] - arr[*lefts];
			arr[k] = arr[k] - arr[*lefts];
			(*lefts) += 1;
			k += 1;
		}
		else if (arr[*rights] < arr[*lefts])//如果右值小，就与k对应的元素交换(if the right-hand value id small,swap with the element corresponding to k)
		{
			arr[k] = arr[*rights] + arr[k];
			arr[*rights] = arr[k] - arr[*rights];
			arr[k] = arr[k] - arr[*rights];
			(*rights) -= 1;
		}
		else if (arr[*rights] == arr[*lefts])//如果左右值相等就与k交换(if the left and right values are equal,they are exchangeed with k)
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


//准备排序的函数的定义(Definition of the function for sorting preparation)
void Ready(int arr[], int left, int right)
{
	if (left < right)
	{
		int lefts = left, rights = right;
		Sort(arr, &lefts, &rights);//排序的函数(Sorting function)
		Ready(arr, left, lefts - 1);//左递归(left recursive)
		Ready(arr, rights + 1, right);//右递归(right recursive)
	}
}
// 主函数(main)
int main()
{
	//int arr[20] = {23,30,42,23,76,87,45,23,65,3,3,2,32,43,23,12,43,54,23,43};//待排序的数组
	int nums = 0;
	printf("输入你的元素数量(Enter your number of elements):");
	scanf("%d", &nums);
	int* arr = (int*)malloc(nums * sizeof(int));
	printf("输入你的元素(Enter your element):");
	for (int i = 0; i < nums; i++)
	{
		scanf("%d", &arr[i]);
	}
	Ready(arr, 0, 19);//准备排序的函数(Prepare sorting function)
	printf("排序结果是(The sorting result is):");
	for (int i = 0; i < 20; i++)
	{
		printf("%d  ", arr[i]);
	}
	return 0;
}