#include<stdio.h>

typedef struct Student
{
  char masv[10];
  char hoten[30];
  float dtb;
}SV;

typedef struct Node
{
  SV info;
  struct Node* pNext;
}NODE;

typedef struct List
{
  NODE* pHead;
  NODE* pTail;
}LIST;

void Nhap1Sv(SV &x)
{
  printf("\nNhap MSSV : ");
  fflush(stdin);
  gets(x.masv);
  printf("\nNhap ho ten : ");
  gets(x.hoten);
  printf("\nNhap diem tb : ");
  scanf("%f", &x.dtb);
}

void Xuat1Sv(SV x)
{
  printf("\n%-15s %-15s %-15f", x.masv, x.hoten, x.dtb);
}
void InitList(LIST &l)
{
  l.pHead = l.pTail = NULL;
}

int IsEmty(LIST l)
{
  return (l.pHead == NULL);
}
NODE* GetNode(SV &x)
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

void AddFirst(LIST &l, NODE* p)
{
  if(l.pHead == NULL)
  {
    l.pHead = l.pTail = p;
  }
  else
  {
    p->pNext = l.pHead;
    l.pHead = p;
  }
}

void InputList(LIST &l)
{
  int n;
  SV x;
  printf("Nhap so luong sinh vien :");
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    Nhap1Sv(x);
    NODE* p = GetNode(x);
    AddFirst(l, p);
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
    Xuat1Sv(i->info);
  }
}

int main()
{
  LIST l;
  InitList(l);
  InputList(l);
  Display(l);
  return 0;
}
