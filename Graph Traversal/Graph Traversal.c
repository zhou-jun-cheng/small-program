# include<stdio.h>

//  Ŀ��:����ͼ�Ĺ�ȱ�������ȱ���  (�����ֿ���ͼ)
//  Objective: Regarding the breadth traversal and depth traversal of graphs (including separate graphs)


//�ڽӵ�ṹ�� Adjacent point structure
struct Adja_point
{
	int adja_data;//�ڽӵ�ı�� Number of Adjacent Points 
	struct Adja_data* next;
};

//���ڵ�
struct Ver_point
{
	int ver_data;//���������  Vertex data
	int mark;//�Ǻ�  mark
	struct Adja_data* first_next;
};

//�����ڽӱ�ĺ���  Function for creating adjacentcy table
void Make_List(struct Ver_point ver_arr[])
{
	int v1 = 0, v2 = 0;//v1:���� v2:�ڽӵ�  v1:vertex v2:Adjacent points
	//���� (make table)
	do
	{
		printf("�����붥�����ڽӵĵ�(Please enter the vertex and adjacent points):");
		scanf("%d %d", &v1, &v2);
		if (v1 != 0)
		{
			struct Adja_point* p = (struct Adja_point*)malloc(sizeof(struct Adja_point));//�����ڽӽ��(Create adjacent vertices)
			p->adja_data = v2;
			//ǰ�巨(Front insertion method)
			p->next = ver_arr[v1].first_next;
			ver_arr[v1].first_next = p;
		}
	} while (v1 != 0);
}

//��ȱ����ĺ���(Function for deep traversal)
void Depth_Tra(struct Ver_point ver_arr[], int point)
{
	printf("�ݷõ�(visit point):%d  ", point);
	ver_arr[point].mark = 1;//�ı�Ǻ�(change mark)
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

//������ȱ����ĺ���  Enter the function for deep traversal
void Depth(struct Ver_point ver_arr[], int ver_num)
{
	int point = 0;//��ı���(point variable)
	printf("��������Ҫ��ʼ��ȱ����Ķ���(Please enter the vertex where you want to start depth traversal):");
	scanf("%d", &point);
	Depth_Tra(ver_arr, point);//��ȱ���(depth-first traversal)
	//����ǲ��Ǳ������(check if traversal is complete)
	for (int i = 1; i <= ver_num; i++)
	{
		if (!ver_arr[i].mark)
		{
			Depth_Tra(ver_arr, i);//��ȱ���(depth-first traversal)
		}
	}
	//������֮�󽫼Ǻų�ʼ��  Initialize the tokens after traversal
	for (int i = 1; i <= ver_num; i++)
	{
		ver_arr[i].mark = 0;
	}
}


//������ȱ����Ķ���ṹ�� Vertex structures with breadth first traversal
struct Bre_str
{
	int sto;
	struct Bre_str* next;
};


//������ȱ����ĺ���  Breadth first traversal function
void Breadth_Tra(struct Ver_point ver_arr[], int point)
{

	struct Bre_str* head = (struct Bre_str*)malloc(sizeof(struct Bre_str));//�������еĶ��ڵ�  Create the top node of the queue
	struct Bre_str* q1;//���ɽ��  Transition Node
	q1 = head;
	head->next = NULL;//��ʼ��   initialization
	head->sto = point;//���  Join the team
	ver_arr[head->sto].mark = 1;
	struct Adja_point* p;
	p = NULL;
	while (head != NULL)
	{
		printf("�ݷõ�(visit point):%d  ", head->sto);//����  leave the line
		p = ver_arr[head->sto].first_next;
		while (p)
		{
			if (!ver_arr[p->adja_data].mark)//û�з��ʹ������  Join the team without visiting
			{
				ver_arr[p->adja_data].mark = 1;//�ı�Ǻ�  Change Mark
				struct Bre_str* q2 = (struct Bre_str*)malloc(sizeof(struct Bre_str));//�������еĹ��ɽڵ�  Create a transition node for the queue
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
		free(q3);//�ͷ��ڴ�  free memmory
		q3 = NULL;
	}
}

//���������ȵĺ����Ķ��� Definition of breadth first functions
void Breadth(struct Ver_point ver_arr[], int ver_num)
{
	int point = 0;//��ı��� (point variable)
	printf("��������Ҫ��ʼ��ȱ����Ķ���(Please enter the vertex where you want to start breadth traversal):");
	scanf("%d", &point);
	Breadth_Tra(ver_arr, point);//������ȱ����ĺ���  Breadth first traversal function
	for (int i = 1; i <= ver_num; i++)//����Ƿ��������  (check if traversal is complete)
	{
		if (!ver_arr[i].mark)
		{
			Breadth_Tra(ver_arr, i);//��ȱ���(Breadth traversal)
		}
	}
	//������֮�󽫼Ǻų�ʼ��(Initialize the tokens after traversal)
	for (int i = 1; i <= ver_num; i++)
	{
		ver_arr[i].mark = 0;
	}
}


//������
int main()
{
	int ver_num = 0;//������  Number of vertices
	printf("�����붥����Ŀ(enter the Number of vertices):");
	scanf("%d", &ver_num);
	//���ٶ�̬���ڵ�����  �±�Ϊ0�Ŀ��������䵱�ڱ��Ľ�ɫ(Opening up a dynamic top node array with index 0 can be used to act as a sentinel)
	struct Ver_point* ver_arr = (struct Ver_point*)malloc((ver_num + 1) * sizeof(struct Ver_point));
	for (int i = 0; i <= ver_num; i++) //��ʼ�� initialization
	{
		ver_arr[i].mark = 0;//���ǺŽ��г�ʼ�� Initialize the markers
		ver_arr[i].first_next = NULL;
	}
	Make_List(ver_arr);    //�����ڽӱ�ĺ���  Function for creating adjacency table
	printf("\n��ʼ������ȱ���(Start depth first traversal)\n");
	Depth(ver_arr, ver_num);//������ȱ����ĺ���  Enter the function for deep traversal
	printf("\n\n��ʼ������ȱ���(Start breadth first traversal)\n");
	Breadth(ver_arr, ver_num);//���������ȱ����ĺ���  Enter the breadth first traversal function    
	return 0;
}
