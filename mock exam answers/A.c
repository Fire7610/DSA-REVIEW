#include <stdio.h>
#include <stdlib.h>

int compare(const void *arrA, const void *arrB){
    float fa = *(const float*)arrA;
    float fb = *(const float*)arrB;

    return fa-fb;
}

int main(){
    int tc;    
    scanf("%d", &tc);
    float arr[tc];
    int arrS= sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < tc; i++){
        scanf(" %f", &arr[i]);
    }

    qsort(arr,arrS,sizeof(float),compare);

    if(tc%2 == 1 ){
        printf("%.1lf", arr[tc/2]);
    } else {
        printf("%.1lf", (arr[tc/2]+arr[(tc/2)-1])/2);
    }

}