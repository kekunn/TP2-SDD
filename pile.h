#ifndef PILE_H

#define PILE_H
#define FORMAT "%d\n"

typedef int element_pile;

typedef struct pile 
{
    int taille_max;
    int rang_sommet;
    element_pile* valeurs;
}
pile_t;

pile_t*  init_pile      (int taille);
int      estVide        (pile_t *p);
int      estPlein       (pile_t *p);
int      empiler        (pile_t *p, element_pile valeur);
void     depiler        (pile_t *p, int *res, int *reussi);
void     sommet         (pile_t *p, int *res, int *reussi);
void     libererPile    (pile_t **p);
void     afficherPile   (pile_t * p);

#endif