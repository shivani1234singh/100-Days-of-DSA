#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char names[n][101];
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    qsort(names, n, sizeof(names[0]), cmp);

    int maxCount = 1, count = 1;
    char result[101];
    strcpy(result, names[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                strcpy(result, names[i - 1]);
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        strcpy(result, names[n - 1]);
    }

    printf("%s %d", result, maxCount);
    return 0;
}
