#include <stdio.h>
#include <stdlib.h>

int main(){
    int i1[3]={8,2,3}, i2[3] = {1,3,4};
    double f1=8.21,f2[3] = {1.2,3.1,4.2};
    char arr1[5] = {'r','h','u','e','l'};   

    void *A,*B,*C,*G,*H,*I;
    char *D;
    double *E;
    int *F;

    A = &B;
    B = &D;
    D = arr1;
    for (int i = 0; i < 5; i++)
        printf("%c",*(**(char ***)A+i)); // rhuel
    printf("\n");

    A = &B;
    B = &E;
    E = f2;
    for (int i = 0; i < 3; i++)
        printf("%.1lf ",*(**(double ***)A+i)); // 1.2 3.1 4.2
    printf("\n");

    A = &C;
    C = &E;
    E = &f1;
    printf("%.2lf\n",***(double ***)A); // 8.21

    A = &C;
    C = &F;
    F = i1;
    for(int i = 0; i < 3; i++)
        printf("%d ",*(**(int ***)A+i)); // 8 2 3

    


    return 0;
}