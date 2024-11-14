# include<stdio.h>

//  目标:关于图的广度遍历与深度遍历  (包括分开的图)
//  Objective: Regarding the breadth traversal and depth traversal of graphs (including separate graphs)


//邻接点结构体 Adjacent point structure
struct Adja_point
{
	int adja_data;//邻接点的编号 Number of Adjacent Points 
	struct Adja_data* next;
};

//顶节点
struct Ver_point
{
	int ver_data;//顶点的数据  Vertex data
	int mark;//记号  mark
	struct Adja_data* first_next;
};

//创建邻接表的函数  Function for creating adjacentcy table
void Make_List(struct Ver_point ver_arr[])
{
	int v1 = 0, v2 = 0;//v1:顶点 v2:邻接点  v1:vertex v2:Adjacent points
	//建表 (make table)
	do
	{
		printf("请输入顶点与邻接的点(Please enter the vertex and adjacent points):");
		scanf("%d %d", &v1, &v2);
		if (v1 != 0)
		{
			struct Adja_point* p = (struct Adja_point*)malloc(sizeof(struct Adja_point));//创建邻接结点(Create adjacent vertices)
			p->adja_data = v2;
			//前插法(Front insertion method)
			p->next = ver_arr[v1].first_next;
			ver_arr[v1].first_next = p;
		}
	} while (v1 != 0);
}

//深度遍历的函数(Function for deep traversal)
void Depth_Tra(struct Ver_point ver_arr[], int point)
{
	printf("拜访点(visit point):%d  ", point);
	ver_arr[point].mark = 1;//改变记号(change mark)
	struct Adja_point* p;
	p = ver_arr[point].first_next;
	while (p)
	{
		if (!ver_arr[p->adja_data].mark)
		{
			Depth_Tra(ver_arr, p->adja_data);
		}
		p = p->next;
	}
}

//进入深度遍历的函数  Enter the function for deep traversal
void Depth(struct Ver_point ver_arr[], int ver_num)
{
	int point = 0;//点的变量(point variable)
	printf("请输入你要开始深度遍历的顶点(Please enter the vertex where you want to start depth traversal):");
	scanf("%d", &point);
	Depth_Tra(ver_arr, point);//深度遍历(depth-first traversal)
	//检测是不是遍历完毕(check if traversal is complete)
	for (int i = 1; i <= ver_num; i++)
	{
		if (!ver_arr[i].mark)
		{
			Depth_Tra(ver_arr, i);//深度遍历(depth-first traversal)
		}
	}
	//遍历完之后将记号初始化  Initialize the tokens after traversal
	for (int i = 1; i <= ver_num; i++)
	{
		ver_arr[i].mark = 0;
	}
}


//广度优先遍历的顶点结构体 Vertex structures with breadth first traversal
struct Bre_str
{
	int sto;
	struct Bre_str* next;
};


//广度优先遍历的函数  Breadth first traversal function
void Breadth_Tra(struct Ver_point ver_arr[], int point)
{

	struct Bre_str* head = (struct Bre_str*)malloc(sizeof(struct Bre_str));//创建队列的顶节点  Create the top node of the queue
	struct Bre_str* q1;//过渡结点  Transition Node
	q1 = head;
	head->next = NULL;//初始化   initialization
	head->sto = point;//入队  Join the team
	ver_arr[head->sto].mark = 1;
	struct Adja_point* p;
	p = NULL;
	while (head != NULL)
	{
		printf("拜访点(visit point):%d  ", head->sto);//出队  leave the line
		p = ver_arr[head->sto].first_next;
		while (p)
		{
			if (!ver_arr[p->adja_data].mark)//没有访问过就入队  Join the team without visiting
			{
				ver_arr[p->adja_data].mark = 1;//改变记号  Change Mark
				struct Bre_str* q2 = (struct Bre_str*)malloc(sizeof(struct Bre_str));//创建队列的过渡节点  Create a transition node for the queue
				q2->sto = p->adja_data;
				q2->next = q1->next;
				q1->next = q2;
				q1 = q2;
			}
			p = p->next;
		}
		struct Bre_str* q3;
		q3 = head;
		head = head->next;
		free(q3);//释放内存  free memmory
		q3 = NULL;
	}
}

//进入广度优先的函数的定义 Definition of breadth first functions
void Breadth(struct Ver_point ver_arr[], int ver_num)
{
	int point = 0;//点的变量 (point variable)
	printf("请输入你要开始广度遍历的顶点(Please enter the vertex where you want to start breadth traversal):");
	scanf("%d", &point);
	Breadth_Tra(ver_arr, point);//广度优先遍历的函数  Breadth first traversal function
	for (int i = 1; i <= ver_num; i++)//检查是否遍历结束  (check if traversal is complete)
	{
		if (!ver_arr[i].mark)
		{
			Breadth_Tra(ver_arr, i);//广度遍历(Breadth traversal)
		}
	}
	//遍历完之后将记号初始化(Initialize the tokens after traversal)
	for (int i = 1; i <= ver_num; i++)
	{
		ver_arr[i].mark = 0;
	}
}


//主函数
int main()
{
	int ver_num = 0;//顶点数  Number of vertices
	printf("请输入顶点数目(enter the Number of vertices):");
	scanf("%d", &ver_num);
	//开辟动态顶节点数组  下标为0的可以用来充当哨兵的角色(Opening up a dynamic top node array with index 0 can be used to act as a sentinel)
	struct Ver_point* ver_arr = (struct Ver_point*)malloc((ver_num + 1) * sizeof(struct Ver_point));
	for (int i = 0; i <= ver_num; i++) //初始化 initialization
	{
		ver_arr[i].mark = 0;//将记号进行初始化 Initialize the markers
		ver_arr[i].first_next = NULL;
	}
	Make_List(ver_arr);    //创建邻接表的函数  Function for creating adjacency table
	printf("\n开始深度优先遍历(Start depth first traversal)\n");
	Depth(ver_arr, ver_num);//进入深度遍历的函数  Enter the function for deep traversal
	printf("\n\n开始广度优先遍历(Start breadth first traversal)\n");
	Breadth(ver_arr, ver_num);//进入广度优先遍历的函数  Enter the breadth first traversal function    
	return 0;
}
