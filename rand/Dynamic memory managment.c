#include <stdio.h>

int main()  {
    char data1 ='X';
    int data2 = 100;
    float data3 = 3.14;

    void *ptr1 = &data3;
    printf("%.2lf\n", *((float*)ptr1));

}