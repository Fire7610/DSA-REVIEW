#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
char* reverse(char* s){
    int len = strlen(s);
    char *out = (char*) malloc(sizeof(char) * (len + 1));
    int index = 0;

    for (int i = len - 1; i >= 0; i--)
        out[index++] = s[i];
    out[index] = '\0';
    return out;
}

char* copy(char* s, int i, int j){
    int length = j-i;
    char* out = (char*)malloc(sizeof(char)*length+1);
    
    for(int a = 0; a<length; a++){
        out[a] = s[i+a];
    }
    out[length] = '\0';

    return out;
}

char* longestPalindrome(char* s) {
    if(strlen(s) == 1){
        return s;
    }
    
    char *output;
    int ml = 0;

    for(int i = 0; i<strlen(s);i++){
        for(int j = i+1; j<strlen(s)+1; j++){
            char* temp = copy(s,i,j);
            char* rev = reverse(temp);
            if(strcmp(temp,rev) == 0&& (j-i)>ml){
                ml = j-i;
                output = temp;
            }else{
                free(temp);
            }
            free(rev);
        }
    }
    return output;
}
*/

void palindrome(int left, int right, int len, char* s, int* start, int* max) {
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
        palindrome(i, i, len, s, &start, &max);      
        palindrome(i, i + 1, len, s, &start, &max);   
    }
    char* c = (char*)malloc((max + 1) * sizeof(char));

    int j = 0;
    for (int i = start; i < max + start; i++) {
        c[j] = s[i];
        j++;
    }
    c[j] = '\0';
    return c;
}

int main()
{
    char s[100000] = "babad";
    char* output = longestPalindrome(s);
    printf("%s", output);
    return 1;
}