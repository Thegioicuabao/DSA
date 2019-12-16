#include<stdio.h>
#include<string.h>
typedef struct bigint
{
  char bigint[1000];
}BI;

typedef struct Node
{
  BI info;
  struct Node* pNext;
}NODE;

typedef struct List
{
  NODE* pHead;
  NODE* pTail;
}LIST;

void NhapBI(BI &x)
{
  printf("\nNhap Big int : ");
  fflush(stdin);
  gets(x.bigint);
}

void XuatBI(BI x)
{
  printf("\n%s", x.bigint);
}
void InitList(LIST &l)
{
  l.pHead = l.pTail = NULL;
}

int IsEmty(LIST l)
{
  return (l.pHead == NULL);
}
NODE* GetNode(BI &x)
{
  NODE* p = new NODE;
  if(p == NULL)
  {
    printf("Not enough memory for allocate");
    return NULL;
  }
  else
  {
    p->info = x;
    p->pNext = NULL;
  }
}


void AddTail(LIST &l, NODE* p)
{
  if (l.pHead == NULL)
  {
    l.pHead = l.pTail = p;
  }
  else
  {
    l.pTail->pNext = p;
    l.pTail = p;
  }
}

void InputList(LIST &l)
{
  int n;
  BI x;
  printf("Nhap so luong Big INT:");
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    NhapBI(x);
    NODE* p = GetNode(x);
    AddTail(l, p);
  }
}
void Display(LIST l)
{
  if(IsEmty(l))
  {
    return;
  }
  for(NODE* i = l.pHead; i!=NULL; i=i->pNext)
  {
    XuatBI(i->info);
  }
}
void swap(BI &x,BI &y)
{
	BI temp = x;
	x=y;
	y=temp;
}

void ListSelectionSort(LIST l)
{
	NODE *min, *i, *j;
  int x,c;
  for(i=l.pHead; i!=l.pTail; i=i->pNext)
  {
    for(int n=0; n<strlen(i->info.bigint); n++)
    {
      x = (int)i->info.bigint[n] - 48;
    }
    for(j=i->pNext; j!=NULL; j=j ->pNext)
    {
      if (strlen(i->info.bigint) > strlen(j->info.bigint))
      {
        x = 1;
        c = 0;
      }
      else if (strlen(i->info.bigint) < strlen(j->info.bigint))
      {
        x = 0;
        c = 1;
      }
      else {
        for(int m=0; m<strlen(j->info.bigint); m++)
        {
          c = (int)j->info.bigint[m] - 48;
        }
      }
      if(x>c)
        swap(i->info, j->info);
    }
  }
}
int main()
{
  LIST l;
  InitList(l);
  InputList(l);
  Display(l);
  ListSelectionSort(l);
  printf("\n");
    Display(l);
  return 0;
}
