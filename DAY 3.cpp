#include <stdio.h>
int main() {
    int n, k, comparisons = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    int found = 0;
    for(int i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    return 0;
}

