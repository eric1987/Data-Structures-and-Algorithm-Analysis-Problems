#include "pch.h"
#include "Base.h"
#include <cstdio>

//3.1
void PrintList(List l)
{
    if (l == NULL)
        return;
    PtrNode p = l;
    while(p != NULL)
    {
        printf("element is: %d\n", p->element);
        p = p->next;
    }
}

//3.2
void PrintLots(List l, List p)
{
    if (p == NULL || l == NULL)
        return;
    PtrNode tmp = p;
    while(tmp != NULL)
    {
        PtrNode print_tmp = l;
        int print_index = tmp->element;
        while(--print_index > 0 && print_tmp != NULL)
        {
            print_tmp = print_tmp->next;
        }
		if (print_tmp != NULL)
		{
			printf("The %d number of List l is: %d.\n", tmp->element, print_tmp->element);
		}
        tmp = tmp->next;
    }
}

//3.3
//通过只调整指针（而不是数据）来交换两个相邻的元素
//单链表、双链表
void ChangeElement(List l)
{

}

void ChangeElement()
{

}

int main()
{
    printf("start running.\n");
    List l = CreateList(10);
    List p = CreateList(2);
    PrintList(l);
    PrintList(p);
    PrintLots(l, p);

    return 0;
}