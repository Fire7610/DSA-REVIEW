#include <stdio.h>

void eval(char in[][4], int s){
    for (int j = s; j>0 ;j--){
        for (int  k = 4; k>0;k--){
            if(in[j-1][k-1] == '#')
                printf("%d ", k);
        }
    }
    printf("");
    
}

int main(){
    int test;
    scanf("%d", &test);

    for(int i = 0; i < test; i++){
        int rows;
        scanf("%d", &rows);
        char input[rows][4];
        printf("");
        for (int j = 0; j<rows ;j++){
            for (int k = 0; k<4;k++ ){
                scanf(" %c", &input[j][k]);
            }
        }
        eval(input,rows);
    }
    

}