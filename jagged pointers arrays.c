#include <stdio.h>
#include <stdlib.h>

int main() {

    void***** x = malloc(sizeof(void*)*4);

    x[0] = (void****)3;
    x[1] =  malloc(sizeof(void*)*2);
    x[2] = NULL;
    x[3] = malloc(sizeof(void*)*6);

    x[1][0] = (void***)1;
    x[1][1] = malloc(sizeof(void*)*5);

    x[1][1][0] = (void**)4;
    x[1][1][1] = (void**)x[1];
    x[1][1][2] = NULL;
    x[1][1][3] = (void**)x[3];
    x[1][1][4] = malloc(sizeof(void*)*8);
    
    x[1][1][4][0] = (void*)7;
    x[1][1][4][1] = NULL;
    x[1][1][4][2] = NULL;
    x[1][1][4][3] = NULL;
    x[1][1][4][4] = NULL;
    x[1][1][4][5] = NULL;
    x[1][1][4][6] = NULL;
    x[1][1][4][7] = (void*)x[1][1];

    x[3][0] = (void***)5;
    x[3][1] = NULL;
    x[3][2] = NULL;
    x[3][3] = (void***)x[1][1][4];

    


      




    printf("%d\n", (int*)x[0]);
    printf("%d\n", (int*)x[1][0]);
    printf("%d\n", (int*)x[3][0]);
    printf("%d\n", (int*)x[1][1][4][0]);

    
    

    
    



}