#include <stdio.h>
#include <string.h>
int main(){
    char s[1000];
    scanf("%999s", s);
    int l = 0, r = strlen(s) - 1;
    while(l < r){
        if(s[l] != s[r]){
            printf("NO");
            return 0;
        }
        l++;
        r--;
    }
    printf("YES");
    return 0;
}
