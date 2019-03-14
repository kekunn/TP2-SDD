#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

pile_t* init_pile(int taille)
{
    pile_t* p = malloc(sizeof(pile_t));
    if(p)
    {
        p->taille_max = taille;
        p->rang_sommet = -1;
        p->valeurs = malloc(sizeof(element_pile) * taille);
        if (!(p->valeurs))
        {
            free(p);
        }
    }
    return p; 
}

int estVide(pile_t *p)
{
    return p->rang_sommet == -1;
}

int estPlein (pile_t *p)
{
    return p->rang_sommet == p->taille_max;
}

int empiler(pile_t *p, element_pile valeur)
{
    int reussi = !estPlein(p);

    if(reussi)
    {
        p->rang_sommet = p->rang_sommet + 1;
        (p->valeurs)[p->rang_sommet] = valeur;
    }

    return reussi;
}

void depiler(pile_t *p, element_pile *res, int *reussi)
{
    *reussi = !estVide(p);
    if(reussi)
    {
        *res = (p->valeurs)[p->rang_sommet];
        p->rang_sommet = p->rang_sommet - 1;
    }   
}

void sommet(pile_t *p, element_pile *res, int *reussi)
{
    *reussi = !estVide(p);
    if(reussi)
    {
        *res = (p->valeurs)[p->rang_sommet];
    }   
}

void libererPile(pile_t **p)
{
    free((*p)->valeurs);
    free(*p);
}

void afficherPile(pile_t * p)
{
    int i;
    for (i = p->rang_sommet; i > 0; i--)
    {
        printf(FORMAT, (p->valeurs)[i]);
    }
}