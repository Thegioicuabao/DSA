#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100

struct CuonSach
{
	int masach;
	char tensach[40];
	float gia;
};
typedef struct CuonSach Sach;

void nhap1sach(Sach &x)
{
	printf("Nhap ma sach: "); scanf("%d", &x.masach);
  fflush(stdin);
  printf("Nhap ten sach: "); gets(x.tensach);
	printf("Nhap gia: "); scanf("%f", &x.gia);
}

void xuat1sach(Sach x)
{
  printf("%d -- %s -- %.2f  \n", x.masach, x.tensach, x.gia );
}

void nhapsophantu(int &n)
{
  do {
    printf("Nhap so phan tu :");
    scanf("%d", &n);
  }
  while ( n<=0 || n > MAX);
}

void nhapDS(Sach a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("\nNhap sach thu %d\n", i+1);
    nhap1sach(a[i]);
  }
}

void xuatDS(Sach a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d.\t", i+1);
    xuat1sach(a[i]);
  }
}

int main() {
  Sach a[MAX];
  int n;
  nhapsophantu(n);
  nhapDS(a,n);
  xuatDS(a,n);
  return 0;
}
