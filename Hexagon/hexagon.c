// RAndom hexagon mattrix with n numbers in each side
//all numbers in the hexagon are random
//25% of the numbers are 2 digit (10-99)
//75% of the numbers are 3 digit (100-999)
//make n=100, and save the numbers in a TXT file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_hexagon_matrix(int n, const char* hexmat) {
    FILE* file = fopen(hexmat, "w");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    srand((unsigned int)time(NULL));

    int total_rows = 2 * n - 1;

    for (int row = 0; row < total_rows; row++) {

        int cols = (row < n)
            ? n + row
            : n + (total_rows - row - 1);

        for (int j = 0; j < cols; j++) {
            int num = (rand() % 4 == 0)
                ? rand() % 90 + 10      
                : rand() % 900 + 100;   

            fprintf(file, "%d ", num);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}




