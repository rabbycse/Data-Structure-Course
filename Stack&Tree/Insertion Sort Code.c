#include<stdio.h>
int main()
{
    int a[10]={5,4,1,2,3,10,6,9,8,7};
    int j,i,key;
    for(j=0;j<10;j++)
    {
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]>=key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
    for(j=0;j<10;j++)
    {
        printf("%d ",a[j]);
    }
    return 0;
}
