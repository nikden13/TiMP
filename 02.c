#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
int value;
struct node *next;
struct node *prev;
}node;

typedef struct
{
node *head;
node *tail;
}list;

//инициализация
void init(list *l)
{
l->head = NULL;
l->tail = NULL;
}

/*//получение нового узла
node *get_node(int val)
{
node *tmp;
tmp = (node*)malloc(sizeof(node));
tmp -> value = val;
tmp->next = NULL;
tmp->prev = NULL;
return tmp;
}*/

//очистка списка
void clear(list *l)
{
node *tmp = l->head;
node *p = NULL;
while(tmp)
{
p = tmp->next;
free(tmp);
tmp = p;
}
l->head = NULL;
l->tail = NULL;
}

//проверка на пустоту
int isEmpty(list l)
{
	return (l.head == NULL && l.tail == NULL);
}

//поиск элемента по значению
node *find(list *l, int val)
{
node *tmp = l->head;
while (tmp)
{
if (tmp->value == val) return tmp;
tmp = tmp->next;
} 
return NULL;
}
//Вывод
void print(list l)
{
	struct node *tmp = l.head;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

//добавление в конец списка
int  push_back(list* l, int val)
{
	node* tmp = malloc(sizeof(node));
	tmp->value = val;
	if(isEmpty(*l))
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		l->head = tmp;
		l->tail = tmp;
	}
	else
	{
		l->tail->next = tmp;
		tmp->next = NULL;
		tmp->prev = l->tail;
		l->tail = tmp;
	}
	return 0;
}

//Вставка в начало списка
int push_front(list *l, int val)
{
	node *tmp = malloc(sizeof(node));
	tmp->value = val;
	l->head->prev = tmp;
	tmp->next = l->head;
	tmp->prev = NULL;
	l->head = tmp;
	return 0;
}

//Вставка значения после указанного узла
int insertAfter(list *l, int val, unsigned int i)
{
	unsigned int j;
	node *tmp = malloc(sizeof(node));
	tmp->value = val;
	struct  node *p = l->head;
	struct  node *q = l->head;
	for (j = 0; j < i; j++)
	{
		p = q;
		q = q->next;
	}
	p->next = tmp;
	tmp->prev = p;
	if (q)
	{
		tmp->next = q;
		q->prev = tmp;
	}
	else
	{
		tmp->next = NULL;
		l->tail = tmp;
	}
	return 0;
}

//Вставка значения перед указанным узлом
int insertBefore(list *l, int val, unsigned int i)
{
	unsigned int j;
	node *tmp = malloc(sizeof(node));
	tmp->value = val;
	struct  node *p = NULL;
	struct  node *q = l->head;
	for (j = 0; j < i-1; j++)
	{
		p = q;
		q = q->next;
	}
	if (p)
	{
		tmp->next = q;
		q->prev = tmp;
		p->next = tmp;
		tmp->prev = p;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = q;
		q->prev = tmp;
		l->head = tmp;
	}
	return 0;
}

//Удаление первого элемента с указанным значением
int removeFirst(list *l, int val)
{
	node* tmp = l->head;
	node* p = l->head;
	while(tmp && tmp->value != val) 
	{
		p = tmp;
		tmp = tmp->next;
	}
	if(tmp)
	{
		if (tmp == l->head) 
			{
				l->head = l->head->next;
				l->head->prev = NULL;
			}
		else if (tmp == l->tail) 
			{
				l->tail = l->tail->prev;
				l->tail->next = NULL;
			}
		else
			{
				p->next = tmp->next;
				tmp->next->prev = p;			
			}
		free(tmp);
	}
	return 0;
}

//Удаление последнего элемента из списка
int removeLast(list *l, int val)
{
	node* tmp = l->tail;
	node* p = l->tail;
	while(tmp && tmp->value != val) 
	{
		p = tmp;
		tmp = tmp->prev;
	}
	if(tmp)
	{
		if (tmp == l->head) 
			{
				l->head = l->head->next;
				l->head->prev = NULL;
			}
		else if (tmp == l->tail) 
			{
				l->tail = l->tail->prev;
				l->tail->next = NULL;
			}
		else
			{
				p->prev = tmp->prev;
				tmp->prev->next = p;			
			}
		free(tmp);
	}
	return 0;
}

//Вывод списка в обратном порядке
void print_invers(list l)
{
	struct node *tmp = l.tail;
	while (tmp)
	{
		printf("%d   ", tmp->value);
		tmp = tmp->prev;
	}
	printf("\n");
}



int main()
{
unsigned int i, j;
int a;
list l;
init(&l);
scanf("%d", &i);
for (j = 0; j < i; j++)
{
	scanf("%d", &a);
	push_back(&l, a);
}
print(l);

scanf("%d", &i);
for (j = 0; j < i; j++)
{
	scanf("%d", &a);
	if (find(&l, a)) printf("1\n");
	else printf("0\n");
}

scanf("%d", &a);
push_back(&l, a);
print_invers(l);

scanf("%d", &a);
push_front(&l, a);
print(l);

scanf("%d %d", &i, &a);
insertAfter(&l, a, i);
print_invers(l);;

scanf("%d %d", &i, &a);
insertBefore(&l, a, i);
print(l);

scanf("%d", &a);
removeFirst(&l, a);
print_invers(l);

scanf("%d", &a);
removeLast(&l, a);
print(l);

clear(&l);
print(l);
return 0;
}
