



void BubbleSort(int a[], int n){
  for(int i=0; i<n-1; i++)
    for(int j=n-1; j<i;i--)
      if(a[j-1]>a[j])
        swap(a[j-1],a[j]);
}

void InterchangeSort(int a[], int n){
  for(int i = 0; i<n-1; i++)
    for(int j = i+1; j < n;j++)
      a[i]>a[j];
}

void selectionSort(int a[], int n){
  for(int i=0; i<n-1; i++)
   int vtmin = i;
    for(int j=i+1; j<n; j++)
      if(a[j] < a[vtmin]) vtmin = j;
    swap(a[vtmin], a[i])
}

void insertionSort(int a[], int n){
  int x,pos;
  for(int i=1; i<n; i++){
    x=a[i], pos=i-1;
    while(pos>=0 && a[pos]>x)
    {
      a[pos+1] = a[pos];
      pos--;
    }
    a[pos+1] = x;
  }
}
