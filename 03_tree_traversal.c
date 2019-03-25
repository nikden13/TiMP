#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
    struct node *par;
}node;

typedef struct
{
    node *head;
    int size;
}tree;


//функции дерева
//инициализация дерева
void init(tree *t)
{
	t->head = NULL;
	t->size = 0;
}	

//вставка
int insert(tree *t, int value)
{
	node *tmp = malloc(sizeof(node));
	if (tmp == NULL)
		return 2;
	node *p = t->head;
	node *q = NULL;
	if (p)
	{
		while(p)
		{
			if (value < p->value)
			{
				q = p;
				p = p->left;
			}
			else if (value > p->value)
			{
				q = p;
				p = p->right;
			}
			else
				return 1; 
		}
		tmp->value = value;
		tmp->left = tmp->right = NULL;
		tmp->par = q;
		if (tmp->value > q->value)
			q->right = tmp;
		else 
			q->left = tmp;
		t->size++;
		return 0;
	}
	else
	{
		t->head = tmp;
		t->head->value = value;
		t->head->par = NULL;
		t->head->left = t->head->right = NULL;
		t->size++;
		return 0;
	}
}

//вывод (обратный обход)
void print(node *n)
{
	if (n)
	{	
		print(n->left);
		print(n->right);
		if (n->par)
			printf("%d ", n->value);
		else printf("%d", n->value);
	}
}

int main()
{
	tree t;
	init(&t);
	int i, a;
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &a);
		insert(&t, a);
	}
	print(t.head);
	printf("\n");
	return 0;
}
