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
//ͨ��ֻ����ָ�루���������ݣ��������������ڵ�Ԫ��
//������:orig1Ϊ��������Ԫ�ص�ǰһ��Ԫ��
int ChangeElement(List &l, PtrNode orig1)
{
	if (l == NULL || orig1->next == NULL)
		return -1;
	else
	{	
		PtrNode pre1 = NULL;
		PtrNode temp = l;
		
		if (orig1 == l)
		{
			PtrNode orig2 = orig1->next;
			orig1->next = orig2->next;
			orig2->next = orig1;
			l = orig2;
		}
		else
		{
			while (temp != NULL)
			{
				if (temp->next == orig1)
				{
					pre1 = temp;
					break;
				}
				else
					temp = temp->next;
			}

			PtrNode orig2 = orig1->next;
			orig1->next = orig2->next;
			orig2->next = orig1;
			pre1->next = orig2;
		}
		
		return 0;
	}
}

void TestChangeElementList()
{
	printf("Test Change Element in List.\n");
	List l = CreateList(4);
	printf("Before change element. \n");

	PrintList(l);
	
	printf("===After change element.===\n");
	PtrNode p = l->next->next;
	ChangeElement(l, p);
	PrintList(l);
}

//˫����:orig1Ϊ��������Ԫ�ص�ǰһ��Ԫ��
int ChangeElement(DList &l, PtrDNode orig1)
{
	if (l == NULL || orig1->next == NULL)
		return -1;
	else
	{
		//orig1Ϊ��ʼԪ��
		if (l == orig1)
		{
			PtrDNode orig2 = orig1->next;
			orig1->next = orig2->next;
			orig1->last = orig2;

			orig2->last = NULL;
			orig2->next = orig1;
			
			l = orig2;
		}
		//orig1��Ϊ��ʼԪ��
		else
		{
			PtrDNode orig2 = orig1->next;
			PtrDNode pre1 = orig1->last;

			orig1->next = orig2->next;
			orig1->last = orig2;

			pre1->next = orig2;
			orig2->last = pre1;
			orig2->next = orig1;
		}

		return 0;
	}
}

void TestChangeElementDList()
{
	printf("Test Change Element in DList.\n");
	DList l = CreateDList(4);
	printf("Before change element. \n");
	PrintDList(l);
	printf("===After change element.===\n");
	PtrDNode p = l->next;
	ChangeElement(l, p);
	PrintDList(l);
}

//3.4 ��������������ı�L1��L2��ֻʹ�û����ı������д����L1&&L2�Ĺ���
//����L1��L2��������������
List Intersection(List l1, List l2)
{
	List l = (List)malloc(sizeof(struct Node));
	PtrNode p = l;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->element == l2->element)
		{
			List temp = (List)malloc(sizeof(struct Node));
			temp->element = l1->element;
			p->next = temp;
			temp->next = NULL;
			p = p->next;

			l1 = l1->next;
			l2 = l2->next;
		}
		else if (l1->element > l2->element)
		{
			l2 = l2->next;
		}
		else
		{
			l1 = l1->next;
		}
	}

	List result = l->next;
	l->next = NULL;
	free(l);
	return result;
}

void CreateOrderList(List &list1, List &list2)
{
	List l1 = (List)malloc(sizeof(struct Node));
	PtrNode p = l1;
	for (size_t i = 0; i < 10; i++)
	{
		List temp = (List)malloc(sizeof(struct Node));
		temp->element = i;
		temp->next = NULL;
		p->next = temp;
		p = p->next;
	}
	list1 = l1->next;

	List l2 = (List)malloc(sizeof(struct Node));
	p = l2;
	List l2_e1 = (List)malloc(sizeof(struct Node));
	l2_e1->element = 3;
	p->next = l2_e1;
	p = p->next;

	List l2_e2 = (List)malloc(sizeof(struct Node));
	l2_e2->element = 4;
	p->next = l2_e2;
	p = p->next;

	List l2_e3 = (List)malloc(sizeof(struct Node));
	l2_e3->element = 11;
	p->next = l2_e3;
	p = p->next;
	l2_e3->next = NULL;

	list2 = l2->next;

	printf("========print List1========.\n");
	PrintList(list1);
	printf("========print List2========.\n");
	PrintList(list2);
}

void Test3_4()
{
	List list1, list2;
	CreateOrderList(list1, list2);

	List result = Intersection(list1, list2);
	printf("========Intersection List========.\n");
	PrintList(result);
}

//3.5 ��������������ı�L1��L2��ֻʹ�û����ı������д����L1||L2�Ĺ���
//����L1��L2��������������

void InsertSmaller(PtrNode &p, List &l1, List &l2)
{
	List temp = (List)malloc(sizeof(struct Node));
	
	if (l1->element == l2->element)
	{
		temp->element = l1->element;
		l1 = l1->next;
		l2 = l2->next;
	}
	else if (l1->element > l2->element)
	{
		temp->element = l2->element;
		l2 = l2->next;
	}
	else
	{
		temp->element = l1->element;
		l1 = l1->next;
	}

	temp->next = NULL;
	p->next = temp;
	p = p->next;
}

List Union(List l1, List l2)
{
	List l = (List)malloc(sizeof(struct Node));
	PtrNode p = l;

	while (l1 != NULL && l2 != NULL)
	{
		InsertSmaller(p, l1, l2);
	}
	if (l1 == NULL)
	{
		while (l2 != NULL)
		{
			List temp = (List)malloc(sizeof(struct Node));
			temp->element = l2->element;
			l2 = l2->next;
			temp->next = NULL;
			p->next = temp;
			p = p->next;
		}
	}
	else if (l2 == NULL)
	{
		while (l1 != NULL)
		{
			List temp = (List)malloc(sizeof(struct Node));
			temp->element = l1->element;
			l1 = l1->next;
			temp->next = NULL;
			p->next = temp;
			p = p->next;
		}
	}

	List result = l->next;
	l->next = NULL;
	free(l);
	return result;
}

void Test3_5()
{
	List list1, list2;
	CreateOrderList(list1, list2);

	List result = Union(list1, list2);
	printf("========Intersection List========.\n");
	PrintList(result);
}

//3.6 ��д����������ʽ��ӵĺ�������Ҫ�ٻ��������ݡ���һ�������ʾ��
//�������������ʽ�ֱ���M���N���ô��ĳ����ʱ�临�Ӷ��Ƕ��٣�

//��������3.5�ϲ��ķ�ʽ��ʱ�临�Ӷ�ΪO(M+N)
void PolynomialSum(List l1, List l2)
{

}

//3.7 
void PolynomialMulti()
{
	//����������ˣ��õ�MN���������
	//��MN����������������ʱ�临�Ӷ�ΪO(M^2*N^2)

	
}

int main()
{
	Test3_5();

    return 0;
}