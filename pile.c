#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/* -------------------------------------------------------------------- */
/* initPile                   Initialise une pile                       */
/*                                                                      */
/* Entree: taille: le nombre maximum d'élément pouvant être contenu     */ 
/*                  dans la pile                                        */
/*                                                                      */
/* Sortie: p, adresse de la pile initialisé si aucun problème           */
/*            d'allocation survenu, vaut null sinon                     */
/*                                                                      */
/* On alloue la pile, si l'allocation c'est bien passé                  */
/* on donne les valeurs d'une pile vide aux éléments de la              */
/* pile puis on alloue le tableau contenant les valeurs                 */
/*                                                                      */
/* Lexique: p, adresse de la pile en cours de création                  */
/*                                                                      */
/* -------------------------------------------------------------------- */
pile_t* initPile(int taille)
{  
    pile_t* p = NULL;

    if(taille > 0)//La pile doit au moins pouvoir contenir un element
    {
        p = malloc(sizeof(pile_t));

        if(p)
        {
            p->taille_max = taille;
            p->rang_sommet = -1;
            p->valeurs = malloc(sizeof(element_pile) * taille);
            if (!(p->valeurs) )
            {
                free(p);
            }
        }
    }
    return p; 
}


/* -------------------------------------------------------------------- */
/* pileVide             Verifie si la pile est vide                     */
/*                                                                      */
/* Entree: p, l'adresse de la pile                                      */
/*                                                                      */
/* Sortie: un int permettant de savoir si la pile est vide              */
/*                                                                      */
/*                                                                      */
/* Retourne un entier non nul si le rang sommet de la pile est egal à 0 */
/* et 0 sinon                                                           */
/* -------------------------------------------------------------------- */
int pileVide(pile_t *p)
{
    return p->rang_sommet == -1;
}

/* -------------------------------------------------------------------- */
/* pilePlein             Verifie si la pile est pleine                  */
/*                                                                      */
/* Entree: p, adresse de la pile                                        */
/*                                                                      */
/* Sortie: un int permettant de savoir si la pile est pleine            */
/*                                                                      */
/*                                                                      */
/* Retourne un entier non nul si le rang sommet de la pile est egal à   */
/* la taille maximal de la pile, et 0 sinon                             */
/*                                                                      */
/* -------------------------------------------------------------------- */
int pilePlein (pile_t *p)
{
    return p->rang_sommet == p->taille_max - 1;//la pile pile indexé de 0 à taille_max -1 
}


/* -------------------------------------------------------------------- */
/* empiler                   Empile une valeur                          */
/*                                                                      */
/* Entrees: p, adresse de la pile                                       */
/*          valeur, la valeur à empiler                                 */
/*                                                                      */
/* Sortie: reussi, un entier non nul si l'element a ete empile, et 0    */
/*                 sinon                                                */
/*                                                                      */
/* Si la pile n'est pas pleine on augmente le rang sommet et on ajoute  */
/* la valeur en parametre                                               */
/*                                                                      */
/* Lexique: reussi, variable de retour                                  */
/*                                                                      */
/* -------------------------------------------------------------------- */
int empiler(pile_t *p, element_pile valeur)
{
    int reussi = !pilePlein(p);

    if(reussi)
    {
        p->rang_sommet = p->rang_sommet + 1;
        (p->valeurs)[p->rang_sommet] = valeur;
    }

    return reussi;
}


/* -------------------------------------------------------------------- */
/* depiler                   Depile un element                          */
/*                                                                      */
/* Entree: p, adresse de la pile                                        */
/*         res, adresse de la varaible permettant de stocker le         */
/*              resultat                                                */
/*         reussi, adresse de la variable indiquant si un element a     */
/*                 ete depile                                           */
/*                                                                      */
/* Si la pile n'est pas vide, on attribue a res la valeur du premier    */
/* element de la pile puis on decremente le rang sommet de la pile      */
/*                                                                      */
/* -------------------------------------------------------------------- */
void depiler(pile_t *p, element_pile *res, int *reussi)
{
    *reussi = !pileVide(p);

    if(*reussi)
    {
        *res = (p->valeurs)[p->rang_sommet];
        p->rang_sommet = p->rang_sommet - 1;
    }
}


/* -------------------------------------------------------------------- */
/* sommet         Renvoie la valeur du sommet de la pile                */
/*                                                                      */
/* Entree: p, adresse de la pile                                        */
/*         res, adresse de la varaible permettant de stocker le         */
/*              resultat                                                */
/*         reussi, adresse de la variable indiquant si un element a     */
/*                 ete depile                                           */
/*                                                                      */
/* Si la pile n'est pas vide, on attribue a res la valeur du premier    */
/* element de la pile                                                   */
/*                                                                      */
/* -------------------------------------------------------------------- */
void sommet(pile_t *p, element_pile *res, int *reussi)
{
    *reussi = !pileVide(p);
    if(reussi)
    {
        *res = (p->valeurs)[p->rang_sommet];
    }   
}


/* -------------------------------------------------------------------- */
/* libererPile                  Libere la pile                          */
/*                                                                      */
/* Entree: p: adresse de l'adresse de la pile                           */
/*                                                                      */
/* On libere le tableau contenant les valeurs de la pile puis la        */
/* structure de la pile                                                 */
/*                                                                      */
/* -------------------------------------------------------------------- */
void libererPile(pile_t *p)
{
    free(p->valeurs);
    free(p);
}


/* -------------------------------------------------------------------- */
/* afficherPile         Affiche le contenu de la pile                   */
/*                                                                      */
/* Entree: p, adresse de la pile                                        */
/*                                                                      */
/* On affiche tout les element de la pile en commencant par le sommet   */
/*                                                                      */
/* Lexique: i, vairable de position dans la pile                        */
/*                                                                      */
/* -------------------------------------------------------------------- */
void afficherPile(pile_t * p)
{
    int i;
    printf("[");
    for (i = p->rang_sommet; i >= 0; i--)
    {
        printf(FORMAT, (p->valeurs)[i]);

        if (i != 0)
        {
            printf(",");
        }
    }
    printf("]\n");
}