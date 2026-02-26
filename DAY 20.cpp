#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;

    for(int start = 0; start < n; start++) {
        int sum = 0;
        for(int end = start; end < n; end++) {
            sum += arr[end];
            if(sum == 0)
                count++;
        }
    }

    printf("%d", count);

    return 0;
}
