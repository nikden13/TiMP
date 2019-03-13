#include <stdio.h>
#include <stdlib.h>

//нод списка
struct node
{
	int value;
	struct node *next;
};

//список
typedef struct
{
	struct node *head;
	unsigned int size;
} list;


//функции:

//инициализация
void init(list *l)
{
	l->head = NULL;
	l->size = 0;
}

//получение нового узла
struct node *get_node(int val)
{
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->value = val;
	tmp->next = NULL;
	return tmp;
}

//Очистка
void clear(list *l)
{
	struct node *pNext = l->head;
	struct node *tmp;
	while (pNext)
	{
		tmp = pNext->next;
		free(pNext);
		pNext = tmp;
	}
	l->head = NULL;
	l->size = 0;
}

//Проверка на пустоту списка
int isEmpty(list *l)
{
	return (l->head == NULL);
}

//Поиск элемента по значению
struct node *find(list *l, int val)
{
	struct node *tmp = l->head;
	while (tmp)
	{
		if (tmp->value == val) return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//Вставка значения в конец списка
int push_back(list *l, int val)
{
	struct node *tmp = l->head;
	if (tmp == NULL)
	{
		l->head = get_node(val);
		return 0;
	}
	while (tmp->next) tmp = tmp->next;
	tmp->next = get_node(val);
	l->size++;
	return 0;
}
//Вставка значения в начало списка
int push_front(list *l, int val)
{
	struct node *tmp;
	tmp = malloc(sizeof(struct node));
	tmp->value = val;
	tmp->next = l->head;
	l->head = tmp;
	l->size++;
	return 0;
}

//Вставка значения после указанного узла
int insertAfter(list *l, int val, unsigned int j)
{
	unsigned int i;
	struct node *tmp = malloc(sizeof(struct node));
	tmp->value = val;
	struct  node *q = l->head;
	struct  node *p = l->head;
	for (i = 0; i < j; i++)
	{
		p = q;
		q = q->next;
		 
	} 
	p->next = tmp;
	if (q)
	{
		tmp->next = q;
	}
	else
	{
		tmp->next = NULL;
	}
	return 0;
	
}

//Удаление первого элемента с указанным значением
int removeFirst(list *l, int val)
{
	struct node *tmp = l->head;
	struct node *p = l->head;
	while (tmp && tmp->value != val) 
	{	
		p = tmp; 
		tmp = tmp->next;
	}
	if (tmp)
	{
		if (tmp == l->head) 
			l->head = l->head->next;
		else
			p->next = tmp->next;
		free(tmp);
		l->size--;
	}
	return 0;	
}

//Вывод списка
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
print(l);

scanf("%d", &a);
push_front(&l, a);
print(l);

scanf("%d %d", &i, &a);
insertAfter(&l, a, i);
print(l);

scanf("%d", &a);
removeFirst(&l, a);
print(l);

clear(&l);
print(l);
return 0;
}















