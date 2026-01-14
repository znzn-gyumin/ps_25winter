#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main() {
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);
    getchar();

    int **matrix_one = (int**)malloc(m * sizeof(int*));
    int **matrix_two = (int**)malloc(m * sizeof(int*));
    int **matrix_res = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++) matrix_one[i] = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < m; i++) matrix_two[i] = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < m; i++) matrix_res[i] = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < m; i++) {
        char string[MAX_LENGTH] = "\0"; 
        fgets(string, MAX_LENGTH, stdin);
        char *ptr = strtok(string, " \n");

        int j = 0;
        while (ptr != NULL) {
            matrix_one[i][j] = atoi(ptr);
            ptr = strtok(NULL, " \n");
            j++;
        }
    }
    for (int i = 0; i < m; i++) {
        char string[MAX_LENGTH] = "\0"; 
        fgets(string, MAX_LENGTH, stdin);
        char *ptr = strtok(string, " \n"); 

        int j = 0;
        while (ptr != NULL) {
            matrix_two[i][j] = atoi(ptr);
            ptr = strtok(NULL, " \n");
            j++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix_res[i][j] = matrix_one[i][j] + matrix_two[i][j];
            printf("%d ", matrix_res[i][j]);
        }
        printf("\n");
    }

    free(matrix_one);
    free(matrix_two);
    free(matrix_res);

    return 0;
}