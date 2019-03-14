#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>
#define format "%d\n"
typedef int T; 

struct file
{
    int tailleMax;
    int compteur;
    int rangPremier;
    int rangDernier;
    T * tab;
};
typedef struct file file_t;

file_t* initialisation(int tailleMaxUser);
int fileVide(file_t*);
int filePlein(file_t*);
void freedom(file_t* file);
int entree(file_t*, int);
int sortie(file_t*, T*);

#endif