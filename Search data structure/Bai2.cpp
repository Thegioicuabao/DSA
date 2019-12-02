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
void linearSearch(Sach a[], int n, int x) {
	int flag = 0;
	printf("Nhap ma sach can tim : ");
	scanf("%d", &x);
  for (int i = 0; i < n; i++)
    if(x==a[i].masach)
		{
			xuat1sach(a[i]);
			flag = 1;
		}
		if(flag == 0) printf("Khong tim thay !!!" );
}

void swap(Sach x, Sach y)
{
    Sach temp = x;
    x = y;
    y = temp;
}

void InterchangeSort(Sach a[], int n)
{
   for (int i = 0; i < n-1; i++)
      for (int j = i+1; j < n; j++)
					 if (a[i].masach > a[j].masach)
	          {
							  Sach temp = a[i];
								a[i] =  a[j];
								a[j] = temp;
						}
}

void binarySearch(Sach a[], int n, int x) {

	int flag = 0;
	printf("Nhap ma sach can tim : ");
	scanf("%d", &x);
  int l = 0;
	int r = n - 1;
  while (l<=r)
  {
    int m = (l+r)/2;
    if(x == a[m].masach)
		{
			flag = 1;
			xuat1sach(a[m]);
			break;
		}
 	  else if (x < a[m].masach)
			r = m - 1;
    else if (x > a[m].masach)
			l = m + 1;
  }
		if(flag == 0) printf("Khong tim thay !!!" );
}
int main() {
  Sach a[MAX];
  int n, x;
  nhapsophantu(n);
  nhapDS(a,n);
  xuatDS(a,n);
	linearSearch(a,n,x);
	InterchangeSort(a,n);
  printf("\nDanh sach sau khi sap xep :\n");
  xuatDS(a,n);
	binarySearch(a,n,x);
  return 0;
}
