#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char* decToBinary(int n) {
    char* binary = (char*)malloc(33 * sizeof(char));
    if (binary == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    binary[32] = '\0';
    int index = 31;

    if (n == 0) {
        binary[index] = '0';
        return &binary[index];
    }

    while (n > 0) {
        binary[index] = (n % 2) + '0';
        n /= 2;
        index--;
    }

    return &binary[index + 1];
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

char singleNumber(char* nums, int numsSize) {
    char out;
    for(int i = 0; i<numsSize;i++){
        out ^= nums[i];
    }
    return out;
}

int romanToInt(char* s) {
    int size = strlen(s), i = 0, out = 0;

    while(i!=size){
        while(s[i]=='I'){
            i+=1;
            out++;
            if(i==size) break;
            
            if(s[i] == 'V'){
                i++;
                out+=5;
                out--;
                if(i=size) break;
            }
            if(s[i] == 'X'){
                i++;
                out+=10;
                out--;
                if(i=size) break;
            }
        }
    }
    return out;
}

char* decToBinary(int n) {
    char* binary = (char*)malloc(33 * sizeof(char));
    if (binary == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    binary[32] = '\0';
    int index = 31;

    if (n == 0) {
        binary[index] = '0';
        return &binary[index];
    }

    while (n > 0) {
        binary[index] = (n % 2) + '0';
        n /= 2;
        index--;
    }

    return &binary[index + 1];
}

int main()
{
    char testp[]={"III"};
    printf("%d", decOct(7672));
}