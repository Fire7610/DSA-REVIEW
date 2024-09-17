#include <stdio.h>

int main(){
    int i;
    scanf("%d", &i);

    if((i)%2 == 0 && (i-2)>0)
        printf("YES");
    else
        printf("NO");
}