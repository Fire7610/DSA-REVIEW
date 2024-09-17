#include <stdio.h>

int main()
{
    int brothers[3] = {3, 1, 2};
    int input[2];
    scanf("%d", &input[0]);
    while(1){
        scanf("%d", &input[1]);
        if(input[1] != input[0])
            break;
        printf("Please enter a different number\n");
    }
    printf("%d", 6-input[0]-input[1]);

    return 0;
}