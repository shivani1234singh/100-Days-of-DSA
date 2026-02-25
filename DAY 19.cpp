#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = arr[0] + arr[1];
    int x = arr[0], y = arr[1];

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}
