#include <stdio.h>
#include <string.h>

void print(char **arr, int tc){
    for (int i = 0; i<tc; i++){
        for (int j = 0; j<100; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
}

int main(){
    int tc;
    scanf("%d", &tc);

    char arr[tc][100];

    for (int j = 0; j <tc ;j++)
        arr[j][0] = '0';

    for(int i = 0; i<tc; i++)
        scanf(" %s", &arr[i]);

    for (int k = 0; k<tc; k++){
        int ctr[5]= {0};
        for (int j = 0; j<strlen(arr[k]); j++){
            if(arr[k][j] == 'a'){
                ctr[0]++;
            }
            if(arr[k][j] == 'e'){
                ctr[1]++;
            }
            if(arr[k][j] == 'i'){
                ctr[2]++;
            }
            if(arr[k][j] == 'o'){
                ctr[3]++;
            }
            if(arr[k][j] == 'u'){
                ctr[4]++;
            }
        }
        int h=0;
        for (int j = 0;j<5;j++){
            if(ctr[j] > h )
                h=ctr[j];
        }

        for(int j = 0; j<5;j++){
            if(ctr[j] == h&& j == 0)
                printf("a ");
            if(ctr[j] == h && j == 1)
                printf("e ");
            if(ctr[j]==h &&j ==2)
                printf("i ");
            if (ctr[j] == h && j ==3)
                printf("o ");
            if(ctr[j] == h && j == 4)
                printf("u ");
        }
        printf("\n");
    }
}