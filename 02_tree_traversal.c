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

//струтура стека

typedef struct stack_node
{
    node *ptr_node_tree;
    struct stack_node *next;
}stack_node;

typedef struct
{
    stack_node *top;
}stack;

//инициализация очереди
void init_stack(stack *s)
{
	s->top = NULL;;
}

//добавление
void push(stack *s, node *n)
{
	stack_node *ns = malloc(sizeof(stack_node));
	ns->ptr_node_tree = n;
	if(s->top)
	{
		ns->next = s->top;
		s->top = ns; 
	}
	else
	{
		s->top = ns;
		ns->next = NULL;
	}
}

//извлечение и удаление
node *pop(stack *s)
{
	if (s->top)
	{
		stack_node *ns = s->top;
		node *tmp = s->top->ptr_node_tree;
		s->top = s->top->next;
		free(ns);
		return tmp;
	}
	else return NULL;
}


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

//вывод (прямой обход)
void print(node *n)
{
	if (n)
	{	
		stack s;
		init_stack(&s);
		push(&s, n);
		while (s.top)
		{
			node *tmp = pop(&s);
			if (tmp->right)
				push(&s, tmp->right);
			if (tmp->left)
				push(&s, tmp->left);
			if (s.top == NULL)
				printf("%d", tmp->value);
			else printf("%d ", tmp->value);
		}
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
