#include <stdio.h>

void mergeSort(int arr[],int , int );
void merge(int arr[],int , int , int );

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
  mergeSort(arr,0,n-1);
  printf("Sorted array:");
  for(i=0; i<n; i++)
  {
    printf(" %d",  arr[i]);
  }
  return 0;
}

void mergeSort(int arr[],int start, int end)
{
   int mid;

   if(start < end)
    {
      mid = (start + end) / 2;
      mergeSort(arr,start, mid);
      mergeSort(arr,mid+1, end);
      merge(arr,start, mid, end);
    }
}

void merge(int arr[],int start, int mid, int end)
{
   int i, j, k,index=0,temp[20];

   i=start;
   j=mid+1;

   while(i<=mid && j<=end)
   {
      if(arr[i] <= arr[j])
      {
         temp[index++] = arr[i++];
      }
      else
      {
         temp[index++] = arr[j++];
      }
    }

   while(i <= mid)
   {
      temp[index++] = arr[i++];
   }

   while(j <= end)
   {
      temp[index++] = arr[j++];
   }

   for(i = start, k=0;i <= end; i++)
   {
      arr[i] = temp[k++];
   }
}

