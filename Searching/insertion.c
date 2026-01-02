#include <stdio.h>

int main()
{
    int a[50], n,i,j;
    printf("enter your size of array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("you entered this array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i=1; i<n; i++)
    {
        int temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("sorted array is :\n");
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
}