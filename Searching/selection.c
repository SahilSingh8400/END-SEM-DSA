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

    for (i=0; i<n; i++){
        int min=i;
        for (j=i+1; j<n; j++){
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i){    // for setting the min value to 0th place
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
        printf("sorted array is :\n");
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
}