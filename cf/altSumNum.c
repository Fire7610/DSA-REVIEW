#include <stdio.h>

int altSum(int a[],int s){
    int sum = 0;
    for(int i = 1; i < s+1;i++){
        if(i%2!=0){
            sum += a[i-1];
        } else{
            sum-=a[i-1];
        } 
    }
    return sum;
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int k[n];
        for(int j = 0; j<n; j++){
            scanf("%d", &k[j]);
        }
        printf("%d\n", altSum(k,n));

    }

}