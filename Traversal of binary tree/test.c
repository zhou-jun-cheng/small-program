# include<stdio.h>

// 目标: 二叉树的创建 先序遍历 层次遍历
//Objective: Tocreat a binary tree and traverse its hinerarchy in order


//输入方式为二叉树的前序输入,左右孩子为空的时候将左右孩子输入零,一次输入一个数据
// The input method is the preceding input of a binary tree. When the left and right children are empty, zero is inputted, and one data is inputted at a time



//二叉树的结构体  The strcuture of a binary tree
struct Two_tree
{
	int data;//值域  Date domain 
	struct Two_tree* left;//左子树 left subtree
	struct Two_tree* right;//右子树 right subtree
};


//创建二叉树的函数的定义  Definition of the function for creating a binary tree
struct Two_tree* Make_Tree()
{
	int num = 0;//值域  Date domain 
	printf("输入数据(enter date):");
	scanf("%d", &num);
	if (num == 0)//为零就返回空  Return null of it is zero
	{
		return NULL;
	}
	struct Two_tree* p = (struct Two_tree*)malloc(sizeof(struct Two_tree));//创建指针  create pointer
	p->data = num;//值域赋值  value range assignment
	p->left = Make_Tree();//左子树进入递归 The left subtree enters recursion
	p->right = Make_Tree();//右子树进入递归 the right subterr enters recursion
	return p;
}

//前序遍历二叉树的函数的定义    Definition of the Function for Traversing Binary Trees in precedence 
void Bef_Tree(struct Two_tree* p)
{
	if (p == NULL)//为空就停止遍历  stop traversing when empty
	{
		return;
	}
	printf("前序访问(Previous visit):%d\n", p->data);
	Bef_Tree(p->left);//左子树递归  Recursive left subtree
	Bef_Tree(p->right);//右子树递归 Recursive right subtree
}

//层次遍历二叉树队列所用的结构体  The structure used for traversing a binary tree in a hierarchical manner
struct Sto_tree
{
	struct Sto_tree* next;
	struct Two_tree* num;
};

//层次遍历二叉树的函数(队列)  Definition of the function for traversing a binary tree in a hierarchical manner
void Sto_Tree(struct Two_tree* p)
{
	struct Sto_tree* head = (struct Sro_tree*)malloc(sizeof(struct Sto_tree));//头指针的创建  creation of head pointer
	struct Sto_tree* q1;//记录访问的指针 record access pointers
	struct Sto_tree* q2;//记录队尾  record the end of the team
	q1 = NULL;
	q2 = NULL;
	head->next = NULL;
	head->num = p;//顶结点入队  join the team at the top node
	q1 = head;
	q2 = head;
	while (q1 != NULL)
	{
		if (q1->num)
			printf("层次访问(Hierarchical Access):%d\n", q1->num->data);
		if (q1->num->left)
		{
			struct Sto_tree* m = (struct Sro_tree*)malloc(sizeof(struct Sto_tree));
			m->next = q2->next;
			m->num = q1->num->left;
			q2->next = m;
			q2 = m;
		}
		if (q1->num->right)
		{
			struct Sto_tree* m = (struct Sro_tree*)malloc(sizeof(struct Sto_tree));
			m->next = q2->next;
			m->num = q1->num->right;
			q2->next = m;
			q2 = m;
		}
		q1 = q1->next;
	}
}
//主函数
int main()
{
	struct Two_tree* head;//创建头指针  create header pointer
	head = Make_Tree();//创建二叉树的函数 function for creating a binary tree
	printf("前序遍历为:");
	Bef_Tree(head);//前序遍历二叉树的函数 the function of traversing a binary tree in sequence
	printf("层次遍历为:");
	Sto_Tree(head);//层次遍历二叉树的函数  function for traversing a binary tree at different levels
	return 0;
}