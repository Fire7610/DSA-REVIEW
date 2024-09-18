#include <stdio.h>
#include <stdlib.h>

int main() {
    void* x;

    void** arr1 = malloc(sizeof(void*)*4);
    void** arr2 = malloc(sizeof(void*)*2);
    void** arr3 = malloc(sizeof(void*)*5);
    void** arr4 = malloc(sizeof(void*)*6);
    void** arr5 = malloc(sizeof(void*)*8);

    x = arr1;

    *(int*)arr1 = 3;
    (arr1[1]) = arr2;
    (arr1[2]) = NULL;
    (arr1[3]) = (int*)arr4; 

    *(int*)arr2 = 1;
    *(arr2+1) = (int*)arr3;

    *(int*)arr3 = 4;
    *(arr3+1) = (int*)arr2;
    *(arr3+2) = NULL;
    *(arr3+3) = (int*)arr4;
    *(arr3+4) = (int*)arr5;

    *(int*)arr4 = 5;
    *(arr4+1) = *(arr4+2) =*(arr4+3) = NULL;
    *(arr4+4) = (int*)arr5;

    *(int*)arr5 = 7;
    *(arr5+1) = *(arr5+2) = *(arr5+3) = *(arr5+4) = *(arr5+5) = *(arr5+6) = NULL;
    *(arr5+7) = (int*)arr2;

    printf("%d\n", ((int*)x)[0]);
    printf("%d\n", (int*)((void**)((void**)x)[1])[0]);
    printf("%d\n", *(int*)((void**)((void**)((void**)x)[1])[1]));
    printf("%d\n", (int*)((void**)((void**)((void**)((void**)x)[1])[1])[3])[0]);
    printf("%d\n", (int*)((void**)((void**)((void**)((void**)((void**)x)[1])[1])[3])[4])[0]);
    //printf("%d\n", *(int*)*((int*)x+1));
    //printf("%d\n", *(int*)*((int*)*((int*)x+1)+1));
    //printf("%d\n", *(int*)*((int*)*((int*)*((int*)x+1)+1)+3));
    //printf("%d\n", *(int*)*((int*)*((int*)*((int*)*((int*)x+1)+1)+3)+4));


}