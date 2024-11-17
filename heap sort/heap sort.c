# include<stdio.h>
// ɸѡ�㷨��ʵ��(Implementation of screening algorithm)
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
		// ���н��� Exchange
		if (arr[i] < arr[t])
		{
			arr[0] = arr[i];
			arr[i] = arr[t];
			arr[t] = arr[0];
			i = t; //��������ܲ���Ӱ�죬��Ҫ���еݹ� The exchange may have an impact and requires recursion
			Filter_Alg(arr, i, num);
		}
	}
}

//�������㷨  Heap sorting algorithm
// ������ main
int main()
{
	int num = 0;
	printf("����������ݵ���(Enter the amount of your data):");
	scanf("%d", &num);
	int* arr = (int*)malloc((num + 1) * sizeof(int)); //�±�Ϊ��䵱�ڱ� (Use zero as a sentinel)
	printf("�������������,�ո����(Enter sorted numbers separated by spaces):\n");
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &arr[i]);
	}
	//������ (Initial construction pile)
	for (int i = num / 2; i >= 1; i--)
	{
		Filter_Alg(arr, i, num);//ɸѡ�㷨(filtering algorithm)
	}
	//��������(build another pile)
	for (int i = num; i > 1; i--)
	{
		arr[0] = arr[i];
		arr[i] = arr[1];
		arr[1] = arr[0];
		Filter_Alg(arr, 1, i - 1);

	}
	printf("������Ϊ(The sorting result if):\n");
	for (int i = 1; i <= num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}