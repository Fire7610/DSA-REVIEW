#include <stdio.h>

int main(){
    char arr[32] = {0};
    int dec;

    scanf("%d", &dec);
    /*
    for(int i = 1; dec>0; i*=10){
        bin += (dec%2)*i;
        dec /= 2;
    }
    printf("%llu", bin);
*/
    char out[32];
    
    int index = 0;
    for (int i = 31; dec>0;i--){
        arr[i] = dec%2;
        dec/=2;
        index++;
    }

    for(int i = 32-index; i<32; i++){
        printf("%d",arr[i]);
    }

    
}