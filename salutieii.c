#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **alloc_matrix(int n, int m) {
    char **mat;
    mat = (char **)malloc(n * sizeof(char *));
    if (mat == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        mat[i] = (char *)malloc((m + 1) * sizeof(char));
        if (mat[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        // Initialize with null terminator
        mat[i][0] = '\0';
    }
    return mat;
}

void elib_mem(char **mat, int n) {
    int i;
    for (i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

char **citire_fisier(const char *file, int *n, int *m, int *k) {
    FILE *f = fopen(file, "r");
    if (!f) {
        printf("eroare fisier\n");
        exit(1);
    }
    
    int test_number;
    fscanf(f, "%d", &test_number);  // Read test number (e.g., "1")
    fscanf(f, "%d %d", n, m);       // Read dimensions (e.g., "6 6")
    fscanf(f, "%d", k);             // Read iterations (e.g., "2")
    
    char **mat = alloc_matrix(*n, *m);
    
    // Read the grid
    for (int i = 0; i < *n; i++) {
        // Add maximum field width to prevent buffer overflow
        fscanf(f, "%99s", mat[i]);
    }
    
    fclose(f);
    return mat;
}

int calc_vecini(char **mat, int n, int m, int x, int y) {
    int cnt = 0, dx, dy;
    for (dx = -1; dx <= 1; dx++)
        for (dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0)
                continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 'X')
                cnt++;
        }
    return cnt;
}

void replia_joc(char **mat, int n, int m) {
    char **tmp = alloc_matrix(n, m);
    int i, j, v;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            v = calc_vecini(mat, n, m, i, j);
            if (mat[i][j] == 'X') {
                if (v < 2 || v > 3)
                    tmp[i][j] = '+';  // Dead cell uses '+'
                else
                    tmp[i][j] = 'X';
            }
            else {
                if (v == 3)
                    tmp[i][j] = 'X';
                else
                    tmp[i][j] = '+';  // Dead cell uses '+'
            }
        }
        // Ensure null termination
        tmp[i][m] = '\0';
    }
    for (i = 0; i < n; i++)
        strcpy(mat[i], tmp[i]);
    elib_mem(tmp, n);
}

void scriere_rezultat(char **mat, int n, int m, const char *output_file) {
    FILE *f = fopen(output_file, "w");
    if (!f) {
        printf("eroare scriere fisier\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s\n", mat[i]);
    }
    
    fclose(f);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Format: %s input.txt output.txt\n", argv[0]);
        return 1;
    }
    
    int N, M, K;
    char **mat;
    
    // Read input
    mat = citire_fisier(argv[1], &N, &M, &K);
    
    // Run Game of Life iterations
    for (int i = 0; i < K; i++) {
        replia_joc(mat, N, M);
    }
    
    // Write output to a single file
    scriere_rezultat(mat, N, M, argv[2]);
    
    // Free memory
    elib_mem(mat, N);
    
    return 0;
}