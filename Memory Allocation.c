#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // stack memory are the 
    //place where all lical variables are stored
    //heap memory is the place where all the dynamic memory allocation is done
    //pointer is a variable that stores the address of another variable
    
    int x = 10; // stack memory
    int *p = (int*)malloc(sizeof(int)); // heap memory
    // as seen pointer p stores the address of the memory allocated in the heap memory using malloc

    //key things to remember about pointers
    int *p1;
    p1 = &x; // p1 stores the address of x
    printf("Address of x: %p\n", &x);
    printf("Address of x stored in p1: %p\n", p1);
    printf("Value of x: %d\n", x);
    printf("Value of x accessed through p1: %d\n", *p1); // *p1 is the value stored at the address stored in p1
    printf("Address of p1: %p\n", &p1);

}