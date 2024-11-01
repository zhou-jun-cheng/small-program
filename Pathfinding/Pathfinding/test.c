# include<stdio.h>

//                  深度优先搜索三叉树的实现
//这里以一个迷宫的形式实现，但是迷宫的每一个点都有三个路可以走，所以这里写一个三叉树
//首先创建三叉树将迷宫所有的路线都给录进去，直到搜索到终点
//再将三叉树进行遍历，找到正确的路线并打印出来
//因为要打印出来，所以应该设计一个双向的三叉树

# define N 10
//迷宫创建的函数
//随机地图的创建
void chuang(char arr[][N], int x, int y)
{
	srand((unsigned int)time(NULL));//根据时间生成随机值
	//初始化地图
	for (int i = 0; i < N; i++)
	{
		for (int m = 0; m < N; m++)
		{
			arr[i][m] = '*';
		}
	}
	arr[x][y] = ' ';
	//初始游戏地图  1.：向右 向下   2.：向下 向左  3.：向左 向上 4.：向上 向右  5.向右
	int num1 = 0;//准备走的两个方向
	int num2 = 0;//实际走的方向
	while (y != N - 1)
	{
		num1 = rand() % 5 + 1;//生成1到5
		num2 = rand() % 2 + 1;//生成1到2
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
	//打印游戏地图
	for (int i = 0; i < N; i++)
	{
		for (int m = 0; m < N; m++)
		{
			printf("%c", arr[i][m]);
		}
		printf("\n");
	}
}

//三叉树的创建
struct tree
{
	int x;//存取空白点的x坐标
	int y;//存取空白点的y坐标
	struct tree* tree1;//子树1
	struct tree* tree2;//子树2
	struct tree* tree3;//子树3
	struct tree* before;//指向父亲结点
};

////将迷宫创建二叉树的函数
struct tree* Deep_Use(char mi[][N], int x, int y, int info, struct tree* head)
{
	if (mi[x][y] == '*')//如果为*号就直接就返回NULL
	{
		return NULL;
	}
	struct tree* Mi_Tree = (struct tree*)malloc(sizeof(struct tree));//如果不是“*”就创建一颗子树
	Mi_Tree->before = head;
	Mi_Tree->x = x;
	Mi_Tree->y = y;
	mi[x][y] = '*';
	if (y == N - 1)  //如果y达到了出口坐标就返回该结点，此节点就是出口结点
	{
		Mi_Tree->tree1 = NULL;
		Mi_Tree->tree2 = NULL;
		Mi_Tree->tree3 = NULL;
		return Mi_Tree;
	}
	if (info == 1)//上，右，下
	{
		Mi_Tree->tree1 = Deep_Use(mi, x - 1, y, 4, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x, y + 1, 1, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x + 1, y, 2, Mi_Tree);
	}
	else if (info == 2)//左，下，右
	{
		Mi_Tree->tree1 = Deep_Use(mi, x, y - 1, 3, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x + 1, y, 2, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x, y + 1, 1, Mi_Tree);
	}
	else if (info == 3)//左，下，上
	{
		Mi_Tree->tree1 = Deep_Use(mi, x, y - 1, 3, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x + 1, y, 2, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x - 1, y, 4, Mi_Tree);
	}
	else//左，右，上
	{
		Mi_Tree->tree1 = Deep_Use(mi, x, y - 1, 3, Mi_Tree);
		Mi_Tree->tree2 = Deep_Use(mi, x, y + 1, 1, Mi_Tree);
		Mi_Tree->tree3 = Deep_Use(mi, x - 1, y, 4, Mi_Tree);
	}
	return Mi_Tree;
}
//寻找出口结点的函数
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
//打印正确路线的函数
struct tree* Print_Loca(struct tree* head)
{
	printf("开始打印路线\n");
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
		int x = 1, y = 0;//x初始坐标，y初始坐标
		chuang(mi, x, y);//创建迷宫的函数
		int info = 1;//，info表示其位置信息，方便搜索下三个走的位置
		printf("开始创建迷宫的三叉树\n");
		struct tree* head = Deep_Use(mi, x, y, info, NULL);//将迷宫创建二叉树的函数
		printf("完成迷宫的三叉树创建\n");
		struct tree* p;
		p = NULL;
		printf("开始寻找出口的地址\n");
		p = Deep_Find(head);//寻找出口结点的函数
		printf("成功寻找出口的地址\n");
		Print_Loca(p);//打印正确路线的函数
		printf("打印完成\n");
		printf("Enter 1 to start the program\nEnter 0 to end the program\n");
		xuan = 0;
		scanf("%d", &xuan);
	}

	return 0;
}

