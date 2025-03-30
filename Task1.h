#ifndef TASK1_H
#define TASK1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **aloca_matrice(int n, int m);//1
void elibereaza_memorie(char **mat, int n);
char **citire_fisier(char *fisier, int *n, int *m, int *t, int *k);
int calc_vecini(char **mat, int n, int m, int x, int y);
void reguli(char **mat, int n, int m);
void scrierez(char **mat, int n, char *dir, int index);
#endif 