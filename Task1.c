#include "Task1.h"
int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    int N, M, T, K;
    char **mat;
    mat = citire_fisier(argv[1], &N, &M, &T, &K);
    if (T == 1)
    {
        FILE *f = fopen(argv[2], "w");
        fclose(f);
        scrierez(mat, N, argv[2]);
        for (int i = 0; i < K; i++)
        {
            reguli(mat, N, M);
            scrierez(mat, N, argv[2]);
        }
        elibereaza_memorie(mat, N);
        return 0;
    }
    else if (T == 2)
    {
        Generare *generari;
        char **mat2;
        mat2 = aloca_matrice(N, M);
        generari = (Generare *)malloc(K * sizeof(Generare));
        if (generari == NULL)
        {
            printf("err\n");
            return 1;
        }
        for (int i = 0; i < K; i++)
        {
            generari[i] = generatia_urm(mat, mat2, N, M);
            char **temp = mat;
            mat = mat2;
            mat2 = temp;
        }
        scriererez2(generari, K, argv[2]);
        for (int i = 0; i < K; i++)
        {
            free(generari[i].celule);
        }
        free(generari);
        elibereaza_memorie(mat, N);
        elibereaza_memorie(mat2, N);
        //
        return 0;
    }
}