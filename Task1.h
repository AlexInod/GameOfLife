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
typedef struct Node {
    char **mat;            
    int n, m;                 
    struct Node *left;    
    struct Node *right;  
} Node;
Node* create_node(char **mat, int n, int m);
void free_node(Node *node);
void free_tree(Node *root);
void regulaB(char **src, char **dest,int n, int m);
Node* build_tree(char **mat, int n, int m, int depth);
void pre_order_traversal(Node *root, char *output_file);
char** copy_matrice(char **src, int n, int m);
#endif 