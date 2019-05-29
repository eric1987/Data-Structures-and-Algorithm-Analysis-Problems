#ifndef BASE_H_
#define BASE_H_

#include <cstdlib>

typedef int Element;
typedef struct Node *PtrNode;
typedef PtrNode List;

struct Node
{
    Element element;
    Node *next;
}typedef Node;

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
    l->next = NULL;
    free(l);
    return result;
}

#endif