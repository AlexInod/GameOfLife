#ifndef TASK1_H
#define TASK1_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int l; 
    int c; 
} Coordonata;
typedef struct {
    Coordonata *celule;  
    int count;         
    int capacitate;      
} Generare;
int compara_coordonate(const void *a, const void *b);
Generare initiere();
void Adauga(Generare *gen, int l, int c) ;
Generare generatia_urm(char **current, char **next, int n, int m) ;
char **aloca_matrice(int n, int m);//11
void elibereaza_memorie(char **mat, int n);
char **citire_fisier(char *fisier, int *n, int *m, int *t, int *k);
int calc_vecini(char **mat, int n, int m, int x, int y);
void reguli(char **mat, int n, int m);
void scrierez(char **mat, int n, char *output_file);
void scriererez2(Generare *generations, int k, char *output_file);
#endif 