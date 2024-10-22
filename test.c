#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

// Function to check if two frequency arrays are the same
bool matches(int count1[], int count2[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

// Function to check if s2 contains any permutation of s1
bool checkInclusion(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len1 > len2) {
        return false;
    }

    // Frequency arrays for s1 and the current window in s2
    int count_s1[ALPHABET_SIZE] = {0};
    int count_window[ALPHABET_SIZE] = {0};

    // Initialize the frequency arrays with the first 'len1' characters
    for (int i = 0; i < len1; i++) {
        count_s1[s1[i] - 'a']++;
        count_window[s2[i] - 'a']++;
    }

    // Use the sliding window technique to compare frequencies
    for (int i = 0; i <= len2 - len1; i++) {
        // If the current window matches s1's frequencies, return true
        if (matches(count_s1, count_window)) {
            return true;
        }

        // Slide the window: Remove the character going out of the window
        if (i + len1 < len2) {
            count_window[s2[i] - 'a']--;                // Remove the leftmost character
            count_window[s2[i + len1] - 'a']++;         // Add the next character into the window
        }
    }

    // If no permutation is found, return false
    return false;
}

int addDigits(int num) {
    while(num > 10){
        int temp = 0;
        for(int i = num; i>0;i/=10){
            temp+= i%10;
        }
        num = temp; 
    }
    return num;
}

int main() {
    int test = 38;
    printf("%d",addDigits(test));

}