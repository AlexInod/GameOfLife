#include "Task1.h"
int compara_coordonate(const void *a, const void *b)
{
    Coordonata *c1 = (Coordonata *)a;
    Coordonata *c2 = (Coordonata *)b;
    int c1_col_zero = (c1->c == 0);
    int c2_col_zero = (c2->c == 0);
    if (c1_col_zero && !c2_col_zero)
        return 1;
    if (!c1_col_zero && c2_col_zero)
        return -1;
    if (c1->l != c2->l)
        return c1->l - c2->l;
    return c1->c - c2->c;
}
Generare initiere()
{
    Generare gen;
    gen.capacitate = 10;
    gen.count = 0;
    gen.celule = (Coordonata *)malloc(gen.capacitate * sizeof(Coordonata));
    if (gen.celule == NULL)
    {
        printf("err\n");
        exit(1);
    }
    return gen;
}
void Adauga(Generare *gen, int l, int c)
{
    if (gen->count >= gen->capacitate)
    {
        gen->capacitate *= 2;
        gen->celule = (Coordonata *)realloc(gen->celule, gen->capacitate * sizeof(Coordonata));
        if (gen->celule == NULL)
        {
            printf("err\n");
            exit(1);
        }
    }

    gen->celule[gen->count].l = l;
    gen->celule[gen->count].c = c;
    gen->count++;
}

Generare generatia_urm(char **current, char **next, int n, int m)
{
    Generare gen = initiere();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int neighbors = calc_vecini(current, n, m, i, j);

            if (current[i][j] == 'X')
            {
                if (neighbors < 2 || neighbors > 3)
                    next[i][j] = '+';
                else
                    next[i][j] = 'X';
            }
            else
            {
                if (neighbors == 3)
                    next[i][j] = 'X';
                else
                    next[i][j] = '+';
            }

            if (current[i][j] != next[i][j])
            {
                Adauga(&gen, i, j);
            }
        }
    }
    qsort(gen.celule, gen.count, sizeof(Coordonata), compara_coordonate);

    return gen;
}
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
        printf("err");
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
        } // 1
    elibereaza_memorie(tmp, n);
}

void scrierez(char **mat, int n, char *output_file)
{
    FILE *f = fopen(output_file, "a");
    if (!f)
    {
        printf("err\n");
        exit(1);
    }
    if (!f)
    {
        printf("err\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        fprintf(f, "%s\n", mat[i]);
    fprintf(f, "\n");
    fclose(f);
}
void scriererez2(Generare *generari, int k, char *output_file)
{
    FILE *f = fopen(output_file, "w");
    if (!f)
    {
        printf("err\n");
        exit(1);
    }

    for (int i = 0; i < k; i++)
    {
        fprintf(f, "%d ", i + 1);

        for (int j = 0; j < generari[i].count; j++)
        {
            fprintf(f, "%d %d", generari[i].celule[j].l, generari[i].celule[j].c);
            if (j < generari[i].count - 1)
                fprintf(f, " ");
        }
        fprintf(f, "\n");
    }

    fclose(f);
}