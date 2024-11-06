# include<stdio.h>

// Ŀ��: �������Ĵ��� ������� ��α���
//Objective: Tocreat a binary tree and traverse its hinerarchy in order


//���뷽ʽΪ��������ǰ������,���Һ���Ϊ�յ�ʱ�����Һ���������,һ������һ������
// The input method is the preceding input of a binary tree. When the left and right children are empty, zero is inputted, and one data is inputted at a time



//�������Ľṹ��  The strcuture of a binary tree
struct Two_tree
{
	int data;//ֵ��  Date domain 
	struct Two_tree* left;//������ left subtree
	struct Two_tree* right;//������ right subtree
};


//�����������ĺ����Ķ���  Definition of the function for creating a binary tree
struct Two_tree* Make_Tree()
{
	int num = 0;//ֵ��  Date domain 
	printf("��������(enter date):");
	scanf("%d", &num);
	if (num == 0)//Ϊ��ͷ��ؿ�  Return null of it is zero
	{
		return NULL;
	}
	struct Two_tree* p = (struct Two_tree*)malloc(sizeof(struct Two_tree));//����ָ��  create pointer
	p->data = num;//ֵ��ֵ  value range assignment
	p->left = Make_Tree();//����������ݹ� The left subtree enters recursion
	p->right = Make_Tree();//����������ݹ� the right subterr enters recursion
	return p;
}

//ǰ������������ĺ����Ķ���    Definition of the Function for Traversing Binary Trees in precedence 
void Bef_Tree(struct Two_tree* p)
{
	if (p == NULL)//Ϊ�վ�ֹͣ����  stop traversing when empty
	{
		return;
	}
	printf("ǰ�����(Previous visit):%d\n", p->data);
	Bef_Tree(p->left);//�������ݹ�  Recursive left subtree
	Bef_Tree(p->right);//�������ݹ� Recursive right subtree
}

//��α����������������õĽṹ��  The structure used for traversing a binary tree in a hierarchical manner
struct Sto_tree
{
	struct Sto_tree* next;
	struct Two_tree* num;
};

//��α����������ĺ���(����)  Definition of the function for traversing a binary tree in a hierarchical manner
void Sto_Tree(struct Two_tree* p)
{
	struct Sto_tree* head = (struct Sro_tree*)malloc(sizeof(struct Sto_tree));//ͷָ��Ĵ���  creation of head pointer
	struct Sto_tree* q1;//��¼���ʵ�ָ�� record access pointers
	struct Sto_tree* q2;//��¼��β  record the end of the team
	q1 = NULL;
	q2 = NULL;
	head->next = NULL;
	head->num = p;//��������  join the team at the top node
	q1 = head;
	q2 = head;
	while (q1 != NULL)
	{
		if (q1->num)
			printf("��η���(Hierarchical Access):%d\n", q1->num->data);
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
//������
int main()
{
	struct Two_tree* head;//����ͷָ��  create header pointer
	head = Make_Tree();//�����������ĺ��� function for creating a binary tree
	printf("ǰ�����Ϊ:");
	Bef_Tree(head);//ǰ������������ĺ��� the function of traversing a binary tree in sequence
	printf("��α���Ϊ:");
	Sto_Tree(head);//��α����������ĺ���  function for traversing a binary tree at different levels
	return 0;
}