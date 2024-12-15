# include<stdio.h>
//行列式计算 calculation of determinant
// 1.用户输入行列式的边长 The user imputs the side length of the determinant  
// 2.将行列式化成三角行列式 Convert determinant to triangular determinant
// 3.可以使用递归进行转换 Using recursion
// 4.中间检查是不是有一行或一列都为零 Is there a row or column with zero in the middle check  
// 7.可以查看是不是有两行或两列相等  Check if there are two rows or two columns that are equal
// 6.最后主对角相乘即可  Finally,multiply the main diagonal lines together

//用户输入的函数的定义  Definition of User Input Function
void Enter(float** arr, int length)
{
	int x = 0, y = 0;
	float value = 0.0;
	while (1)
	{
		printf("输入坐标以及对应的值(Enter coordinates and corresponding values):");
		scanf("%d %d %f", &x, &y, &value);
		if (x == 0 && y == 0)//退出的情况 Exit situation
		{
			printf("已经退出\n");
			break;
		}
		if (x <= length && y <= length && x >= 1 && y >= 1)//检查输入是否合法 Check if it is legal
		{
			arr[x - 1][y - 1] = value;
		}
		else
		{
			printf("输入不合法，重新输入(Invalid input,re-enter)\n");
		}

	}
	printf("你的行列式为(Your determinant is):\n");
	for (int i = 0; i < length; i++)
	{
		for (int m = 0; m < length; m++)
		{
			printf("%f ", arr[i][m]);
		}
		printf("\n");
	}
}

//解决问题的函数的定义 Defintion of Function for Problem Solving
float Solve(float** arr, int length, int x) //参数分别是 行列式数组，边长，当前所在的行	 The parameters are the determinant array,edge Length,and current row
{
	//结束条件 end condition
	if (x == length)
	{
		return 1;
	}
	int sign = 1;
	//检查是不是有一行都为零  Check if there is a row with zero
	for (int i = 0; i < length; i++)
	{
		if (arr[x][i] != 0)
		{
			sign = 0;
			break;
		}
	}
	if (sign)
	{
		return 0;
	}
	//开始转换为上三角行列式 Start converting to an upper triangular determinant 
	sign = 0;//change sign
	if (arr[x][x] == 0)//如果主行列式为零就应该替换 if the main determinant is zero,replace it
	{
		sign = 1;
		//寻找不为零的行 Find non-zero rows
		for (int m = 0; x < length; x++)
		{
			if (arr[m][x] != 0)
			{
				sign = 0;//改变记号
				for (int n = 0; n < length; n++)
				{
					arr[x][n] = arr[x][n] + arr[m][n];
				}
				break;//找到就跳出循环 Find it and jump out of the loop
			}
		}
	}
	if (sign)
	{
		return 0;
	}
	//开始合并 Start merging
	for (int i = 0; i < x; i++)
	{
		if (arr[x][i] == 0)//如果已经为0 if it is already zero
		{
			continue;
		}
		float num = arr[x][i] / arr[i][i];
		for (int m = 0; m < length; m++)
		{
			arr[x][m] = arr[x][m] - arr[i][m] * num;
		}
	}
	//递归 recursion
	return arr[x][x] * Solve(arr, length, x + 1);
}


//主函数 main
int main()
{
	int length = 0;//边长的变量  variable of side length
	printf("输入你的边长(Enter side length):");
	scanf("%d", &length);
	printf("开始创建(Start creating determinant framework)\n");
	float** arr = (float**)malloc(length * sizeof(float));

	for (int i = 0; i < length; i++)
	{
		arr[i] = (float*)malloc(length * sizeof(float));
	}
	for (int i = 0; i < length; i++)
	{
		for (int m = 0; m < length; m++)
		{
			arr[i][m] = 0.0;
		}
	}
	printf("用户开始输入(The user begins to input)\n");
	Enter(arr, length);//用户输入的函数
	printf("开始计算(compute)\n");
	float result = Solve(arr, length, 0);//解决问题的函数
	printf("最后的结果是(The final result is):%.2f", result);
}