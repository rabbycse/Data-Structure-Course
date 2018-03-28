#include<stdio.h>

int merge(int arr[],int p,int q,int r);
int merge_sort(int arr[],int p,int r);

int main()
{
  int n,i,arr[20];

  printf("Enter the size of array:");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(i=0; i<n; i++)
  {
    scanf("%d",&arr[i]);
  }
  merge_sort(arr,0,n-1);
  printf("Sorted array:");
  for(i=0; i<n; i++)
  {
    printf(" %d",  arr[i]);
  }
  return 0;
}

int merge_sort(int arr[],int p,int r)
{
  int q;
  if(p<r)
  {
    q=(p+r)/2;
    merge_sort(arr,p,q);
    merge_sort(arr,q+1,r);
    merge(arr,p,q,r);
   }
  return 0;
}

int merge(int arr[],int p,int q,int r)
{
  int L[10],R[10];
  int n1,n2,i,j,k;

  n1=q-p+1;
  n2=r-q;

  for(i=0; i<n1; i++)
  {
    L[i]=arr[p+i];
  }
  for(j=0; j<n2; j++)
  {
    R[j]=arr[q+j+1];
  }

  L[i]=9999;
  R[j]=9999;

  i=0;
  j=0;

  for(k=p; k<=r; k++)
    {
    if(L[i]<=R[j])
    {
      arr[k]=L[i++];
    }
    else
    {
      arr[k]=R[j++];
    }

    }
    return 0;
}

