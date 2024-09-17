#include <stdio.h>
#include <math.h>
int main(){
    float input[15] = {8.533, 3.019, -8.827, 3.543, -9.069, 0.301, -7.498, 0.229, -1.740, 7.905, -4.356, 8.767, -8.704, -4.770, 7.212};
    for(int i = 0; i<15; i++){
        for (int j=0;j<15;j++){
            float temp3=0;
            if (fabs(input[i]) < fabs(input[j])){
                 temp3 = input[i];
                 input[i] = input[j];
                 input[j] = temp3;
             }
        }
    }

    for(int i = 0; i<15; i++){
        printf("%.3lf ", input[i]);
    }

    
}