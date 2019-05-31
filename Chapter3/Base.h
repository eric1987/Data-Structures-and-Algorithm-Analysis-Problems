#ifndef BASE_H_
#define BASE_H_

#include <cstdlib>
#include <cstdio>

typedef int Element;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef struct DoublyNode *PtrDNode;
typedef PtrDNode DList;

struct Node
{
    Element element;
    Node *next;
}typedef Node;

struct DoublyNode
{
	Element element;
	DoublyNode *last;
	DoublyNode *next;
}typedef DoublyNode;

List CreateList(int len)
{
    List l = (List)malloc(sizeof(struct Node));
    PtrNode p = l;
    while (len-- > 0)
    {
        List tmp = (List)malloc(sizeof(struct Node));
        tmp->element = rand() %100;
        tmp->next = NULL;
        p->next = tmp;
        p = p->next;
    }

    List result = l->next;
    //l->next = NULL;
    free(l);
    return result;
}

DList CreateDList(int len)
{
	DList l = (DList)malloc(sizeof(struct DoublyNode));
	PtrDNode p = l;
	while (len-- > 0)
	{
		DList tmp = (DList)malloc(sizeof(struct DoublyNode));
		tmp->element = rand() % 100;
		tmp->last = p;
		tmp->next = NULL;
		p->next = tmp;
		p = p->next;
	}

	DList result = l->next;
	l->next = NULL;
	free(l);
	result->last = NULL;

	return result;
}

void PrintDList(DList l)
{
	printf("Print Doubly list.\n");
	if (l == NULL)
		return;
	else
	{
		while (l != NULL)
		{
			printf("element is: %d\n", l->element);
			l = l->next;
		}
	}
}

#endif