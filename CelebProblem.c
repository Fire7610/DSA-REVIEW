#include <stdio.h>
#include <string.h>

int main(){

    int M[4][4] = {{0,0,1,0},
                {0,0,1,0},
                {0,1,0,0},
                {0,0,1,0}};
    
    int ctr = 0, tempi = 0, tempj =0;
    for(int i = 0; i < 4;i++){
        for (int j = 0; j < 4; j++){
            if(M[i][j] == 1 && j == tempj){
                ctr++;
                tempj = j;
            }             
            if(ctr == 0) {
                if(M[i][j] == 1){
                ctr++;
                tempj = j;
                }
            }
            if() 

            if(ctr == 3){
                printf("Celebrity is %d", j);
                break;
            }
            if (ctr != 3){ 
                printf("No Celebrity");
                break;
            }
        }

    }

}