#include "Task1.h"
int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;//11
    int N, M, T, K;
    char **mat;
    mat = citire_fisier(argv[1], &N, &M, &T, &K);
    scrierez(mat, N, argv[2], 0);
    for (int i = 0; i < K; i++)
    {
        reguli(mat, N, M);
        scrierez(mat, N, argv[2], i + 1);
    }
    elibereaza_memorie(mat, N);
    return 0;
}