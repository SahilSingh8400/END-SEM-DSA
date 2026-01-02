#include <stdio.h>

int main()
{
    int a[50], n, key, i;
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

    printf("\nenter value to find\n");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("the value is found at index %d",i+1);
            return 0;
        }
    }
}