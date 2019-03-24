#include <stdio.h>
#include "truc.h"
#include "pile.h"


/* -------------------------------------------------------------------- */
/* TRUC_rec         Affiche toutes les permutations de la liste         */
/*                                                                      */
/* Entree: i, indice du premier element a permuter                      */
/*         n, taille de la liste                                        */
/*         T, adresse de la liste                                       */
/*                                                                      */
/* Si i est egal a taille de la liste alors on affiche la liste, sinon  */
/* pour j allant de i a n on inverse T[i] et T[j] puis on rappele la    */
/* fonction TRUC en incrementant i, apres cet appele on remet la liste  */
/* dans sont etat initial                                               */
/*                                                                      */
/* Lexique: j, indice du deuxieme element a permuter                    */
/*                                                                      */
/* -------------------------------------------------------------------- */
void TRUC_rec(int i, int n, int* T)
{
    int j;
    
    if(i == n)
    {
        Affichage(n, T);
    }
    else
    {
        for (j = i; j <= n; j++)
        {
            Inverser(i - 1, j - 1, T);
            TRUC_rec(i + 1, n, T);
            Inverser(i - 1, j - 1, T);
        }
    }
}


/* -------------------------------------------------------------------- */
/* Affichage        Affiche les elements d'une liste                    */
/*                                                                      */
/* Entree: n, taille de la liste                                        */
/*         T, adresse de la liste                                       */
/*                                                                      */
/* On affiche les elements de la liste                                  */
/*                                                                      */
/* Lexique: i, indice dans la liste                                     */
/*                                                                      */
/* -------------------------------------------------------------------- */
void Affichage(int n, int * T)
{
    int i;
    printf("[ ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", T[i]);
    }
    printf("]\n");
}


/* -------------------------------------------------------------------- */
/* Inverser         Inverse deux elements d'une liste                   */
/*                                                                      */
/* Entree: i, indice du premier element a inverser                      */
/*         j, indice du deuxieme element a inverser                     */
/*         T, adresse de la liste                                       */
/*                                                                      */
/*                                                                      */
/* On inverse les deux elements                                         */
/*                                                                      */
/* Lexique: temp, variable stockant la valeur de T[i]                   */
/*                                                                      */
/* -------------------------------------------------------------------- */
void Inverser(int i, int j, int* T)
{
    int temp = T[i];
    T[i] = T [j];
    T[j] = temp;
}


/* -------------------------------------------------------------------- */
/* TRUC_ite         Affiche toutes les permutations de la liste         */
/*                                                                      */
/* Entree: i, indice du premier element a permuter                      */
/*         n, taille de la liste                                        */
/*         T, adresse de la liste                                       */
/*                                                                      */
/* Tant qu'on est pas arrive a la fin                                   */                            
/*                                                                      */
/* Lexique: p, pile de stockage de il                                   */
/*          p2, pile de sotckage de j                                   */
/*          il, indice du preier element a permuter                     */
/*          j, indice du deuxieme element a permuter                    */
/*          fin, variable booleene indiquant si la boucle principale    */
/*               est fini                                               */
/*          ok, variable indiquant si l'element a bien ete depile       */
/*              (inutile dans notre cas mais necessaire pour appeler la */
/*               fonction)                                              */ 
/*                                                                      */
/* -------------------------------------------------------------------- */
void TRUC_ite (int i, int n, int* T)
{
    pile_t*          p = initPile(n - i); //pile pour stocker il
    pile_t*          p2 = initPile(n - i); //pile pour stocker j
    element_pile     il = i - 1;
    element_pile     j = 0;
    int              fin = 0;
    int              ok;

    while(!fin)
    {
        if( il != n-1 && j < n)
        {
            while (j < n)
            {
                Inverser(il, j, T);
                empiler(p, j);
                empiler(p2, il);
                il++;
                j = il;
            }
        }

        if(il == n-1)
        {
            Affichage(n, T);
        }

        if(pileVide(p))
        {
            fin = 1;
        }
        else
        {
            depiler(p, &j, &ok);
            depiler(p2, &il, &ok);
            Inverser(il, j, T);
            j++;
        }
    }
    libererPile(&p);
    libererPile(&p2);
}