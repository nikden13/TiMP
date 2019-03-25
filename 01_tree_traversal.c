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

//струтура очереди

typedef struct queue_node
{
    node *ptr_node_tree;
    struct queue_node *next;
}queue_node;

typedef struct
{
    queue_node *head;
    queue_node *tail;
}queue;

//инициализация очереди
void init_queue(queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

//добавление
void push(queue *q, node *n)
{
	queue_node *nq = malloc(sizeof(queue_node));
	nq->ptr_node_tree = n;
	if(q->head)
	{
		q->tail->next = nq;
		nq->next = NULL;
		q->tail = nq;
	}
	else
	{
		q->head = q->tail = nq;
		nq->next = NULL;
	}
}

//извлечение и удаление
node *pop(queue *q)
{
	if (q->head)
	{
		queue_node *nq = q->head;
		node *tmp = q->head->ptr_node_tree;
		q->head = q->head->next;
		if (q->head == NULL)
			q->tail = NULL;
		free (nq);
		return tmp;
	}
	else return NULL;
}

//очистка
void clear_queue(queue *q)
{
	if (q->head)
	{
		queue_node *nq;
		while (q->head)
		{
			nq = q->head;
			q->head = q->head->next;
			free(nq);
		}
	}
	q->head = q->tail = NULL;
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

//вывод (обход в ширину)
void print(node *n)
{
	if (n)
	{	
		queue q1, q2;
		init_queue(&q1);
		init_queue(&q2);
		push(&q1, n);
		while(1)
		{
			while(q1.head)
			{
				node *tmp  = pop(&q1);
				if (tmp->left)
					push(&q2, tmp->left);
				if (tmp->right)
					push(&q2, tmp->right);
				if (q1.head == NULL && q2.head == NULL)
					printf("%d", tmp->value);
				else printf("%d ", tmp->value);
			}
			if (q2.head == NULL)
				break;
			q1.head = q2.head;
			q1.tail = q2.tail;
			queue_node *temp = q1.head;
			while (q2.head)
			{
				temp->next = q2.head->next;
				q2.head = q2.head->next;
				temp = temp->next;
			}
			clear_queue(&q2);
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

