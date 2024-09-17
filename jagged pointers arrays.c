#include <stdio.h>
#include <stdlib.h>

int main() {
    void* x;

    void* arr1 = malloc(sizeof(void*)*4);
    void* arr2 = malloc(sizeof(void*)*2);
    void* arr3 = malloc(sizeof(void*)*5);
    void* arr4 = malloc(sizeof(void*)*6);
    void* arr5 = malloc(sizeof(void*)*8);

    x = arr1;

    *(int*)arr1 = 3;
    *((int*)arr1+1) = (int*)arr2;
    *((int*)arr1+2) = NULL;
    *((int*)arr1+3) = (int*)arr4; 

    *(int*)arr2 = 1;
    *((int*)arr2+1) = (int*)arr3;

    *(int*)arr3 = 4;
    *((int*)arr3+1) = (int*)arr2;
    *((int*)arr3+2) = NULL;
    *((int*)arr3+3) = (int*)arr4;
    *((int*)arr3+4) = (int*)arr5;

    *(int*)arr4 = 5;
    *((int*)arr4+1) = *((int*)arr4+2) =*((int*)arr4+3)= NULL;
    *((int*)arr4+4) = (int*)arr5;

    *(int*)arr5 = 7;
    *((int*)arr5+1) = *((int*)arr5+2) = *((int*)arr5+3) = *((int*)arr5+4) = *((int*)arr5+5) = *((int*)arr5+6) = NULL;
    *((int*)arr5+7) = (int*)arr2;

    printf("%d\n", *(int*)x);
    printf("%d\n", *(int*)*((int*)x+1));
    printf("%d\n", *(int*)*((int*)*((int*)x+1)+1));
    printf("%d\n", *(int*)*((int*)*((int*)*((int*)x+1)+1)+3));
    printf("%d\n", *(int*)*((int*)*((int*)*((int*)*((int*)x+1)+1)+3)+4));

    /*
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
    */
   
}