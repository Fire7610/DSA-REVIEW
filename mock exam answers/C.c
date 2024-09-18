#include <stdio.h>

int main(){
    int tc;
    scanf("%d", &tc);

    char arr[tc];
    for (size_t i = 0; i < tc; i++)
        scanf(" %c", &arr[i]);
    
    for(int i = 0; i<tc; i++){
        if (arr[i]-3 < 65)
            printf("%c ", (arr[i]-3)+26);
        else 
            printf("%c ", arr[i]-3);
    }
}