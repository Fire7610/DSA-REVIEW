#include <stdio.h>
#include <stdlib.h>

int main(){
    int i1[3]={8,2,3}, i2[3] = {1,3,4};
    double f1=8.21,f2[3] = {1.2,3.1,4.2};
    char arr1[5] = {'r','h','u','e','t'};
    
    void** A = malloc(sizeof(void*)*2);
    void** B = malloc(sizeof(void*)*2);
    void** C = malloc(sizeof(void*)*2);
    void** G = malloc(sizeof(void*)*2);
    void* D;
    void* E;
    void* F;
    void* H;
    void* I;

    A[0]=B;
    A[1]=C;

    B[0]=D;
    B[1]=E;


    C[0]=E;
    C[1]=F;

    D=arr1; 

    E=&f1;

    F=i1;

    G[0] = &H;
    G[1] = &I;
    
    H=i2;

    I=f2;

}