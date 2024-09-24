#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *output = (int*)malloc(sizeof(int)*2);
    for(int i = 0; i<numsSize;i++){
        for(int j = i+1; j <numsSize; j++){
            if(nums[i]+nums[j]==target){
                output[0]=i;
                output[1]=j;
                *returnSize = 2;
                return output;
            }
        }
    }
    *returnSize = 0;
    return output;
}

int main(){
    int nums[4] = {2,7,11,15};
    int target = 9;
    int returnSize;
    int* output = twoSum(nums, 4, target, &returnSize);
    for(int i = 0; i<returnSize; i++){
        printf("%d ", output[i]);
    }

    return 1;
}