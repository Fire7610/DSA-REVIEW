#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* decOct(int i) {
    int octalNum = 0, placeValue = 1;

    while (i != 0) {
        octalNum += (i % 8) * placeValue;
        i /= 8;
        placeValue *= 10;
    }
    int* output = &octalNum;
    return output;
}

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

char* reverse(char* s){
    int len = strlen(s);
    char *out = (char*) malloc(sizeof(char) * (len + 1));
    int index = 0;
    for (int i = len - 1; i >= 0; i--)
        out[index++] = s[i];
    return out;
}

void pali(int left, int right, int len, char* s, int* start, int* max) {
    while ((left >= 0 && right < len) && (s[left] == s[right])) {
        int a = right - left + 1;
        if (*max < a) {
            *start = left;
            *max = a;
        }
        left--;
        right++;
    }
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    int start = 0;
    int max = 1;

    for (int i = 0; i < len; i++) {
        pali(i, i, len, s, &start, &max);      
        pali(i, i + 1, len, s, &start, &max);   
    }
    char* c = (char*)malloc((max + 1) * sizeof(char));
        if (c == NULL) {
            return NULL;  
        }

    int j = 0;
    for (int i = start; i < max + start; i++) {
        c[j] = s[i];
        j++;
    }
    c[j] = '\0';
    return c;
}

int rev(int i){
    int out=0;
    while(i > 0){
        out = (out*10)+(i%10);
        i = i/10;
    }
    return out;
}

bool isPalindrome(int x) {
    if(x<10&&x>0)
        return true;
    if(x<0)
        return false;
    if(x != rev(x))
        return true;
    return false;
}

int main()
{
    int x = 10;
    printf("%d\n", rev(123));
}