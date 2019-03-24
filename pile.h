#ifndef pile_H

#define pile_H
#define FORMAT "%d\n"

typedef int element_pile;

typedef struct pile 
{
    int taille_max; //taille maximale de la pile
    int rang_sommet; //rang du dernier element empile
    element_pile* valeurs;
}
pile_t;

pile_t*  initPile       (int taille);
int      pileVide       (pile_t *p);
int      pilePlein      (pile_t *p);
int      empiler        (pile_t *p, element_pile valeur);
void     depiler        (pile_t *p, element_pile *res, int *reussi);
void     sommet         (pile_t *p, element_pile *res, int *reussi);
void     libererPile    (pile_t **p);
void     afficherPile   (pile_t * p);

#endif