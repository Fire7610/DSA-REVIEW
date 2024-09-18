#include <stdio.h>

int main()  {
    int rows = 2, cols = 2;

    int** matrix;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    
}