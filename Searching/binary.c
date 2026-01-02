#include <stdio.h>

int main() {
    int a[50], n, key, low = 0, high, mid, i;

    printf("Enter size: ");
    scanf("%d", &n);
    high = n - 1;

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key) {
            printf("Found at position %d", mid+1);
            return 0;
        }
        else if(key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("Not Found");
    return 0;
}
