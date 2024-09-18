#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    float fa = *(const float*)a;
    float fb = *(const float*)b;

    return fa-fb;
}

int main(){
    int tc;
    scanf("%d", &tc);

    float arr[tc];

    for(int i = 0; i<tc; i++)
        scanf(" %f", &arr[i]);

    qsort(arr,tc,sizeof(float),compare);

    for (int i = 0; i < tc; i++)
        printf("%.1lf ", arr[i]);
}