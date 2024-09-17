#include <stdio.h>
#include <string.h>


int main(){
    int M[4][4] = {{0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0}};
int temp = 1;
if(temp){
    for(int i = 0; i < 4;i++)// eval if person 2-4 is the celeb
    {
        if(M[0][i] == 1)
        {
            for(int j = 0; j<4; j++)
            {
                if(M[j][i] == 0)
                {
                    int ctr = 0;
                    for(int k = 0; k<4; k++)
                    {
                        if(M[j][k] == 1)
                        {
                            printf("no celeb");
                            return 1;
                        }
                        ctr++;
                        if(ctr==4)
                        {
                            printf("%d", i);
                            return 1;
                        }
                    }
                }
                if(j == 3){
                    printf("no celeb");
                    return 1;
                }
                
            }
        }
    }
    for(int j = 0; j<4;j++)// eval if person 1 is the celeb
    {
        if(M[1][j]==1)
        {
            for (int k = 1; k<4; k++)
            {
               if(M[k][j]==0)
                {
                    printf("no celeb");
                    return 1;
                }
                if(k == 3)
                {
                    printf("%d", j);
                   return 1;
                }
            }
        }
    }
   printf("all are celeb???");
   return 1; 
}
}