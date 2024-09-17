#include <stdio.h>
#include <stdlib.h>

// Function to generate the hint map based on the sample map
int** generateHintMap(int** sample, int s){
    // Allocate memory for the hint map
    int** hintMap = (int**)malloc(s * sizeof(int*));
    for (int i = 0; i < s; i++){
        hintMap[i] = (int*)malloc(s * sizeof(int));
        // Initialize all elements of the hint map to 0
        for(int j = 0; j < s; j++){
            hintMap[i][j] = 0;
        }
    }

    // Traverse the sample map
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            // If a mine is found in the sample map
            if (sample[i][j] == 1){
                // Set the corresponding cell in the hint map to -1
                hintMap[i][j] = -1;

                // Update the neighboring cells in the hint map
                if (i - 1 >= 0 && j - 1 >= 0 && sample[i - 1][j - 1] != 1){
                    hintMap[i - 1][j - 1]++;
                }
                if (i - 1 >= 0 && sample[i - 1][j] != 1){
                    hintMap[i - 1][j]++;
                }
                if (i - 1 >= 0 && j + 1 < s && sample[i - 1][j + 1] != 1){
                    hintMap[i - 1][j + 1]++;
                }
                if (j - 1 >= 0 && sample[i][j - 1] != 1){
                    hintMap[i][j - 1]++;
                }
                if (j + 1 < s && sample[i][j + 1] != 1){
                    hintMap[i][j + 1]++;
                }
                if (i + 1 < s && j - 1 >= 0 && sample[i + 1][j - 1] != 1){
                    hintMap[i + 1][j - 1]++;
                }
                if (i + 1 < s && sample[i + 1][j] != 1){
                    hintMap[i + 1][j]++;
                }
                if (i + 1 < s && j + 1 < s && sample[i + 1][j + 1] != 1){
                    hintMap[i + 1][j + 1]++;
                }
            }
        }
    }
    return hintMap;
}

int main(){
    // Sample map with mines represented by 1 and empty cells represented by 0
    int field[5][5] = { 
            {0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 0, 0} };

    int s = 5;
    int** sample = (int**)malloc(s * sizeof(int*));
    for (int i = 0; i < s; i++){
        sample[i] = (int*)malloc(s * sizeof(int));
        // Copy the elements from the field to the sample map
        for(int j = 0; j < s; j++){
            sample[i][j] = field[i][j];
        }
    }

    // Generate the hint map
    int** ghm = generateHintMap(sample, s);

    // Print the hint map
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            printf("%d ", ghm[i][j]);
        }
        printf("\n");
    }
}