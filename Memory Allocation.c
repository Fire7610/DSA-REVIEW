#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // stack memory are the 
    //place where all lical variables are stored
    //heap memory is the place where all the dynamic memory allocation is done
    //pointer is a variable that stores the address of another variable
    
    //int x = 10; // stack memory
    //int *p = (int*)malloc(sizeof(int)); // heap memory
    // as seen pointer p stores the address of the memory allocated in the heap memory using malloc

    //key things to remember about pointers
    //int *p1;
    //p1 = &x; // p1 stores the address of x
    //printf("Address of x: %p\n", &x);
   // printf("Address of x stored in p1: %p\n", p1);
   // printf("Value of x: %d\n", x);
    //printf("Value of x accessed through p1: %d\n", *p1); // *p1 is the value stored at the address stored in p1
    //printf("Address of p1: %p\n", &p1);

    // malloc function is used to allocate memort on the heap
    // malloc returns a void pointer
    // void pointer is a pointer that can point to any data type

    /*
    // learning task
    int x = 10;
    int *p;
    p = &x;

    *p = 5; // this changes the value of the variable being pointed by p
    
    float *pi = (float*)malloc(sizeof(float));
    *pi = 3.14f;
    p = pi;

    float *p_ptr = p;

    printf("Value of x: %.2lf\n", *p_ptr);

    */
   /*
   //learning task 2

   int a;
   int *p;
   int **q;

   a = 14;
   p = &a;
   q = &p;

    printf("Value of a: %d\n", a);
    printf("Value of a accessed through p: %d\n", *p);
    printf("Value of a accessed through q: %d\n", **q);
    printf("%p\n", p);
    printf("%p\n", q);

    */
   /*
   int a = 23;
    
    int* p = &a;

    int** q = &p;
    int** r = &p;

    int*** s = &q;
    int*** t = &q;
    int*** u = &r;
    int*** v = &r;

    printf("%d\n", ***v);
    printf("%d\n", ***u);
    printf("%d\n", ***t);
    printf("%d\n\n", ***s);

    printf("%d\n", **q);
    printf("%d\n\n", **r);

    printf("%d\n", *p);
    */
}