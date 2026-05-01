#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, sum = 0;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum of elements = %d\n", sum);
    free(arr);
    return 0;
}
