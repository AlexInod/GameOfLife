#include "Task1.h"
char **aloca_matrice(int n, int m)
{
    char **mat;
    mat = (char **)malloc(n * sizeof(char *));
    if (mat == NULL)
        exit(1);

    for (int i = 0; i < n; i++)
    {
        mat[i] = (char *)malloc((m + 1) * sizeof(char));
        if (mat[i] == NULL)
            exit(1);
    }
    return mat;
}

void elibereaza_memorie(char **mat, int n)
{
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

char **citire_fisier(char *fisier, int *n, int *m, int *t, int *k)
{
    FILE *f = fopen(fisier, "r");
    if (!f)
    {
        printf("error");
        exit(1);
    }
    fscanf(f, "%d%d%d%d", t, n, m, k);
    char **mat = aloca_matrice(*n, *m);
    for (int i = 0; i < *n; i++)
        fscanf(f, "%s", mat[i]);
    fclose(f);
    return mat;
}

int calc_vecini(char **mat, int n, int m, int x, int y)
{
    int cnt = 0, lin, col;
    for (lin = -1; lin <= 1; lin++)
        for (col = -1; col <= 1; col++)
        {
            if (lin == 0 && col == 0)
                continue;
            int nlin = x + lin, ncol = y + col;
            if (nlin >= 0 && nlin < n && ncol >= 0 && ncol < m && mat[nlin][ncol] == 'X')
                cnt++;
        }
    return cnt;
}

void reguli(char **mat, int n, int m)
{
    char **tmp = aloca_matrice(n, m);
    int v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            v = calc_vecini(mat, n, m, i, j);
            if (mat[i][j] == 'X')
            {
                if (v < 2 || v > 3)
                    tmp[i][j] = '+';
                else
                    tmp[i][j] = 'X';
            }
            else
            {
                if (v == 3)
                    tmp[i][j] = 'X';
                else
                    tmp[i][j] = '+';
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = tmp[i][j];
        }//1
    elibereaza_memorie(tmp, n);
}

void scrierez(char **mat, int n, char *dir, int index)
{
    char nume[100];
    index += 1;
    sprintf(nume, "%s/data%d.out", dir, index);
    FILE *f = fopen(nume, "w");
    if (!f)
    {
        printf("err");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        fprintf(f, "%s\n", mat[i]);
    fclose(f);
}