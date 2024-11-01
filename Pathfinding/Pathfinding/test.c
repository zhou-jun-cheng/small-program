# include<stdio.h>

//                  �������������������ʵ��
//������һ���Թ�����ʽʵ�֣������Թ���ÿһ���㶼������·�����ߣ���������дһ��������
//���ȴ������������Թ����е�·�߶���¼��ȥ��ֱ���������յ�
//�ٽ����������б������ҵ���ȷ��·�߲���ӡ����
//��ΪҪ��ӡ����������Ӧ�����һ��˫���������

# define N 10
//�Թ������ĺ���
//�����ͼ�Ĵ���
void chuang(char arr[][N], int x, int y)
{
	srand((unsigned int)time(NULL));//����ʱ���������ֵ
	//��ʼ����ͼ
	for (int i = 0; i < N; i++)
	{
		for (int m = 0; m < N; m++)
		{
			arr[i][m] = '*';
		}
	}
	arr[x][y] = ' ';
	//��ʼ��Ϸ��ͼ  1.������ ����   2.������ ����  3.������ ���� 4.������ ����  5.����
	int num1 = 0;//׼���ߵ���������
	int num2 = 0;//ʵ���ߵķ���
	while (y != N - 1)
	{
		num1 = rand() % 5 + 1;//����1��5
		num2 = rand() % 2 + 1;//����1��2
		if (num1 == 1)
		{
			if (num2 == 1)
			{
				y = y + 1;
				arr[x][y] = ' ';
			}
			else if (num2 == 2 && x + 1 != N - 1)
			{
				x = x + 1;
				arr[x][y] = ' ';
			}
		}
		else if (num1 == 2)
		{
			if (num2 == 1 && x + 1 != N - 1)
			{
				x = x + 1;
				arr[x][y] = ' ';
			}
			else if (num2 == 1 && y - 1 != 0 && y != 0)
			{
				y = y - 1;
				arr[x][y] = ' ';
			}
		}
		else if (num1 == 3)
		{
			if (num2 == 1 && y - 1 != 0 && y != 0)
			{
				y = y - 1;
				arr[x][y] = ' ';
			}
			else if (num2 == 2 && x - 1 != 0)
			{
				x = x - 1;
				arr[x][y] = ' ';
			}
		}
		else if (num1 == 4)
		{
			if (num2 == 1 && x - 1 != 0)
			{
				x = x - 1;
				arr[x][y] = ' ';
			}
			else if (num2 == 2)
			{
				y = y + 1;
				arr[x][y] = ' ';
			}
		}
		else if (num1 == 5)
		{
			y = y + 1;
			arr[x][y] = ' ';
		}
	}
	//��ӡ��Ϸ��ͼ
	for (int i = 0; i < N; i++)
	{
		for (int m = 0; m < N; m++)
		{
			printf("%c", arr[i][m]);
		}
		printf("\n");
	}
}

//�������Ĵ���
struct tree
{
	int x;//��ȡ�հ׵��x����
	int y;//��ȡ�հ׵��y����
	struct tree* tree1;//����1
	struct tree* tree2;//����2
	struct tree* tree3;//����3
	struct tree* before;//ָ���׽��
};

////���Թ������������ĺ���
struct tree* Deep_Use(char mi[][N], int x, int y, int info, struct tree* head)
{
	if (mi[x][y] == '*')//���Ϊ*�ž�ֱ�Ӿͷ���NULL
	{
		return NULL;
	}
	struct tree* Mi_Tree = (struct tree*)malloc(sizeof(struct tree));//������ǡ�*���ʹ���һ������
	Mi_Tree->before = head;
	Mi_Tree->x = x;
	Mi_Tree->y = y;
	mi[x][y] = '*';
	if (y == N - 1)  //���y�ﵽ�˳�������ͷ��ظý�㣬�˽ڵ���ǳ��ڽ��
	{
		Mi_Tree->tree1 = NULL;
		Mi_Tree->tree2 = NULL;
		Mi_Tree->tree3 = NULL;
		return Mi_Tree;
	}
	if (info == 1)//�ϣ��ң���
	{
		Mi_Tree->tree1 = Deep_Use(mi, x - 1, y, 4, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x, y + 1, 1, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x + 1, y, 2, Mi_Tree);
	}
	else if (info == 2)//���£���
	{
		Mi_Tree->tree1 = Deep_Use(mi, x, y - 1, 3, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x + 1, y, 2, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x, y + 1, 1, Mi_Tree);
	}
	else if (info == 3)//���£���
	{
		Mi_Tree->tree1 = Deep_Use(mi, x, y - 1, 3, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x + 1, y, 2, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x - 1, y, 4, Mi_Tree);
	}
	else//���ң���
	{
		Mi_Tree->tree1 = Deep_Use(mi, x, y - 1, 3, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x, y + 1, 1, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x - 1, y, 4, Mi_Tree);
	}
	return Mi_Tree;
}
//Ѱ�ҳ��ڽ��ĺ���
struct tree* Deep_Find(struct tree* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	if (head->y == N - 1)
	{
		return head;
	}
	if (Deep_Find(head->tree1) != NULL)
	{
		return Deep_Find(head->tree1);
	}
	else if (Deep_Find(head->tree2) != NULL)
	{
		return Deep_Find(head->tree2);
	}
	else
	{
		return Deep_Find(head->tree3);
	}
}
//��ӡ��ȷ·�ߵĺ���
struct tree* Print_Loca(struct tree* head)
{
	printf("��ʼ��ӡ·��\n");
	while (head)
	{
		printf("%d %d\n", head->x, head->y);
		head = head->before;
	}
}


int main()
{
	printf("Enter 1 to start the program\nEnter 0 to end the program\n");
	int xuan = 0;
	scanf("%d", &xuan);
	while (xuan)
	{
		char mi[N][N] = { 0 };
		int x = 1, y = 0;//x��ʼ���꣬y��ʼ����
		chuang(mi, x, y);//�����Թ��ĺ���
		int info = 1;//��info��ʾ��λ����Ϣ�����������������ߵ�λ��
		printf("��ʼ�����Թ���������\n");
		struct tree* head = Deep_Use(mi, x, y, info, NULL);//���Թ������������ĺ���
		printf("����Թ�������������\n");
		struct tree* p;
		p = NULL;
		printf("��ʼѰ�ҳ��ڵĵ�ַ\n");
		p = Deep_Find(head);//Ѱ�ҳ��ڽ��ĺ���
		printf("�ɹ�Ѱ�ҳ��ڵĵ�ַ\n");
		Print_Loca(p);//��ӡ��ȷ·�ߵĺ���
		printf("��ӡ���\n");
		printf("Enter 1 to start the program\nEnter 0 to end the program\n");
		xuan = 0;
		scanf("%d", &xuan);
	}

	return 0;
}

