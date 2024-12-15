# include<stdio.h>
//����ʽ���� calculation of determinant
// 1.�û���������ʽ�ı߳� The user imputs the side length of the determinant  
// 2.������ʽ������������ʽ Convert determinant to triangular determinant
// 3.����ʹ�õݹ����ת�� Using recursion
// 4.�м����ǲ�����һ�л�һ�ж�Ϊ�� Is there a row or column with zero in the middle check  
// 7.���Բ鿴�ǲ��������л��������  Check if there are two rows or two columns that are equal
// 6.������Խ���˼���  Finally,multiply the main diagonal lines together

//�û�����ĺ����Ķ���  Definition of User Input Function
void Enter(float** arr, int length)
{
	int x = 0, y = 0;
	float value = 0.0;
	while (1)
	{
		printf("���������Լ���Ӧ��ֵ(Enter coordinates and corresponding values):");
		scanf("%d %d %f", &x, &y, &value);
		if (x == 0 && y == 0)//�˳������ Exit situation
		{
			printf("�Ѿ��˳�\n");
			break;
		}
		if (x <= length && y <= length && x >= 1 && y >= 1)//��������Ƿ�Ϸ� Check if it is legal
		{
			arr[x - 1][y - 1] = value;
		}
		else
		{
			printf("���벻�Ϸ�����������(Invalid input,re-enter)\n");
		}

	}
	printf("�������ʽΪ(Your determinant is):\n");
	for (int i = 0; i < length; i++)
	{
		for (int m = 0; m < length; m++)
		{
			printf("%f ", arr[i][m]);
		}
		printf("\n");
	}
}

//�������ĺ����Ķ��� Defintion of Function for Problem Solving
float Solve(float** arr, int length, int x) //�����ֱ��� ����ʽ���飬�߳�����ǰ���ڵ���	 The parameters are the determinant array,edge Length,and current row
{
	//�������� end condition
	if (x == length)
	{
		return 1;
	}
	int sign = 1;
	//����ǲ�����һ�ж�Ϊ��  Check if there is a row with zero
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
	//��ʼת��Ϊ����������ʽ Start converting to an upper triangular determinant 
	sign = 0;//change sign
	if (arr[x][x] == 0)//���������ʽΪ���Ӧ���滻 if the main determinant is zero,replace it
	{
		sign = 1;
		//Ѱ�Ҳ�Ϊ����� Find non-zero rows
		for (int m = 0; x < length; x++)
		{
			if (arr[m][x] != 0)
			{
				sign = 0;//�ı�Ǻ�
				for (int n = 0; n < length; n++)
				{
					arr[x][n] = arr[x][n] + arr[m][n];
				}
				break;//�ҵ�������ѭ�� Find it and jump out of the loop
			}
		}
	}
	if (sign)
	{
		return 0;
	}
	//��ʼ�ϲ� Start merging
	for (int i = 0; i < x; i++)
	{
		if (arr[x][i] == 0)//����Ѿ�Ϊ0 if it is already zero
		{
			continue;
		}
		float num = arr[x][i] / arr[i][i];
		for (int m = 0; m < length; m++)
		{
			arr[x][m] = arr[x][m] - arr[i][m] * num;
		}
	}
	//�ݹ� recursion
	return arr[x][x] * Solve(arr, length, x + 1);
}


//������ main
int main()
{
	int length = 0;//�߳��ı���  variable of side length
	printf("������ı߳�(Enter side length):");
	scanf("%d", &length);
	printf("��ʼ����(Start creating determinant framework)\n");
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
	printf("�û���ʼ����(The user begins to input)\n");
	Enter(arr, length);//�û�����ĺ���
	printf("��ʼ����(compute)\n");
	float result = Solve(arr, length, 0);//�������ĺ���
	printf("���Ľ����(The final result is):%.2f", result);
}