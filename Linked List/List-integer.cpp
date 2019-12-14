#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE;

typedef struct List
{
	NODE* pHead;
	NODE* pTail;
}LIST;

void InitList(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

int ListIsEmty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}

NODE* InitNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		printf("Khong du bo nho de cap phat\n");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
}

void AddFirt(LIST &l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		return;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(LIST &l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		return;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void InputList(LIST &l)
{
	int n, x;
	InitList(l);
	NODE* p;
	printf("Moi nhap so luong nut");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("Moi nhap x");
		scanf("%d", &x);
		p = InitNode(x);
		AddFirt(l,p);
	}
}

void OutputList(LIST l)
{
	for(NODE* i = l.pHead; i!=NULL; i = i->pNext )
	{
		printf("%d->", i->data);
	}
		printf("NULL");
}

int FindMax(LIST l)
{
	int max = l.pHead->data;
	for(NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		if(max < i->data)
			max = i-> data;
	}
	return max;
}

void DeleteHead(LIST &l)
{
	NODE* p;
	p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	if(l.pHead==NULL)
			l.pTail = NULL;

	printf("\n%d\n%d\n", l.pHead, l.pTail);
}
void DeleteTail(LIST &l)
{
	NODE* p, *i;
	if(l.pHead==l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
		return;
	}
	for(i=l.pHead;i->pNext!=l.pTail;i=i->pNext);
	p=l.pTail;
	l.pTail = i;
	l.pTail->pNext = NULL;
	delete p;
		printf("\n%d\n%d\n", l.pHead, l.pTail);
}
int main()
{
	LIST l;
	InputList(l);
	OutputList(l);
	DeleteTail(l);
	OutputList(l);
	return 0;
}
